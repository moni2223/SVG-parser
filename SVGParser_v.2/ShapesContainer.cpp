#include "ShapesContainer.h"

void ShapesContainer::free()
{
	for (int i = 0; i < count; i++)
		delete shapes[i];

	delete[] shapes;
}
void ShapesContainer::copyFrom(const ShapesContainer& other)
{
	shapes = new Shape * [other.count];
	capacity = other.capacity;
	count = other.count;
	for (int i = 0; i < other.count; i++)
		shapes[i] = other.shapes[i]->clone();
}
void ShapesContainer::resize(int NewCappacity)
{
	Shape** NewArray = new Shape * [NewCappacity];

	for (int i = 0; i < count; i++) NewArray[i] = shapes[i];

	delete[] shapes;
	shapes = NewArray;
	capacity = NewCappacity;
}

int ShapesContainer::GetCount()const
{
	return count;
}

ShapesContainer::ShapesContainer()
{
	capacity = 4;
	shapes = new Shape * [capacity];
	count = 0;

}

ShapesContainer::ShapesContainer(const ShapesContainer& other)
{
	copyFrom(other);
}

ShapesContainer& ShapesContainer::operator=(const ShapesContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ShapesContainer::~ShapesContainer()
{
	free();
}

Shape* ShapesContainer::AtIndex(int index)
{
	if (index - 1 > count)
		cout << "There is no figure at index" << index;
	else
		return shapes[index - 1];
}

void ShapesContainer::AddShape(const char* shape, double startX, double startY, const char* color, double endX, double endY)
{
	if (count == this->capacity)
		resize(capacity * 2);

	Shape* newObj;

	if (strcmp(shape, "line") == 0)
		newObj = new Line(startX, startY, endX, endY, color,this->GetCount());

	else if (strcmp(shape, "circle") == 0)
		newObj = new Circle(startX, startY, endX, color, count + 1); // endX here plays the role of radius
	/*
	else if (strcmp(shape, "rectangle") == 0)
		newObj = new Rectangle(startX, startY, endX, endY, color, count + 1); // endX and endY play the role of width and height exactly in that order
	*/
	else throw "Invalid shape";

	shapes[this->count++] = newObj;
}

void ShapesContainer::PrintAll() const
{
	for (int i = 0; i < count; i++)
		shapes[i]->Print();
}