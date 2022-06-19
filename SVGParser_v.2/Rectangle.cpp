#include "Rectangle.h"
Rectangle::Rectangle(double startX, double startY, double width, double height, const char* color, int id) :Shape(startX, startY, color, id)
{
	setWidth(width);
	setHeight(height);
}

double Rectangle::getWidth() const
{
	return width;
}
double Rectangle::getHeight() const
{
	return height;
}
void Rectangle::setWidth(double width)
{
	this->width = width;
}
void Rectangle::setHeight(double height)
{
	this->height = height;
}

void Rectangle::Print(ostream& str)
{
	str << "  <rect ";
	start.Print(str);
	str << "width = " << '"' << width << '"' << " height = " << '"' << height << '"' << " ";
	str << "fill = " << '"' << color << '"' << " " << "/>"<<endl;
}
void Rectangle::Print()
{
	cout << id << ". rectangle, ";
	start.Print();
	cout << ", " << width << ", " << height << ", ";
	cout << color<<endl;
}

bool Rectangle::inRectangle(double startX, double startY, double width, double height)
{
	Point LeftUpperCorner(start.getX() + this->width, start.getY() + this->height));
	Point RightUpperCorner(start.getX(), start.getY() + this->height);
	Point LeftBottomCorner(start.getX() + this->width, start.getY());
	if (start.inRectangle(startX, startY, width, height) && LeftUpperCorner.inRectangle(startX, startY, width, height) && RightUpperCorner.inRectangle(startX, startY, width, height) && LeftBottomCorner.inRectangle(startX, startY, width, height))
	{
		this->Print(cout);
		return true;
	}
	else
		return false;
}
bool Rectangle::inCircle(double startX, double startY, double radius)
{
}

void Rectangle::Translate(double horizontal, double vertical)
{
	start.setX(start.getX() + horizontal);
	start.setY(start.getY() + horizontal);
}


Shape* Rectangle::clone()
{
	return new Rectangle(*this);
}

double Rectangle::Area(double width, double height)
{
	return width * height;
}