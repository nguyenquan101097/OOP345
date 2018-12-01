#ifndef _TEXT_H_
#define _TEXT_H_
#include <fstream>
#include <iostream>
#include <string>

namespace w2
{
class Text
{
  private:
    std::string *m_file;
    std::size_t m_count;

  public:
    Text();
    Text(char *);
    Text(const Text &);            //a copy constructor
    Text &operator=(const Text &); //a copy assignment operator
    Text(Text &&);                 //a move constructor
    Text &operator=(Text &&);      //a move assignment operator
    ~Text();                       //a destructor
    //a member function named size_t size() const that returns the number of records of text data
    size_t size() const;

    // the num of recorded ext;
};
} // namespace w2
#endif
