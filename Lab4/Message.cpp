#include "Message.h"

namespace w5
{
Message::Message()
{
    name.clear();
    rep.clear();
    tweet.clear();
}
Message::Message(std::ifstream &in, char c)
{

    std::string line;
    getline(in, line, c);
    //delete \r
    if (line.find('\r') != std::string::npos)
        line.erase(line.find('\r'));
    size_t i = 0;
    //get name
    while (i < line.size() & line[i] != ' ')
    {
        name += line[i];
        i++;
    }
    //skip spaceee
    i++;
    //reply
    if (line[i] == '@')
    {
        i++;
        while (i < line.size() && line[i] != ' ')
        {
            rep += line[i];
            i++;
        }
        i++;
    }
    //skip sp
    //tweet
    while (i < line.size())
    {
        tweet += line[i];
        i++;
    }
}
bool Message::empty() const
{
    return tweet.empty();
}

void Message::display(std::ostream &os) const
{
    os << "Message" << std::endl;
    os << " User  : " << name << std::endl;
    if (!rep.empty())
        os << " Reply : " << rep << std::endl;
    os << " Tweet : " << tweet << std::endl;
    os << std::endl;
}
} // namespace w5