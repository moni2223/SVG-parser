#include "Circle.h"
class ShapesContainer
{
private:
	Shape** shapes;

	int capacity;
	int count;

	void copyFrom(const ShapesContainer& other);
	void free();
	void resize(int cap);

public:
	ShapesContainer();
	ShapesContainer(const ShapesContainer& other);
	ShapesContainer& operator=(const ShapesContainer& other);
	~ShapesContainer();

	int GetCount()const;

	Shape* AtIndex(int index);
	void AddShape(const char* shape, double startX, double startY, const char* color, double endX, double endY = 0);
	void PrintAll() const;

	/*void Erase(int index);
	void WithinCircle(double startX, double startY, double radius);
	void PrintAllInStrm(ostream& strm);
	void WithinRectangle(double startX, double startY, double width, double height);
	void TranslateShape(double vertical, double horizontal);
	void TranslateShape(double vertical, double horizontal, int n);
*/
};