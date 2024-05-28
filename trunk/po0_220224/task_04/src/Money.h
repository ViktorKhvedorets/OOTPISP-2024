#pragma once

#include <iostream>

class Money
{
public:
	Money() = default;
	explicit Money(const double money);
	Money(const Money& other) = default;
	~Money() = default;

	Money& operator=(const Money& a) = default;
	bool operator==(const Money& a) const;

	friend std::ostream& operator<<(std::ostream& out, const Money& a)
	{
		out << a.GetRubles() << " Рубли, " << a.GetPenny() << " копейки" << std::endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Money& a)
	{
		std::cout << "Введите сумму рублей" << std::endl;
		in >> a.rub;
		std::cout << "Введите сумму копеек" << std::endl;
		in >> a.pennys;
		return in;
	}

	inline int32_t GetPenny() const { return pennys; };
	inline int64_t GetRubles() const { return rub; };

	inline void SetPenny(const int32_t p) { pennys = p; };
	inline void SetRubles(const int64_t r) { rub = r; };

private:
	int64_t rub = 0;
	int32_t pennys = 0;
};