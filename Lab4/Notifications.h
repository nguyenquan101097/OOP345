#ifndef _NOTIFICATIONS_H_
#define _NOTIFICATIONS_H_
#include "Message.h"

namespace w5
{
const size_t MAX = 10;

class Notifications
{
private:
  size_t count = 0;
  Message *m_message = nullptr;

public:
  Notifications();                                 //empty constructor
  Notifications(const Notifications &);            //copy constructor
  Notifications &operator=(const Notifications &); //copy assignment operator
  Notifications(Notifications &&);                 //move constructor
  Notifications &&operator=(Notifications &&);     // move assignment operator
  ~Notifications();                                // destructor
  void operator+=(const Message &msg);             //adds msg to the set
  void display(std::ostream &os) const;            //inserts the Message objects to the os output stream
};
} // namespace w5

#endif