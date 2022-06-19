#include "Line.h"
Line::Line(double startX, double startY, double endX, double endY, const char* color,int id) : Shape(startX,startY,color,id)
{
	this->endPoint.setX(endX);
	this->endPoint.setY(endY);
}

Point Line::GetEnd()
{
	return endPoint;
}

void Line::Print(ostream& str)
{
	str << "  <line ";
	start.Print(str);
	endPoint.Print(str);
	str << "fill = " << '"' << color << '"' << " " << "/>"<<endl;
}
void Line::Print()
{
	cout << id << ". line, ";
	start.Print();
	cout << ", ";
	endPoint.Print();
	cout << ", " << color << endl;
}

void Line::Translate(double vertical, double horizontal)
{
	start.setX(start.getX() + horizontal);
	start.setY(start.getY() + horizontal);
	endPoint.setX(endPoint.getX() + vertical);
	endPoint.setY(endPoint.getY() + vertical);
}

double Line::Area(double width, double height)
{
	return 0;
}
Shape* Line::clone()
{
	return new Line(*this);
}

bool Line::inCircle(double startX, double startY, double radius) { // both start and end should be in the circle
	if (start.inCircle(startX, startY, radius) && endPoint.inCircle(startX, startY, radius)) return true;
	else return false;
}

bool Line::inRectangle(double startX, double startY, double width, double height)
{
	if (start.inRectangle(startX, startY, width, height) && endPoint.inRectangle(startX, startY, width, height))
	{
		this->Print(cout);
		return true;
	}
	else
		return false;
}

