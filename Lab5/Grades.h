#ifndef _GRADES_H_
#define _GRADES_H_
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Letter.h"
using namespace std;
namespace sict
{
class Grades
{
    string *m_id;
    double *m_grade;
    int count;

  public:
    Grades()
    {
        m_id = nullptr;
        m_grade = nullptr;
        count = 0;
    }
    Grades(Grades &);
    Grades &operator=(Grades &);
    Grades(Grades &&);
    Grades &operator=(Grades &&);
    Grades(char *file);

    template <typename T>
    void displayGrades(std::ostream &os, T F) const
    {
        for (int i = 0; i < count; ++i)
            os << m_id[i] << " " << fixed << setprecision(2) << m_grade[i] << " " << F(m_grade[i]) << endl;
    };
    ~Grades();
};
} // namespace sict
#endif
