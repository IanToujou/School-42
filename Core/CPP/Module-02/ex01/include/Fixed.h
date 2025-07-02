#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	int fixedPointValue;
	static const int fractionalBits;
public:
	Fixed();
	Fixed(int const raw);
	Fixed(float const raw);
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed &operator=(const Fixed &src);
	float toFloat() const;
	int toInt() const;
	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);