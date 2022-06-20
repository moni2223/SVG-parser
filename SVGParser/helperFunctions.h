#pragma once
#include <string>
#include <vector>
#include "ShapesCollection.h"


int lines_count(string filename) {

	ifstream input;
	input.open(filename);
	string line;
	unsigned int curLine = 0;
	while (getline(input, line))
		curLine++;

	input.close();
	return curLine;
}

ShapesCollection shapesFromFile(string filename)
{
	ShapesCollection shapes;
	int lines = lines_count(filename);
	ifstream input;
	string line;                     
	string token = "<svg>";
	string endToken = "</svg>";
	input.open(filename);
	int curLine = 0;
	while (getline(input, line))     
	{
		curLine++;
		if (line.find(token, 0) != string::npos)
			break;
	}

	string shape;
	int LinesLeft = lines - curLine;
	int startX = 0, startY = 0, endX = 0, endY = 0;
	string line2;
	string color;

	input.seekg(0);

	for (int n = 1; n < curLine; n += 1) 
	{
		if (!getline(input, line2))
		{
			cout << "error";
		}
	}// move to svg tag

	while (getline(input, line2))    
	{
		if (LinesLeft == lines)
			break;                   

		input.ignore(2); // ignore< + whitespace
		getline(input, shape, ' ');
		if (shape.compare("rect") == 0)
		{
			getline(input, line, '"');
			input >> startX;

			getline(input, line, '=');
			input.ignore(1);
			input >> startY;

			getline(input, line, '=');
			input.ignore(1);
			input >> endX;

			getline(input, line, '=');
			input.ignore(1);
			input >> endY;

			getline(input, line, '=');
			input.ignore(1);
			getline(input, color, '"');

			int len = color.length() + 1;
			char* ColorChar = new char[len];
			for (int i = 0; i < len; i++) {
				ColorChar[i] = color[i];
			}
			shapes.AddShape("rectangle", startX, startY, ColorChar, endX, endY);
			delete[] ColorChar;
		}
		else if (shape.compare("circle") == 0)
		{
			getline(input, line, '"');
			input >> startX;

			getline(input, line, '=');
			input.ignore(1);
			input >> startY;

			getline(input, line, '=');
			input.ignore(1);
			input >> endX;

			getline(input, line, '=');
			input.ignore(1);
			getline(input, color, '"');

			int len = color.length() + 1;
			char* ColorChar = new char[len];
			for (int i = 0; i < len; i++) {
				ColorChar[i] = color[i];
			}
			shapes.AddShape("circle", startX, startY, ColorChar, endX, endY);
			delete[] ColorChar;
		}
		else if (shape.compare("line") == 0)
		{
			getline(input, line, '"');
			input >> startX;

			getline(input, line, '=');
			input.ignore(1);
			input >> startY;

			getline(input, line, '=');
			input.ignore(1);
			input >> endX;

			getline(input, line, '=');
			input.ignore(1);
			input >> endY;

			getline(input, line, '=');
			input.ignore(1);
			getline(input, color, '"');

			int len = color.length() + 1;
			char* ColorChar = new char[len];
			for (int i = 0; i < len; i++) {
				ColorChar[i] = color[i];
			}
			shapes.AddShape("line", startX, startY, ColorChar, endX, endY);
			delete[] ColorChar;
		}
		LinesLeft++;
	}

	return shapes;
}

void Write(const char* filename, ShapesCollection& shapes)
{
	ofstream ofs;
	ofs.open("temp.svg", ofstream::out);
	ifstream input;
	string line;                     
	string token = "<svg>";
	input.open(filename);
	unsigned int curLine = 0;
	while (getline(input, line))   
	{
		curLine++;
		if (line.find(token, 0) != string::npos)
			break;
	}

	input.seekg(0);
	int LinesLeft = lines_count(filename) - curLine + 1;
	for (int i = 0; i < curLine; i++)
	{
		getline(input, line);
		ofs << line << endl;
	}
	shapes.printAll(ofs);
	ofs << "</svg>";

}