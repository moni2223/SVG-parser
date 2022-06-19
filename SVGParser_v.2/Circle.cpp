#include "Circle.h"
Circle::Circle(double centerX, double centerY, double radius, const char* color, int id) :Shape(centerX, centerY, color, id)
{
	this->radius = radius;
}


double Circle::getRadius() const
{
	return radius;
}
void Circle::setRadius(double radius)
{
	this->radius = radius;
}

void Circle::Print(ostream& strm)
{
	strm << "  <circle ";
	start.PrintCircle(strm);
	strm << "r = " << '"' << radius << '"' << " ";
	strm << "fill = " << '"' << color << '"' << " " << "/>"<<endl;
}
void Circle::Print()
{
	cout << id << ". circle, ";
	start.Print();
	cout << ", " << radius << ", ";
	cout << color;
	cout << endl;
}
void Circle::Translate(double horizontal, double vertical)
{
	start.setX(start.getX() + horizontal);
	start.setY(start.getY() + horizontal);
}

bool Circle::isInRectangle(double startX, double startY, double width, double height) {
	Point rectangleCenter = Point((startX + width / 2), (startY + height / 2));

	double w = width / 2;
	double h = height / 2;

	double dx = abs(start.getX() - rectangleCenter.getX());
	double dy = abs(start.getY() - rectangleCenter.getY());

	if (dx > (radius + w) || dy > (radius + h)) return false;

	Point circleDistance = Point((abs(start.getX() - startX - w)), (abs(start.getY() - startY - h)));

	if (circleDistance.getX() <= (w))
	{
		return true;
	}
	if (circleDistance.getY() <= (h))
	{
		return true;
	}
	double cornerDistanceSq = pow(circleDistance.getX() - w, 2) + pow(circleDistance.getY() - h, 2);

	return (cornerDistanceSq <= (pow(radius, 2)));
}

bool Circle::inRectangle(double startX, double startY, double width, double height)
{
	if (this->inRectangle(startX, startY, width, height))
	{
		this->Print(cout);
		return true;
	}
	return false;
}

bool Circle::inCircle(double startX, double startY, double radius)
{
	Point point(startX, startY);
	double dist = start.getDistance(point);
	if (this->getRadius() < radius)
	{
		if (dist + radius < this->getRadius())
		{
			this->Print(cout);
			return true;
		}
	}
	else if (dist + this->getRadius() < radius)
	{
		this->Print(cout);
		return true;
	}
	else
	{
		return false;
	}
}
double Circle::Area(double width, double height = 0)
{
	return width * width * 3.14 ;
}


Shape* Circle::clone()
{
	return new Circle(*this);
}