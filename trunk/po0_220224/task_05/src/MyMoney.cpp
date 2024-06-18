#include "Money.h"
#include <iostream>
#include <iomanip>

std::ostream& operator<<(std::ostream& out, const Money& a)
{
    out << a.GetR() << ',' << std::setw(2) << std::setfill('0') << a.GetK();
    return out;
}

std::istream& operator>>(std::istream& in, Money& a)
{
    std::cout << "Enter amount of rubles" << std::endl;
    in >> a.rubles;
    std::cout << "Enter amount of kopeck" << std::endl;
    in >> a.kopeck;
    a.normalize();
    return in;
}
