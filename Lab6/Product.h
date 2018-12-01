#pragma once

#include "iProduct.h"

namespace w6
{
class Product : public iProduct
{
  int m_item;
  double m_price;

public:
  Product();
  Product(int item, double price);
  ~Product();
  virtual double getPrice() const;
  virtual void display(std::ostream &os) const;
};
} // namespace w6