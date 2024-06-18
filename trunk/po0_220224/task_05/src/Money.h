#pragma once
#ifndef MONEYH
#define MONEYH

#include <iostream>

// Класс для работы с деньгами (рубли и копейки)
class Money
{
public:
    Money() = default;
    explicit Money(const double a); // Конструктор из double
    Money(const Money& other) = default;
    ~Money() = default;
    Money& operator=(const Money& a) = default;
    bool operator==(const Money& a) const;
    auto operator<=>(const Money& a) const = default;
    Money operator+(const Money& a) const;
    Money operator-(const Money& a) const; // Оператор вычитания
    Money operator/(const int a) const; // Оператор деления

    friend std::ostream& operator<<(std::ostream& out, const Money& a);
    friend std::istream& operator>>(std::istream& in, Money& a);

    inline int GetK() const { return kopeck; }
    inline long GetR() const { return rubles; }
    inline void SetK(const int k) { kopeck = k; }
    inline void SetR(const long r) { rubles = r; }

private:
    long rubles = 0;
    int kopeck = 0;
    void normalize()
    {
        if (kopeck >= 100)
        {
            rubles += kopeck / 100;
            kopeck %= 100;
        }
        else if (kopeck < 0)
        {
            rubles -= (-kopeck + 99) / 100;
            kopeck = 100 + kopeck % 100;
        }
    }
    Money operator-(const Money& a, const Money& b)
{
    Money result;
    result.rubles = a.rubles - b.rubles;
    result.kopeck = a.kopeck - b.kopeck;
    if (result.kopeck < 0)
    {
        result.rubles -= 1;
        result.kopeck += 100;
    }
    return result;
}

Money operator/(const Money& a, int b)
{
    Money result;
    double totalKopeck = a.rubles * 100 + a.kopeck;
    double dividedKopeck = totalKopeck / b;
    result.rubles = static_cast<long>(dividedKopeck / 100);
    result.kopeck = static_cast<int>(dividedKopeck) % 100;
    return result;
}
};

#endif
