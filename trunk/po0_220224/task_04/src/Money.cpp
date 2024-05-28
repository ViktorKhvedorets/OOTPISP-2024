#include "Money.h"

Money::Money(const double money)
	: rub(static_cast<int64_t>(money)),
	pennys(static_cast<int32_t>((money - static_cast<int32_t>(money)) * 100))
{
}

bool Money::operator==(const Money& a) const
{
	return (pennys == a.pennys && rub == a.rub);
}