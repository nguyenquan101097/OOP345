#ifndef _w5_MESSAGE_H_
#define _w5_MESSAGE_H_
#include <iostream>
#include <fstream>
#include <string>

namespace w5
{
class Message
{
  std::string name;
  std::string rep;
  std::string tweet;

public:
  Message();
  Message(std::ifstream &in, char c);
  bool empty() const;
  void display(std::ostream &os) const;
};
} // namespace w5
#endif
