#include "Point.hpp"
class Shape
{
protected:
	Point start;
	char color[25];
	unsigned int id;
public:
	Shape(double x = 0, double y = 0, const char* color = "Unidentified", unsigned int id = 0);

	virtual Shape* clone() = 0;

	char* GetColor();
	unsigned int getID();
	Point GetStart();
	void SetColor(char* color);
	void setID(unsigned int id);


	virtual void Print() = 0;
	virtual void Translate(double vertical, double horizontal) = 0;
	virtual bool inRectangle(double startX, double startY, double width, double height) = 0;
	virtual bool inCircle(double startX, double startY, double radius) = 0;
	virtual double Area(double width, double height) = 0;
	virtual void Print(ostream& strm) = 0;
	virtual ~Shape();

};