#include "CustomerOrder.h"
#include "Item.h"
#include "Utilities.h"
#include <vector>
#include <iomanip>
CustomerOrder::CustomerOrder()
{
    Name = "";
    Product = "";
    ItemCount = 0;
    field_width = 0;
}
//Use utilities object to extract token
CustomerOrder::CustomerOrder(std::string &str)
{
    Utilities temp;
    bool ok = true;
    size_t pos = 0, beg = 0;

    Name = temp.extractToken(str, pos, ok);
    Product = temp.extractToken(str, pos, ok);

    if (temp.getFieldWidth() > field_width)
        field_width = temp.getFieldWidth();

    beg = pos;
    ItemCount = 0;

    // Count how many products exists
    while (ok)
    {
        temp.extractToken(str, pos, ok);
        ItemCount++;
    }

    // Allocate memory
    ItemList = new ItemInfo *[ItemCount];
    ok = true;

    // Take the addresses of the extracted tokens
    temp.setFieldWidth(0);
    for (int i = 0; i < ItemCount; i++)
        ItemList[i] = new ItemInfo(temp.extractToken(str, beg, ok));
}
CustomerOrder::~CustomerOrder()
{
    delete[] ItemList;
}
//Object move functionality
CustomerOrder::CustomerOrder(CustomerOrder &&obj)
{
    *this = std::move(obj);
}
CustomerOrder &CustomerOrder::operator=(CustomerOrder &&obj)
{
    //check address
    if (this != &obj)
    {
        this->Name = obj.Name;
        this->Product = obj.Product;
        this->ItemCount = obj.ItemCount;
        this->ItemList = obj.ItemList;
        //empty state

        obj.ItemList = nullptr;
        obj.ItemCount = 0;
    }
    return *this;
}

bool CustomerOrder::getOrderFillState() //Returns true if order completely filled, false otherwise
{
    for (int i = 0; i < ItemCount; ++i)
    {
        if (!ItemList[i]->FillState)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
bool CustomerOrder::getItemFillState(std::string str) //Returns true if the given item has been filled
{
    bool check = true;
    for (int i = 0; i < ItemCount; ++i)
    {
        if (str == ItemList[i]->ItemName)
        {
            check = ItemList[i]->FillState;
        }
        return check;
    }
}
void CustomerOrder::fillItem(Item &obj, std::ostream &os) //Fills the customer order item if the inventory on Item is available
{
    for (int i = 0; i < ItemCount; ++i)
    {
        if (obj.getName() == ItemList[i]->ItemName)
        {
            if (obj.getQuantity() > 0)
            {
                obj.updateQuantity();
                ItemList[i]->SerialNumber = obj.getSerialNumber();
                ItemList[i]->FillState = true;
                os << "Filled " << Name << ", " << Product << "[" << ItemList[i]->ItemName << "]" << std::endl;
            }
            else
            {
                os << "Unable to fill " << Name << ", " << Product << std::endl;
            }
        }
    }
}
void CustomerOrder::Display(std::ostream &os)
{
    os << Name << std::endl;
    os << Product << std::endl;
    for (size_t i = 0; i < ItemCount; i++)
        os << "[" << ItemList[i]->SerialNumber << "] " << std::setw(field_width) << std::setfill(' ') << ItemList[i]->ItemName << " - " << (ItemList[i]->FillState ? "FILLED\n" : "MISSING\n");
}
