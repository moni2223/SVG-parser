#include "Shape.h"
Shape::Shape(double x, double y, const char* color, unsigned int id)
{
	this->start.setX(x);
	this->start.setY(y);
	strcpy(this->color, color);
	this->id = id;
}

char* Shape::GetColor()
{
	return color;
}

void Shape::SetColor(char* color)
{
	strcpy(this->color, color);
}

unsigned int Shape::getID()
{
	return id;
}

void Shape::setID(unsigned int id)
{
	this->id = id;
}

Point Shape::GetStart()
{
	return start;
}

