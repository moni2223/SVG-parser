#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


class Point
{
private:
    double x;
    double y;
public:
    Point(const double x = 0, const double y = 0);

    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);

    double getDistance(Point other);

    bool inRectangle(double startPointX, double startPointY, double width, double height);
    bool inCircle(double startPointX, double startPointY, double radius);
    void PrintCircle(ostream& str);
    void Print(ostream& str);
    void Print();
};