#include "Line.h"
class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double centerX = 0, double centerY = 0, double radius = 0, const char* color = "undefined", int id = 0);


	double getRadius() const;
	void setRadius(double radius);


	void Translate(double horizontal, double vertical);
	//bool IsWithinRectangle(double startX, double startY, double width, double height);
	bool isInRectangle(double startX, double startY, double width, double height);
	bool inRectangle(double startX, double startY, double width, double height);
	bool inCircle(double startX, double startY, double radius);
	double Area(double width, double height);
	void Print(ostream& str);
	void Print();
	virtual ~Circle(){};



	Shape* clone();
};