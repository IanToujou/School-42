#include "../include/Fixed.h"
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed(): fixedPointValue(0) {}

Fixed::Fixed(int const raw)
{
	this->fixedPointValue = raw << fractionalBits;
}

Fixed::Fixed(float const raw): fixedPointValue(raw)
{
	this->fixedPointValue = roundf(raw * (1 << this->fractionalBits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->fixedPointValue = src.fixedPointValue;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

float Fixed::operator+(const Fixed &fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(const Fixed &fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(const Fixed &fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(const Fixed &fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++()
{
	this->fixedPointValue++;
	return *this;
}

Fixed Fixed::operator--()
{
	this->fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->fixedPointValue;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->fixedPointValue;
	return *this;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(this->fixedPointValue) / static_cast<float>(1 << fractionalBits));
}

int Fixed::toInt() const
{
	return (this->fixedPointValue >> fractionalBits);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}

int Fixed::getRawBits() const
{
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}