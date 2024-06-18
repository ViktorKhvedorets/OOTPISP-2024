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

// Приватный метод для нормализации значения копеек и рублей
void Money::normalize()
{
    if (kopeck >= 100)
    {
        rubles += kopeck / 100;
        kopeck %= 100;
    }
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
std::ostream& operator<<(std::ostream& out, const Money& money)
{
    out << money.GetR() << ',' << std::setw(2) << std::setfill('0') << money.GetK();
    return out;
}

// Дружественный оператор ввода объекта Money
std::istream& operator>>(std::istream& in, Money& money)
{
    std::cout << "Введите количество рублей: ";
    in >> money.rubles;
    std::cout << "Введите количество копеек: ";
    in >> money.kopeck;

    // Нормализуем введенные значения
    money.normalize();

    return in;
}
