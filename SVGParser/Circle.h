#include "Line.h"
class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double centerX = 0, double centerY = 0, double radius = 0, const char* color = "undefined", size_t id = 0);


	double get_radius() const;
	void set_radius(const double radius);

	//overriden methods from Shape
	Shape* clone();
	void print(ostream& str);
	void print();
	void translate(const double vertical, const double horizontal);
	bool inRect(double startPointX, double startPointY, double width, double height);
	bool withinRect(double startPointX, double startPointY, double width, double height);
	bool withinCircle(double startPointX, double startPointY, double radius);
	double Area(double width, double height);

	~Circle() {};

};