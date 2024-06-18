#pragma once
#ifndef COINSH
#define COINSH
#include <iostream>

class Coins
{
public:
    Coins() = default;
    explicit Coins(const double a);
    Coins(long r, int k); // Constructor to accept rubles and kopecks directly
    Coins(const Coins& other) = default;
    ~Coins() = default;
    Coins& operator=(const Coins& a) = default;
    bool operator==(const Coins& a) const;
    auto operator<=>(const Coins& a) const = default;
    Coins operator+(const Coins& a) const;

    friend std::ostream& operator << (std::ostream& out, const Coins& a)
    {
        out << a.rubles << ',' << a.kopeck << std::endl;
        return out;
    }

    friend std::istream& operator >> (std::istream& in, Coins& a)
    {
        std::cout << "Enter amounts of rubles" << std::endl;
        in >> a.rubles;
        std::cout << "Enter amounts of kopeck" << std::endl;
        in >> a.kopeck;
        return in;
    }

    inline int GetK() const { return kopeck; };
    inline long GetR() const { return rubles; };
    inline void SetK(const int k) { kopeck = k; };
    inline void SetR(const long r) { rubles = r; };

private:
    long rubles = 0;
    int kopeck = 0;
};

Coins::Coins(long r, int k) : rubles(r), kopeck(k) {}

#endif
