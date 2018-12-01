#include "Notifications.h"
#include "Message.h"

namespace w5
{
Notifications::Notifications()
{
    m_message = new Message[MAX];
}

//! Copy constructor
Notifications::Notifications(const Notifications &src)
{
    m_message = nullptr;
    *this = src;
}

//Copy assignment opera
Notifications &Notifications::operator=(const Notifications &src)
{
    if (this != &src)
    {
        delete[] m_message;
        count = 0;
        m_message = new Message[count];
        for (size_t i = 0; i < count; ++i)
            m_message[i] = src.m_message[i];
    }
    return *this;

    // if (this != &src)
    // {
    //     if (src.count != 0)
    //     {
    //         m_message = new Message[size];
    //         count = src.count;
    //         for (int i = 0; i < src.count; i++)
    //         {
    //             m_message[i] = src.m_message[i];
    //         }
    //     }
    //     else
    //     {
    //         m_message = nullptr;
    //     }
    // }

    // return *this;
}
//Move constructor
Notifications::Notifications(Notifications &&src)
{
    m_message = nullptr;
    *this = std::move(src);
}

//! Move assignment opera
Notifications &&Notifications::operator=(Notifications &&src)
{
    if (this != &src)
    {
        delete[] m_message;
        count = 0;
        count = src.count;
        m_message = new Message[count];
        for (size_t i = 0; i < count; ++i)
            m_message[i] = src.m_message[i];
        src.count = 0;
        src.m_message = nullptr;
    }
    return std::move(*this);
}

//     if (this != &src)
//     {
//         m_message = src.m_message;
//     }
//     return std::move(*this);
// }
//! Destructor
Notifications::~Notifications()
{
    delete[] m_message;
}

//! Operator that adds a message to the set
void Notifications::operator+=(const Message &msg)
{
    if (count < MAX)
    {
        m_message[count] = msg;
        count++;
    }
}

//! query that displays the Message objects in the os output stream
void Notifications::display(std::ostream &os) const
{
    for (size_t i = 0; i < count; ++i)
    {
        m_message[i].display(os);
    }
}
}; // namespace w5