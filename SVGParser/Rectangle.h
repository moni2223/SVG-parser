#include "Circle.h"
class Rectangle : public Shape
{
private:
	double width;
	double height;
public:
	Rectangle(double startPointX = 0, double startPointY = 0, double width = 0, double height = 0, const char* color = "undefined", size_t id = 0);


	double get_width() const;
	double get_height() const;


	void set_width(const double width);
	void set_height(const double height);
	
	
	//overriden methods from Shape
	Shape* clone();
	void print(ostream& str);
	void print();
	void translate(const double vertical, const double horizontal);
	bool inRect(double startPointX, double startPointY, double width, double height);
	bool withinRect(double startPointX, double startPointY, double width, double height);
	bool withinCircle(double startPointX, double startPointY, double radius);
	double Area(double width, double height);


};