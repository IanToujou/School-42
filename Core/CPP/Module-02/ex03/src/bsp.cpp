#include "../include/Point.h"

static float calculate_area(const Point a, const Point b, const Point c)
{
	const float area = (( a.getX().toFloat() * ( b.getY().toFloat() - c.getY().toFloat()))
			+ ( b.getX().toFloat() * ( c.getY().toFloat() - a.getY().toFloat()))
			+ ( c.getX().toFloat() * ( a.getY().toFloat() - b.getY().toFloat()))) / 2;
	if (area >= 0)
		return (area);
	return (area * -1);
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {

	float d0, d1, d2, d3;
	bool result = false;

	d0 = calculate_area(a, b, c);
	d1 = calculate_area(point, a, b);
	d2 = calculate_area(point, b, c);
	d3 = calculate_area(point, a, c);
	if (d1 == 0 || d2 == 0 || d3 == 0)
		result = false;
	else if (d1 + d2 + d3 == d0)
		result = true;
	return result;
}