#include "helperFunctions.h"

void Help() {
	cout << "Available commands: " << endl;
	cout << "print - prints all shapes with detailed information" << endl;
	cout << "create - creates shape" << endl;
	cout << "erase - if you input index it will delete the shape at this place" << endl;
	cout << "translate - optionally you enter index, if not it will translate all shapes after you input vertical and horizontal values" << endl;
	cout << "within - you must enter circle or rectangle and its values, and then you should see if there is any shapes in inputted one" << endl;
	cout << "open - opens the file that you input" << endl;
	cout << "save - saves all shapes in the file" << endl;
	cout << "exit - closes the program" << endl;
	cout << "close - closes the file that you have opened" << endl;
}

int main()
{
	ShapesCollection shapes;

	char* cl = new char[128];
	char* command = new char[128];
	char* shape = new char[128];
	char* color = new char[128];
	char* filename = new char[128];
	int index;
	int startX = 0, startY = 0, endX = 0, endY = 0;

	while (true) {
		cout << "Enter the command you want to start: " << endl;
		cin.getline(command, 128);
		if (strcmp(command, "print") == 0)
		{
			shapes.printAll();
		}
		else if (strcmp(command, "create") == 0)
		{
			cout << "Enter the shape you want to create:" << endl;
			cin.getline(shape, 128);

			if (strcmp(shape, "rectangle") == 0)
			{
				cout << "Enter start point coordinates: " << endl;
				cin >> startX;
				cin >> startY;
				cout << "Enter width and height: " << endl;
				cin >> endX;
				cin >> endY;
				cin.ignore();
				cout << "Enter color" << endl;
				cin.getline(color, 128);
				shapes.AddShape("rectangle", startX, startY, color, endX, endY);
			}
			else if (strcmp(shape, "circle") == 0)
			{
				cout << "Enter start point coordinates: " << endl;
				cin >> startX;
				cin >> startY;
				cout << "Enter radius: " << endl;
				cin >> endX;
				cin.ignore();
				cout << "Enter color" << endl;
				cin.getline(color, 128);
				shapes.AddShape("circle", startX, startY, color, endX);
			}
			else if (strcmp(shape, "line") == 0)
			{
				cout << "Enter start point coordinates: " << endl;
				cin >> startX;
				cin >> startY;
				cout << "Enter end point coordinates: " << endl;
				cin >> endX;
				cin >> endY;
				cin.ignore();
				cout << "Enter color" << endl;
				cin.getline(color, 128);
				shapes.AddShape("line", startX, startY, color, endX, endY);
			}
			else
				cout << "This shape is not supported."<<endl;
		}
		else if (strcmp(command, "erase") == 0) {
			cout << "Enter the id of the shape you want to erase: " << endl;
			cin >> index;
			shapes.erase(index);
		}
		else if (strcmp(command, "translate") == 0) {
			int id = -20;
			double vertical, horizontal;
			cout << "Enter the index of the shape you want to translate (optional, if you want to skip enter -1): " << endl;
			cin >> id;
			cout << "Enter vertical value: " << endl;
			cin >> vertical;
			cout << "Enter horizontal value: " << endl;
			cin >> horizontal;
			if (id < 0) {
				shapes.translateShapes(vertical, horizontal);
			}
			else {
				shapes.translateShape(vertical, horizontal, id);
			}
		}
		else if (strcmp(command, "within") == 0) {
			cout << "Enter shape: " << endl;
			cin.getline(shape, 100);
			if (strcmp(shape, "rectangle") == 0) {
				cout << "Enter start coordinates of the rectangle: " << endl;
				cin >> startX;
				cin >> startY;
				cout << "Enter width and height: " << endl;
				cin >> endX;
				cin >> endY;
				shapes.withinRect(startX, startY, endX, endY);
			}
			else if (strcmp(shape, "circle") == 0) {
				cout << "Enter start coordinates of the circle: " << endl;
				cin >> startX;
				cin >> startY;
				cout << "Enter radius: " << endl;
				cin >> endX;
				shapes.withinCircle(startX, startY, endX);
			}
		}
		else if (strcmp(command, "open") == 0)
		{
			cout << "Enter file name:" << endl;
			cin.getline(filename, 128);
			ifstream input(filename);

			if (!input.is_open())
				cout << "Couldn't find file with this name." << endl;

			shapes = shapesFromFile(filename);
		}
		else if (strcmp(command, "exit") == 0)
		    break;

		else if (strcmp(command, "help") == 0)
			Help();

		else if (strcmp(command, "save") == 0) {
			Write(filename, shapes);
			remove(filename);
			rename("temp.svg", filename);
		}
		else if (strcmp(command, "save as") == 0) {
			cout << "Enter the file name you want to create:" << endl;
			cin.getline(filename, 100);
			Write(filename, shapes);
			remove(filename);
			rename("temp.svg", filename);
		}
			

	}
	delete[] cl;
	delete[] command;
	delete[] shape;
	delete[] color;
	delete[] filename;
}
