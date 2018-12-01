#include "Utilities.h"
#include <iostream>
char Utilities::delimiter;
Utilities::Utilities() : field_width{1} {}
void Utilities::setFieldWidth(size_t fw)
{
    field_width = fw;
}
size_t Utilities::getFieldWidth() const
{
    return field_width;
}
const std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &check)
{
    size_t temp = next_pos;
    if ((temp - str.find(delimiter, temp + 1)) == 1)
    {
        throw "No token found";
    }

    if (str.find(delimiter, temp + 1) != std::string::npos)
        check = true;
    else
        check = false;

    if (next_pos > 0)
    {
        if (check)
        {
            next_pos = str.find(delimiter, temp + 1);
        }
        return str.substr(temp + 1, next_pos - (temp + 1));
    }
    else
    {
        next_pos = str.find(delimiter, temp);
        if (getFieldWidth() < str.substr(temp, next_pos).length())
        {
            setFieldWidth(str.substr(temp, next_pos).length());
        }
        return str.substr(temp,next_pos);
    }
    // size_t x = next_pos;

    // if (check)
    // {

    //     token = str.substr(next_pos);       //store string begin with next_pos
    //     size_t pos = token.find(delimiter); //store delimiter
    //     if (pos != std::string::npos)
    //     {
    //         token.erase(pos, token.length()); //delete the rest of string
    //     }

    //     next_pos += token.length() + 1; //read from delimiter

    //     if (next_pos > str.length())
    //     {
    //         check = false;
    //     }
    // }
    // if (field_width <= 0)
    // {
    //     setFieldWidth(str.substr(x, next_pos).length());
    // }
    // std::cout << "efef" << std::endl;
    // std::cout << field_width << std::endl;
    // return token;
}
void Utilities::setDelimiter(const char x)
{
    delimiter = x;
}
const char Utilities::getDelimiter() const
{
    return delimiter;
}
