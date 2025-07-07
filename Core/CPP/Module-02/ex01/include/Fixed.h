#pragma once

#include <iostream>

class Fixed {
	int fixedPointValue;
	static const int fractionalBits;
public:
	Fixed();
	explicit Fixed(int raw);
	explicit Fixed(float raw);
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed &operator=(const Fixed &src);
	float toFloat() const;
	int toInt() const;
	int getRawBits() const;
	void setRawBits(int raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);