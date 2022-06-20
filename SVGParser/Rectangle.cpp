#include "Rectangle.h"

Rectangle::Rectangle(double startPointX, double startPointY, double width, double height, const char* color, size_t id)
	:Shape(startPointX, startPointY, color, id), width(width), height(height) {}

double Rectangle::get_width() const {
	return width;
}

double Rectangle::get_height() const {
	return height;
}

void Rectangle::set_width(const double width) {
	this->width = width;
}

void Rectangle::set_height(const double height) {
	this->height = height;
}

Shape* Rectangle::clone() {
	return new Rectangle(*this);
}

void Rectangle::print(ostream& str)
{
	str << "  <rect ";
	start.print(str);
	str << "width=" << '"' << width << '"' << " height=" << '"' << height << '"' << " ";
	str << "fill=" << '"' << color << '"' << " " << "/>" << endl;
}
void Rectangle::print()
{
	cout << "Rectangle ->" << " id: " << id << endl;
	start.print();
	cout << ", width: " << width << ", height: " << height << ", color: ";
	cout << color << endl;
}

void Rectangle::translate(double horizontal, double vertical) {
	start.translate(vertical, horizontal);
}

bool Rectangle::withinRect(double startX, double startY, double width, double height)
{
	Point LeftUpperCorner(start.get_x(), start.get_y() + this->height);
	Point RightUpperCorner(start.get_x() + this->width, start.get_y() + this->height);
	Point LeftBottomCorner(start.get_x(), start.get_y());
	if (start.withinRect(startX, startY, width, height) && LeftUpperCorner.withinRect(startX, startY, width, height) && RightUpperCorner.withinRect(startX, startY, width, height) && LeftBottomCorner.withinRect(startX, startY, width, height))
	{
		print(cout);
		return true;
	}
	else
		return false;
}
bool Rectangle::withinCircle(double startX, double startY, double radius)
{
	if (((radius + radius) < this->width) || ((radius + radius) < this->height))return true;
	else return false;
}

double Rectangle::Area(double width, double height) {
	return width * height;
}