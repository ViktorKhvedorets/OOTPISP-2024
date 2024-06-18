#include "Money.h"
#include <memory>

Coins::Coins(const double a)

	:rubles(static_cast<long>(a)),
	kopeck(static_cast<int>((a - static_cast<int>(a)) * 100))
{
}

bool Coins::operator==(const Coins& a) const
{
	if (kopeck == a.kopeck && rubles == a.rubles)
		return true;
	else
		return false;
}


Coins operator+(const Coins& a, const Coins& b) {
    long totalRubles = a.rubles + b.rubles;
    int totalKopecks = a.kopeck + b.kopeck;

    if (totalKopecks >= 100) {
        totalRubles += totalKopecks / 100;
        totalKopecks %= 100;
    }

    return Coins(totalRubles, totalKopecks);
}