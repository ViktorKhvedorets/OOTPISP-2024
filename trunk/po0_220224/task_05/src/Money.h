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

    friend std::ostream& operator<<(std::ostream& out, const Money& a);
    friend std::istream& operator>>(std::istream& in, Money& a);

    inline int GetK() const { return kopeck; }
    inline long GetR() const { return rubles; }
    inline void SetK(const int k) { kopeck = k; }
    inline void SetR(const long r) { rubles = r; }

private:
	long rubles = 0;
	int kopeck = 0;
};

#endif