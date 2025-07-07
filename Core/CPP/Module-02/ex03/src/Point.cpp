#include "../include/Point.h"

Point::Point(): x(0), y(0) {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point &copy): x(copy.getX()), y(copy.getY()) {}

Point::~Point() {}

Point &Point::operator=(const Point &src) {
	if (this != &src) {
		this->x = src.getX();
		this->y = src.getY();
	}
	return *this;
}

const Fixed &Point::getX() const {
	return this->x;
}

const Fixed &Point::getY() const {
	return this->y;
}

std::ostream	&operator<<(std::ostream &o, Point const &point)
{
	o << "X: " << point.getX() << " | Y: " << point.getY() << std::endl;
	return (o);
}