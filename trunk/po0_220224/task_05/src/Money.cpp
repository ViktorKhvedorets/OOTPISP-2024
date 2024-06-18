#include "Money.h"
#include <memory>
#include <cmath>

// Конструктор, инициализирующий объект Money из вещественного числа
Money::Money(double amount)
    : rubles(static_cast<long>(amount)),
      kopeck(static_cast<int>(std::round((amount - static_cast<long>(amount)) * 100)))
{
    // Корректировка, если количество копеек превышает 99
    if (kopeck >= 100)
    {
        rubles += kopeck / 100;
        kopeck %= 100;
    }
}

// Оператор сложения двух объектов Money
Money Money::operator+(const Money& other) const
{
    long totalRubles = rubles + other.rubles;
    int totalKopeck = kopeck + other.kopeck;

    // Перенос копеек при необходимости
    if (totalKopeck >= 100)
    {
        totalRubles += totalKopeck / 100;
        totalKopeck %= 100;
    }

    return Money(static_cast<double>(totalRubles) + static_cast<double>(totalKopeck) / 100);
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

    // Корректировка копеек при необходимости
    if (money.kopeck >= 100)
    {
        money.rubles += money.kopeck / 100;
        money.kopeck %= 100;
    }

    return in;
}
