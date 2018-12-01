#include <iostream>
#include "Text.h"

namespace w2
{
Text::Text()
{
    m_count = 0;
    m_file = nullptr;
}

Text::Text(char *file)
{
    Text();
    std::fstream gutenberg_shakespeare(file, std::ios::in);
    if (!gutenberg_shakespeare.is_open())
    {
        std::cerr << "File is not open " << file << std::endl;
    }
    else
    {
        std::string x;
        while (getline(gutenberg_shakespeare, x))
        {
            m_count++;
        }
        m_file = new std::string[m_count];
        gutenberg_shakespeare.clear();

        for (size_t i = 0; i < m_count; i++)
        {
            getline(gutenberg_shakespeare, m_file[i]);
        }
        gutenberg_shakespeare.close();
    }
}

//copy constructor
Text::Text(const Text &x)
{
    m_count = 0;
    m_file = nullptr;
    *this = x;
}

//copy assignment opera
Text &Text::operator=(const Text &x)
{
    m_count = x.m_count;
    if (this != &x)
    {
        delete[] m_file; //allocate mem
        m_file = new std::string[m_count];

        for (size_t i = 0; i < m_count; ++i)
        {
            m_file[i] = x.m_file[i];
        }
    }
    return *this;
}

//move constructor
Text::Text(Text &&x)
{
    m_count = 0;
    m_file = nullptr;
    *this = std::move(x);
}

//move assignment operator
Text &Text::operator=(Text &&x)
{
    if (this != &x)
    {
        m_file = x.m_file;
        m_count = x.m_count;
        x.m_count = 0;
        x.m_file = nullptr;
    }
    return *this;
}

//destructor
Text::~Text()
{
    delete[] m_file;
    m_file = nullptr;
}

//size_t
size_t Text::size() const
{
    return m_count;
}
}; // namespace w2
