#include "Shape.h"
Shape::Shape(double x, double y, const char* color, size_t id) : start(x,y), id(id)
{
	strcpy(this->color, color);
}

char* Shape::get_color()
{
	return color;
}
size_t Shape::get_id() const
{
	return id;
}
Point Shape::get_start() const
{
	return start;
}
void Shape::set_color(const char* color)
{
	strcpy(this->color, color);
}
void Shape::set_id(size_t ID)
{
	this->id = id;
}