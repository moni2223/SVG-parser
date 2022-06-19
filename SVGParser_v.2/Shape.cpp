#include "Shape.h"
Shape::Shape(double x, double y, const char* color, int id) : start(x,y), id(id)
{
	strcpy(this->color, color);
}

char* Shape::getColor()
{
	return color;
}
int Shape::getID() const
{
	return id;
}
Point Shape::getStart() const
{
	return start;
}
void Shape::setColor(char* color)
{
	strcpy(this->color, color);
}
void Shape::setID(int ID)
{
	this->id = id;
}
