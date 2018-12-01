#include "Item.h"
#include "Utilities.h"
#include <string>
unsigned int Item::field_width;
Item::Item(std::string &record) //takes a record from the items file and parses the data
{
    Utilities a;
    size_t pos = 0;
    bool ok = true;
    this->name = a.extractToken(record, pos, ok);
    if (this->name.empty())
    {
        throw std::string("No name");
    }
    this->serialNumber = std::stoi(a.extractToken(record, pos, ok));
    this->Quantity = std::stoi(a.extractToken(record, pos, ok));
    this->description = a.extractToken(record, pos, ok);
    if (this->description.empty())
    {
        throw std::string("No description");
    }
    if (getName().length() > field_width)
    {
        field_width = a.getFieldWidth();
    }
}
const std::string &Item::getName() const //Returns a reference to the items name
{
    return this->name;
}
const unsigned int Item::getSerialNumber() //Returns a reference to the serial number
{
    return this->serialNumber++;
}
const unsigned int Item::getQuantity() //Returns a reference to the remaining quantity
{
    return this->Quantity;
}
void Item::updateQuantity() //Removes 1 from the quantity
{
    Quantity--;
}
void Item::display(std::ostream &os, bool full) const
{
    if (full)
    {
        os << std::setw(field_width) << std::left << getName()
           << " [" << serialNumber << "]"
           << " "
           << "Quantity: " << Quantity
           << " Description: " << description << std::endl;
    }
    else
    {
        os << std::setw(field_width) << std::left << name << "[" << std::setw(field_width) << serialNumber << "]" << std::setfill(' ') << std::endl;
    }
    // os << std::left << std::setw(12) << getName();
    // os << std::right<<std::setw(11)<<"[" << std::setw(CODE_WIDTH)<<std::right<< serialNumber << "]";
    // if (full)
    // {
    //     os << std::left << std::setw(field_width) << " Quantity " << this->Quantity;

    //     os << std::setw(field_width + CODE_WIDTH + 3) << " Description:" << this->description;
    // }
}
