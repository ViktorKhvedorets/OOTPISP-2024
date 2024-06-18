#include "Money.h"
#include <cmath>
#include <memory>
#include <iomanip>

Money::Money(double rubles, double kopecks)
    : rubles(static_cast<long>(rubles)),
      kopeck(static_cast<int>(std::round(kopecks)))
{
    normalize();
}

// Оператор сложения двух объектов Money
Money operator+(const Money& a, const Money& b)
{
    Money sum;
    sum.rubles = a.rubles + b.rubles;
    sum.kopeck = a.kopeck + b.kopeck;
    sum.normalize();
    return sum;
}

Money operator-(const Money& a, const Money& b)
{
    auto diff = std::make_unique<Money>();
    long RDiff = a.GetR() - b.GetR();
    int KDiff = a.GetK() - b.GetK();
    if (KDiff < 0) {
        RDiff--;
        KDiff += 100;
    }
    diff->SetK(KDiff);
    diff->SetR(RDiff);
    return *diff.get();
}

Money operator/(const Money& a, int b)
{
    double totalKopecks = static_cast<double>(a.GetR()) * 100.0 + a.GetK();
    totalKopecks /= b;
    double newRubles = totalKopecks / 100.0;
    double newKopecks = std::fmod(totalKopecks, 100.0); // Change newKopecks to double
    return Money(newRubles, newKopecks);
}

// Оператор сравнения на равенство двух объектов Money
bool Money::operator==(const Money& other) const = default;

// Дружественный оператор вывода объекта Money
std::ostream& operator<<(std::ostream& out, const Money& a)
{
    out << a.GetR() << ',' << std::setw(2) << std::setfill('0') << a.GetK();
    return out;
}

std::istream& operator>>(std::istream& in, Money& a)
{
    std::cout << "Enter amount of rubles: ";
    in >> a.rubles;
    std::cout << "Enter amount of kopeck: ";
    in >> a.kopeck;
    a.normalize();
    return in;
}