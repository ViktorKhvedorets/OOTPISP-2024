#include "Money.h"
#include <cmath>
#include <memory>

// Конструктор, инициализирующий объект Money из вещественного числа
Money::Money(double amount)
    : rubles(static_cast<long>(amount)),
      kopeck(static_cast<int>(std::round((amount - std::floor(amount)) * 100)))
{
    // Если количество копеек больше или равно 100, добавляем их к рублям
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
    double totalKopecks = static_cast<double>(a.rubles) * 100.0 + static_cast<double>(a.kopeck);
    totalKopecks /= b;
    long newRubles = static_cast<long>(totalKopecks / 100.0);
    auto newKopecks = static_cast<int>(std::fmod(totalKopecks, 100.0));
    return Money(newRubles + newKopecks / 100.0);
}


// Оператор сравнения на равенство двух объектов Money
bool Money::operator==(const Money& other) const = default;


// Дружественный оператор вывода объекта Money
std::ostream& operator<<(std::ostream& out, const Money& a)

{
   std::cout<< "hello world";
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

