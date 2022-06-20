#include "Rectangle.h"
class ShapesCollection
{
private:
	int capacity;
	int count;
	Shape** shapes;

	void copyFrom(const ShapesCollection& other);
	void free();
	void resize(int newCap);

public:
	ShapesCollection();
	ShapesCollection(const ShapesCollection& other);
	ShapesCollection& operator=(const ShapesCollection& other);
	~ShapesCollection();

	int get_count() const;

	void AddShape(const char* shape, double startPointX, double startPointY, const char* color, double endPointX, double endPointY = 0);
	Shape* AtIndex(int index);
	void printAll(ostream& strm) const;
	void printAll() const;
	void erase(int index);
	void withinCircle(double startX, double startY, double radius);
	void withinRect(double startX, double startY, double width, double height);
	void translateShapes(double vertical, double horizontal);
	void translateShape(double vertical, double horizontal, int n);

};