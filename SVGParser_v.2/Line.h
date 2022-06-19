#include "Shape.h"
class Line : public Shape
{
private:
	Point endPoint;
public:
	Line(double startX = 0, double startY = 0, double endX = 0, double endY = 0, const char* color = "undefined",int id = 0);

	Point GetEnd();

	void Translate(double vertical, double horizontal);
	bool inRectangle(double startX, double startY, double width, double height);
	bool inCircle(double startX, double startY, double radius);
	double Area(double width, double height);
	void Print(ostream& str);
	void Print();

	virtual ~Line(){};

	Shape* clone();
};