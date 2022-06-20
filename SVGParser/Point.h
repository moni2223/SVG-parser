#pragma warning(disable : 4996)
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

class Point {
	double x;
	double y;
public:
	Point(const double x = 0, const double y = 0);

	double get_x() const;
	double get_y() const;

	void set_x(const double x);
	void set_y(const double y);

	double getDistance(Point other);

	bool withinRect(double startPointX, double startPointY, double width, double height);
	bool withinCircle(double startPointX, double startPointY, double radius);

	void translate(const double vertical, const double horizontal);

	void print(ostream& str);
	void print();

};