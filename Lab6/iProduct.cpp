#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Product.h"
#include "TaxableProduct.h"
#include "iProduct.h"
using namespace std;
namespace w6
{
iProduct *readProduct(std::ifstream &is)
{
    int item;
    double price;
    char taxSt;
    is >> item >> price;
    if (is.get() != '\n')
    {
        is.get(taxSt);
        return new TaxableProduct(item, price, taxSt);
    }
    else
    {
        return new Product(item, price);
    }
   
}

Product::Product() : m_item{0}, m_price{0} {}
Product::Product(int item, double price) : m_item{item}, m_price{price} {}
Product::~Product() {}
double Product::getPrice() const
{
    return m_price;
}
void Product::display(std::ostream &os) const
{
    os << std::fixed;
    os << std::setprecision(2);
    os << std::setw(10) << m_item;
    os << std::setw(10) << m_price;
}
TaxableProduct::TaxableProduct() : taxStatus{' '}
{
    taxRate[NONE] = 1.00;
    taxRate[HST] = 1.13;
    taxRate[PST] = 1.08;
}
TaxableProduct::TaxableProduct(int item, double price, char tax) : Product(item, price), taxStatus(tax)
{
    taxRate[NONE] = 1.00;
    taxRate[HST] = 1.13;
    taxRate[PST] = 1.08;
}

double TaxableProduct::getPrice() const
{
    Tax tax;
    if (taxStatus == 'H')
        tax = HST;
    else if (taxStatus == 'P')
        tax = PST;
    else
        tax = NONE;
    return Product::getPrice() * taxRate[tax];
}

void TaxableProduct::display(std::ostream &os) const
{
    Product::display(os);
    os << " ";
    if (taxStatus == 'H')
        os << "HST";
    else if (taxStatus == 'P')
        os << "PST";
    else
        os << " ";
}

std::ostream &operator<<(std::ostream &os, const iProduct &x)
{
    x.display(os);
    return os;
}
} // namespace w6