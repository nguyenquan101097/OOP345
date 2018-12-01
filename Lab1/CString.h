#ifndef _CSTRING_H
#define _CSTRING_H

namespace w1
{
class CString
{
public:
  static const int MAX = 3;
  char m_string[10];
  CString(const char *string);
  void display(std::ostream &os) const;
};
std::ostream &operator<<(std::ostream &os, CString &string);
} // namespace w1

#endif