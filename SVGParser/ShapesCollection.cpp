#include "ShapesCollection.h"

void ShapesCollection::free()
{
	for (int i = 0; i < count; i++)
		delete shapes[i];

	delete[] shapes;
}

void ShapesCollection::copyFrom(const ShapesCollection& other) {
	shapes = new Shape * [other.count];

	count = other.count;
	capacity = other.capacity;

	for (int i = 0; i < other.count; i++) shapes[i] = other.shapes[i]->clone();

}

void ShapesCollection::resize(int newCap)
{
	Shape** NewArray = new Shape * [newCap];

	for (int i = 0; i < count; i++)
		NewArray[i] = shapes[i];
	delete[] shapes;
	capacity = newCap;
	shapes = NewArray;

}

int ShapesCollection::get_count() const {
	return count;
}

ShapesCollection::ShapesCollection() : count(0), capacity(4) {
	shapes = new Shape * [capacity];
}

ShapesCollection::ShapesCollection(const ShapesCollection& other) {
	copyFrom(other);
}

ShapesCollection& ShapesCollection::operator=(const ShapesCollection& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ShapesCollection::~ShapesCollection() {
	free();
}

void ShapesCollection::AddShape(const char* shape, double startX, double startY, const char* color, double endX, double endY)
{
	if (count == this->capacity)
		resize(capacity * 2);

	Shape* newObj;

	if (strcmp(shape, "line") == 0)
	{
		newObj = new Line(startX, startY, endX, endY, color, count + 1);
	}
	else if (strcmp(shape, "circle") == 0)
	{
		newObj = new Circle(startX, startY, endX, color, count + 1);
	}
	else if (strcmp(shape, "rectangle") == 0)
	{
		newObj = new Rectangle(startX, startY, endX, endY, color, count + 1);
	}
	else{
		cout << "You entered invalid shape." << endl;
		return;
	}

	shapes[this->count++] = newObj;
}

Shape* ShapesCollection::AtIndex(int index) {
	if (index - 1 > count) {
		cout << "No shape on this position" << endl;
	}
	else return shapes[index - 1];
}

void ShapesCollection::printAll(ostream& str) const {
	for (int i = 0; i < count; i++) {
		shapes[i]->print(str);
	}
}

void ShapesCollection::printAll() const {
	for (int i = 0; i < count; i++) {
		shapes[i]->print();
	}
}

void ShapesCollection::erase(int index) {
	bool deleted = false;
	for (int i = 0; i < count; i++)
	{
		if (index == shapes[i]->get_id())
		{
			cout << "Deleted shape with id: " << shapes[i]->get_id() << endl;
			deleted = true;
			int i, j;
			Shape** NewArray = new Shape * [capacity];
			for (i = 0; i < index - 1; i++)
			{
				NewArray[i] = shapes[i];
			}	

			for (j = index; j < count; j++)
			{
				NewArray[i] = shapes[j];
				i++;
			}
			delete[] shapes;
			shapes = NewArray;
			count--;

			break;
		}
	}
	if (!deleted)
	{
		cout << "No figure number with index: " << index << endl;
	}
}

void ShapesCollection::withinCircle(double startX, double startY, double radius)
{
	int counter = 0;
	for (int i = 0; i < count; i++)
		if (shapes[i]->withinCircle(startX, startY, radius)) counter++;

	if (counter == 0)
		cout << "None of the figures are located within circle " << startX << " " << startY << " " << radius;
}

void ShapesCollection::withinRect(double startX, double startY, double width, double height)
{
	int counter = 0;
	for (int i = 0; i < count; i++)
		if (shapes[i]->withinRect(startX, startY, width, height)) counter++;

	if (counter == 0)
		cout << "None of the figures are located within rectangle " << startX << " " << startY << " " << width << " " << height;
}

void ShapesCollection::translateShape(double vertical, double horizontal, int n)
{
	shapes[n]->translate(vertical, horizontal);
	cout << "Shape with index: " << n << "translated successfully" << endl;
}

void ShapesCollection::translateShapes(double vertical, double horizontal) {

	for (int i = 0; i < count; i++){
		shapes[i]->translate(vertical,horizontal);
	}
	cout << "All figures are translated" << endl;
}
