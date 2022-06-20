#include "Point.h"

Point::Point(const double x, const double y) : x(x), y(y){}

double Point::get_x() const {
	return x;
}

double Point::get_y() const {
	return y;
}

void Point::set_x(const double x) {
	this->x = x;
}

void Point::set_y(const double y) {
	this->y = y;
}

double Point::getDistance(Point other) {
	double xDist = x - other.x;
	double yDist = y - other.y;
	return sqrt(xDist * xDist + yDist * yDist);
}

bool Point::withinRect(double startPointX, double startPointY, double width, double height) {
	if (x < startPointX + width && y < startPointY + height && x > startPointX && y > startPointY) return true;
	else return false;
}

bool Point::withinCircle(double startPointX, double startPointY, double radius) {
	if (((x - startPointX) * (x - startPointX) + (y - startPointY) * (y -startPointY)) < radius * radius)
		return true;
	else
		return false;
}

void Point::translate(const double vertical, const double horizontal) {
	set_x(x + horizontal);
	set_y(y + vertical);
}

void Point::print(ostream& str)
{
	str << "x=" << '"' << x << '"' << " " << "y=" << '"' << y << '"' << " ";
}
void Point::print()
{
	cout <<"(" << x << "," << y<<")";
}