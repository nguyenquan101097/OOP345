
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "CString.h"

int STORED = w1::CString::MAX;

namespace w1
{
// address of a C-style null-terminated string
// stores the first MAX characters of the string
// Initial MAX to the value of STORED
//
CString::CString(const char *string)
{
	if (string == nullptr)
		m_string[0] = '\0';
	else
	{
		std::strncpy(m_string, string, MAX);
		m_string[MAX + 1] = '\0';
	}
}
void CString::display(std::ostream &os) const
{
	os << m_string;
}

std::ostream &operator<<(std::ostream &os, CString &a)
{
	a.display(os);
	return os;
}
} // namespace w1