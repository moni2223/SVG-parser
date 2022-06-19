#include "Shape.h"
class Rectangle : public Shape
{
private:
	double width;
	double height;
public:
	Rectangle(double FirstPointX = 0, double FirstPointY = 0, double width = 0, double height = 0, const char* color = "undefined", int id = 0);

	double getWidth() const;
	double getHeight() const;

	void setWidth(double width);
	void setHeight(double height);

	void Print(ostream& strm);
	void Print();
	void Translate(double horizontal, double vertical);
	bool inRectangle(double startX, double startY, double width, double height);
	bool inCircle(double startX, double startY, double radius);
	double Area(double width, double height);


	Shape* clone();
};