#ifndef _LETTER_H_
#define _LETTER_H_
namespace sict
{
enum class Letter
{
    A,
    A_p,
    B,
    B_p,
    C,
    C_p,
    D,
    D_p,
    F
};
template <typename T>
const char *convertString(const T &mark)
{
    switch (mark)
    {
    case T::A:
        return "A";
    case T::A_p:
        return "A+";
    case T::B:
        return "B";
    case T::B_p:
        return "B+";
    case T::C:
        return "C";
    case T::C_p:
        return "C+";
    case T::D:
        return "D";
    case T::D_p:
        return "D+";
    case T::F:
        return "F";
    }
}
} // namespace sict
#endif
