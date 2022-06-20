#include "Shape.h"
class Line : public Shape
{
private:
	Point end;
public:
	Line(double startPointX = 0, double startPointY = 0, double endPointX = 0, double endPointY = 0, const char* color = "undefined", size_t id = 0);


	Point get_end();

	//overriden methods from Shape
	Shape* clone();
	void print(ostream& str);
	void print();
	void translate(const double vertical, const double horizontal);
	bool withinRect(double startPointX, double startPointY, double width, double height);
	bool withinCircle(double startPointX, double startPointY, double radius);
	double Area(double width, double height);

	~Line(){};
};