#include "../include/Fixed.h"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(): fixedPointValue(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const raw)
{
	std::cout << "Int Constructor called" << std::endl;
	this->fixedPointValue = raw << this->fractionalBits;
}

Fixed::Fixed(float const raw): fixedPointValue(raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(raw * (1 << this->fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixedPointValue = src.fixedPointValue;
	return *this;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(this->fixedPointValue) / static_cast<float>(1 << this->fractionalBits));
}

int Fixed::toInt() const
{
	return (this->fixedPointValue >> this->fractionalBits);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}