#include <iostream>
#include "process.h"
#include "CString.h"

void process(const char *string, std::ostream &os)
{
   static int counter = 0;
    w1::CString cs(string);
    os << counter++ << ": " << cs << std::endl;
}
// namespace w1
