#include "Point.hpp"

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const
{
    return x;
}
double Point::getY() const
{
    return y;
}
void Point::setX(const double x)
{
    this->x = x;
}
void Point::setY(const double y)
{
    this->y = y;
}

double Point::Distance(Point other)
{
    double xdist = x - other.x;
    double ydist = y - other.y;
    return sqrt(xdist * xdist + ydist * ydist);
}

bool Point::inRectangle(double pointX, double pointY, double height, double width)
{
    if (this->getX() < pointX + width && this->getX() > pointX && this->getY() > pointY && this->getY() < pointY + height)
        return true;
    else
        return false;
}
bool Point::inCircle(double pointX, double pointY, double radius)
{
    if (((this->getX() - pointX) * (this->getX() - pointX) + (this->getY() - pointY) * (this->getY() - pointY)) < radius * radius) return true;

    else return false;
}
void Point::PrintCircle(ostream& str)
{
    str << "cx=" << '"' << this->x << '"' << " " << "cy=" << '"' << this->y << '"' << " ";
}
void Point::Print(ostream& str)
{
    str << "x=" << '"' << this->x << '"' << " " << "y=" << '"' << this->y << '"' << " ";
}
void Point::Print()
{
    cout << this->x << "," << this->y;
}