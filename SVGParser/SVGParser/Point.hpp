#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
using namespace std;

class Point {
	double x;
	double y;

public:
	Point(double x = 0, double y = 0);

	void setX(const double x);
	void setY(const double y);

	double getX() const;
	double getY() const;

	double Distance(Point other);

	bool inRectangle(double pointX, double poimtY, double height, double width);
	bool inCircle(double pointX, double pointY, double radius);

	void PrintCircle(ostream& str);
	void Print(ostream& str);
	void Print();
};