#include "Line.h"

Line::Line(double startPointX, double startPointY, double endPointX, double endPointY, const char* color, size_t id) 
	: Shape(startPointX,startPointY,color,id), end(endPointX,endPointY) {}

Point Line::get_end() {
	return end;
}

Shape* Line::clone() {
	return new Line(*this);
}

void Line::print(ostream& str) {
	str << "<line ";
	start.print(str);
	end.print(str);
	str << "fill=" << color << '"' << " " << "/>" << endl;
}
void Line::print() {
	cout <<"Line -> " <<  "id:" << id << endl;
	start.print();
	end.print();
	cout << "color:" <<", color: " << color << endl;
}

void Line::translate(const double vertical, const double horizontal) {
	start.translate(vertical, horizontal);
	end.translate(vertical, horizontal);
}

bool Line::withinRect(double startPointX, double startPointY, double width, double height) {
	if (start.withinRect(startPointX, startPointY, width, height) && end.withinRect(startPointX, startPointY, width, height)) {
		this->print(cout);
		return true;
	}
	else return false;
}

bool Line::withinCircle(double startPointX, double startPointY, double radius) {
	if (start.withinCircle(startPointX, startPointY,radius) && end.withinCircle(startPointX, startPointY, radius)) {
		this->print(cout);
		return true;
	}
	else return false;
}

double Line::Area(double width, double height) {
	return 0; //line doesnt have area
}