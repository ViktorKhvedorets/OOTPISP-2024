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
Money Money::operator+(const Money& other) const
{
    Money sum;
    sum.rubles = rubles + other.rubles;
    sum.kopeck = kopeck + other.kopeck;

    // Нормализуем результат
    sum.normalize();

    return sum;
}
Money Money::operator-(const Money& a) const
{
    auto diff = std::make_unique<Money>();
    long RDiff = this->GetR() - a.GetR();
    int KDiff = this->GetK() - a.GetK();
    if (KDiff < 0)
    {
        RDiff--;
        KDiff += 100;
    }
    diff->SetK(KDiff);
    diff->SetR(RDiff);
    return *diff.get();
}
Money Money::operator/(const int a) const
{
    long totalKopecks = rubles * 100 + kopeck;
    totalKopecks /= a;
    double newRubles = totalKopecks / 100;
    int newKopecks = totalKopecks % 100;
    return Money(newRubles + newKopecks / 100.0);
}

// Оператор сравнения на равенство двух объектов Money
bool Money::operator==(const Money& other) const = default;


// Дружественный оператор вывода объекта Money
std::ostream& operator<<()
{
   std::cout<< "hello world";
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

