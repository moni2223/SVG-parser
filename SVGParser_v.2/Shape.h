#include "Point.h"
class Shape
{
protected:
	Point start;
	char color[20];
	int id;
public:
	Shape(double x = 0, double y = 0, const char* color = "undefined", int id = 0);


	char* getColor();
	int getID() const;
	Point getStart() const;


	void setColor(char* color);
	void setID(int id);


	virtual void Print(ostream& str) = 0;
	virtual void Print() = 0;
	virtual void Translate(double vertical, double horizontal) = 0;
	virtual bool inRectangle(double startPointX, double startPointY, double width, double height) = 0;
	virtual bool inCircle(double startPointX, double startPointY, double radius) = 0;
	virtual double Area(double width, double height) = 0;

	virtual Shape* clone() = 0;

	virtual ~Shape(){};
};