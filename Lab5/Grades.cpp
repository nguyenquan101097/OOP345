#include "Grades.h"
using namespace std;
namespace sict
{
Grades::Grades(char *file)
{
    try
    {
        ifstream fs(file);
        if (fs.is_open())
        {
            int index = 0;
            string s;

            while (getline(fs, s))
            {
                index++;
            }
            fs.clear();
            fs.seekg(0);

            count = index;
            m_id = new string[count];
            m_grade = new double[count];

            for (int i = 0; i < count; ++i)
            {
                fs >> m_id[i];
                fs >> m_grade[i];
            }
            fs.close();
        }
        else if (fs.fail())
            throw "Fail to open file: " + string(file);
    }
    catch (const char *mg)
    {
        cerr << mg << endl;
        exit(0);
    }
}

Grades::~Grades()
{
    delete[] m_id;
    delete[] m_grade;
}
} // namespace sict
