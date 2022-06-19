#include "ShapesContainer.h"

int main()
{
	ifstream input;
	ShapesContainer shapes;
	char* command = new char[128];
	char* shape = new char[128];
	char* shapeColor = new char[128];
	int startX = 0, startY = 0, endX = 0, endY = 0;

	while (true) {
		cout << "Enter command:" << endl;
		cin.getline(command, 128);
		if (strcmp(command, "print") == 0) shapes.PrintAll();
		else if (strcmp(command, "create") == 0) {
			cout << "Enter shape you want to add:" << endl;
			cin.getline(shape, 128);
			if (strcmp(shape, "line") == 0) {
				cout << "Enter values:" << endl;
				cin >> startX;
				cin >> startY;
				cin >> endX;
				cin >> endY;
				cin.ignore();
				cin.getline(shapeColor, 128);
				shapes.AddShape(shape, startX, startY, shapeColor, endX, endY);
			}

		}
	}
	
}
