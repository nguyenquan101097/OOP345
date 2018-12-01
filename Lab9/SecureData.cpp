// Workshop 10 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <cstring>
#include "SecureData.h"

namespace w10
{

void converter(char *t, char key, int n, const Cryptor &c)
{
    for (int i = 0; i < n; i++)
        t[i] = c(t[i], key);
}

SecureData::SecureData(const char *file, char key, std::ofstream *pOfs)
{

    ofs = pOfs;

    // open text file
    std::fstream input(file, std::ios::in);
    if (!input)
        throw std::string("\n***Failed to open file ") +
            std::string(file) + std::string(" ***\n");

    // copy from file into memory
    nbytes = 0;
    input >> std::noskipws;
    while (input.good())
    {
        char a;
        input >> a;
        nbytes++;
    }
    nbytes--;
    input.clear();
    input.seekg(0, std::ios::beg);
    text = new char[nbytes + 1];

    int i = 0;
    while (input.good())
        input >> text[i++];
    text[--i] = '\0';
    *ofs << "\n"
         << nbytes << " bytes copied from text "
         << file << " into memory (null byte added)\n";
    encoded = false;

    // encode using key
    code(key);
    *ofs << "Data encrypted in memory\n";
}

SecureData::~SecureData()
{
    delete[] text;
}

void SecureData::display(std::ostream &os) const
{
    if (text && !encoded)
        os << text << std::endl;
    else if (encoded)
        throw std::string("\n***Data is encoded***\n");
    else
        throw std::string("\n***No data stored***\n");
}

void SecureData::code(char key)
{
    // converter(text,key,nbytes,Cryptor());
    // encoded = !encoded;

    std::thread x1(converter, &text[0], key, nbytes / 2, Cryptor());
    std::thread x2(converter, &text[nbytes / 2], key, nbytes / 2, Cryptor());

    x1.join();
    x2.join();

    encoded = !encoded;
}

void SecureData::backup(const char *file)
{
    if (!text)
        throw std::string("\n***No data stored***\n");
    else if (!encoded)
        throw std::string("\n***Data is not encoded***\n");
    else
    {
        // open binary file
        std::fstream os(file, std::ios::out);
        if (!os)
            throw std::string("\n***Failed to open file ") +
                std::string(file) + std::string(" ***\n");

        // write binary file here
        for (int i = 0; i < std::strlen(text); i++)
            os << text[i];
    }
}

void SecureData::restore(const char *file, char key)
{
    delete[] text;
    nbytes = 0;
    // open binary file
    std::fstream fs(file, std::ios::in | std::ios::binary);

    // get length of file
    if (fs)
    {
        nbytes = 0;
        fs >> std::noskipws;
        while (!fs.eof())
        {
            char temp;
            fs >> temp;
            nbytes++;
        }

        // allocate memory here
        nbytes--;
        fs.clear();
        fs.seekg(0, std::ios::beg);
        text = new char[nbytes + 1];

        // read binary file here
        fs.read(text, nbytes);
        text[nbytes] = '\0';

        *ofs
            << "\n"
            << nbytes + 1 << " bytes copied from binary file "
            << file << " into memory (null byte included)\n";

        // decode using key
        code(key);
        *ofs << "Data decrypted in memory\n\n";
    }
}

std::ostream &operator<<(std::ostream &os, const SecureData &sd)
{
    sd.display(os);
    return os;
}

} // namespace w10
