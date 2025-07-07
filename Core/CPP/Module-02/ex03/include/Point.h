#ifndef POINT_H

# define POINT_H
#include "Fixed.h"

class Point {
	Fixed x;
	Fixed y;
public:
	Point();
	Point(float x, float y);
	Point(const Point &copy);
	~Point();
	Point &operator=(const Point &src);
	const Fixed &getX() const;
	const Fixed &getY() const;
};

std::ostream	&operator<<(std::ostream &o, const Point &point);

#endif