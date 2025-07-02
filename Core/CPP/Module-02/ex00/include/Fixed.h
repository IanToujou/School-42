#pragma once

#include <iostream>

class Fixed {
	int fixedPointValue;
	static const int fractionalBits;
public:
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed &operator=(const Fixed &src);
	int getRawBits() const;
	void setRawBits(int const raw);
};