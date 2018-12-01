
#pragma once
#include "Product.h"

namespace w6
{

class TaxableProduct : public Product
{
  char taxStatus;
  double taxRate[3];

public:
  enum Tax
  {
    NONE,
    HST,
    PST
  };
  TaxableProduct();
  TaxableProduct(int item, double price, char tax);
  virtual double getPrice() const;
  virtual void display(std::ostream &os) const;
};
} // namespace w6