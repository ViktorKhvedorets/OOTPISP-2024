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


// Оператор сравнения на равенство двух объектов Money
bool Money::operator==(const Money& other) const
{
    return rubles == other.rubles && kopeck == other.kopeck;
}

// Дружественный оператор вывода объекта Money
std::ostream& operator<<(std::ostream& out, const Money& a)
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

