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
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	float operator+(const Fixed &fixed) const;
	float operator-(const Fixed &fixed) const;
	float operator*(const Fixed &fixed) const;
	float operator/(const Fixed &fixed) const;
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	float toFloat() const;
	int toInt() const;
	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(Fixed const &first, Fixed const &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(Fixed const &first, const Fixed &second);
	int getRawBits() const;
	void setRawBits(int raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);