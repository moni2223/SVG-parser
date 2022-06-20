#include "Point.h"

class Shape {
protected:
	Point start;
	char color[50];
	size_t id;
	// protected because it will be inaccessible in derived
public:
	Shape(const double x = 0, const double y = 0, const char* color = "undefined", size_t id = 0);


	size_t get_id() const;
	char* get_color();
	Point get_start() const;

	void set_id(size_t id);
	void set_color(const char* color);

	//Methods that will be overwritten for different shapes (line,circle,rectangle)
	virtual Shape* clone() = 0;
	virtual void print(ostream& str) = 0;
	virtual void print() = 0;
	virtual void translate(const double vertical, const double horizontal) = 0;
	virtual bool withinRect(double startPointX, double startPointY, double width, double height) = 0;
	virtual bool withinCircle(double startPointX, double startPointY, double radius) = 0;
	virtual double Area(double width, double height) = 0;
	virtual ~Shape() {};


};