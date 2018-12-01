// Workshop 6 - STL Containers
// w6.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"
int main(int argc, char **argv)
{

    std::ofstream ofs("Lab6Output.txt");

    std::cout << "\nCommand Line : ";
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 2)
    {
        std::cerr << "\n***Incorrect number of arguments***\n";
        return 1;
    }
    std::ifstream productList(argv[1]);
    if (!productList)
    {
        std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
        return 2;
    }
    ofs << std::fixed << std::setprecision(2);

    //Add your code here
    std::vector<w6::iProduct *> VecPro;

    char check;
    while (productList >> check)
    {
        productList.putback(check);
        VecPro.push_back(w6::readProduct(productList));
    }


    double total;
    ofs << "Product No     Price Taxable" << std::endl;
    for (int i = 0; i < VecPro.size(); ++i)
    {
        ofs << *VecPro[i];
        ofs << std::endl;
        total += VecPro[i]->getPrice();
    }

    ofs << "     Total" << std::setw(10) << total << std::endl;

    std::cout << "Results are in Lab6Output.txt\nPress any key to continue ... ";
    std::cin.get();

    ofs.close();
}
