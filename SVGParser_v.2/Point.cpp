#include "Point.h"

Point::Point(const double x, const double y)
{
    setX(x);
    setY(y);
}
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

double Point::getDistance(Point other)
{
    double xd = x - other.x;
    double yd = y - other.y;
    return sqrt(xd * xd + yd * yd);
}


bool Point::inRectangle(double startPointX, double startPointY, double width, double height) // we can check if point is smaller than the gathering of the start point of the rectangle + the width (same for y)
{
    if (this->x >= startPointX && this->y >= startPointY && this->x < startPointX + width  && this->y < startPointY + height)
        return true;

    else return false;
}

bool Point::inCircle(double startPointX, double startPointY, double radius)
{
    if (radius * radius > ((x - startPointX) * (x - startPointX)) + ((y - startPointY) * (y - startPointY))) return true;
    else return false;
}

void Point::PrintCircle(ostream& str)
{
    str << "cx = " << '"' << x << '"' << " " << "cy = " << '"' << y << '"' << " ";
}

void Point::Print(ostream& str)
{
    str << "x = " << '"' << x << '"' << " " << "y = " << '"' << y << '"' << " ";
}
void Point::Print()
{
    cout <<"(" << x << "," << y << ")";
}