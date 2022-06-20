#include "Circle.h"

Circle::Circle(double centerX,double centerY,double radius,const char* color,size_t id)
	: Shape(centerX,centerY,color,id), radius(radius){}

double Circle::get_radius() const {
	return radius;
}

void Circle::set_radius(const double radius) {
	this->radius = radius;
}

Shape* Circle::clone() {
	return new Circle(*this);
}

void Circle::print(ostream& str) {
	str << "<circle ";
	str << "cx=" << '"' << start.get_x() << '"' << " " << "cy=" << '"' << start.get_y() << '"' << " ";
	str << "r=" << '"' << radius << '"' << " ";
	str << "fill=" << color << '"' << " " << "/>" << endl;
}
void Circle::print() {
	cout <<"Circle -> " << " id: " << id << " radius: " << radius << endl;
	start.print();
	cout << ", color:" << color << endl;
}

void Circle::translate(const double vertical, const double horizontal) {
	start.translate(vertical, horizontal);
}

bool Circle::withinCircle(double startX, double startY, double radius)
{
	Point point(startX, startY);
	double dist = start.getDistance(point);

	if (dist + this->radius < radius) {
		print(cout);
		return true;
	}
	else if (this->radius < radius) {
		if (dist + radius < radius)
		{
			print(cout);
			return true;
		}
	}

	else return false;
}

bool Circle::inRect(double startPointX, double startPointY, double width, double height) {
	if (start.get_x() + this->radius > (startPointX + width)) 
		return false;

	else if (start.get_x() - this->radius < startPointX)
		return false;

	if (start.get_y() + this->radius > (startPointY + height))
		return false;
	
	else if (start.get_y() - radius < startPointY)
		return false;

	else
		return true;
}

bool Circle::withinRect(double startPointX, double startPointY, double width, double height)
{
	if (inRect(startPointX, startPointY, width, height)) {
		print(cout);
		return true;
	}
	else return false;
}

double Circle::Area(double width, double height) {
	return 3.14 * width * width;
}
