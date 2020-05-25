#include "Table.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Table::Table() {
	this->load();
}

void Table::load() {
	std::string line;
	std::ifstream myfile("data.txt");
	if (myfile.is_open())
	{
		std::cout << "Znaleziono plik z danymi, ladowanie danych..." << std::endl;
		try {


			getline(myfile, line);
			int w = stoi(line);
			getline(myfile, line);
			int h = stoi(line);

			this->resize(w, h);
			int row = 0;

			while (getline(myfile, line))
			{
				std::stringstream ss(line);
				std::string value;
				int column = 0;
				while (getline(ss, value, ';')) {
					if (value != "")
						this->getCell(row, column)->setValue(value);
					column++;
				}
				row++;
			}
		}
		catch (...) {
			myfile.close();
		}
	}

	else {
		std::cout << "Nie znaleziono pliku z danymi." << std::endl;
		this->resize(10, 10);
	}
}

void Table::save() {
	std::ofstream myfile("data.txt");
	if (myfile.is_open())
	{
		myfile << this->width << "\n";
		myfile << this->height << "\n";
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				Cell* cell = this->getCell(i, j);
				if (cell != NULL)
					myfile << cell->getValue();
				if (j + 1 < width)
					myfile << ";";
				else
					myfile << "\n";
			}
		}
		myfile.close();
	}
	else std::cout << "Blad podczas zapisywania!";
}

Cell* Table::getCell(int row, int column)
{
	if (row > this->height || column > this->width)
		return NULL;
	Cell* value = &this->table[row][column];
	return value;
}

void Table::resize(int width, int height) {
	if (this->width <= 0) {
		this->width = width;
		this->height = height;
		this->table = new Cell*[height];
		for (int i = 0; i < width; i++)
			this->table[i] = new Cell[width];
		return;
	}
	Cell **temp = new Cell*[height];
	for (int i = 0; i < width; i++)
		temp[i] = new Cell[width];

	for (int i = 0; i < (this->height < height ? this->height : height); i++) {
		temp[i] = new Cell[width];
		for (int j = 0; j < (this->width < width ? this->width : width); j++)
			temp[i][j] = this->table[i][j];
	}

	delete[] this->table;
	this->table = temp;
	this->width = width;
	this->height = height;
}

void Table::setTabelType(CellType type)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Cell* cell = this->getCell(i, j);
			if (cell != NULL) {
				cell->setValue("");
				cell->setType(type);
			}
		}
	}
	this->save();
}

int Table::sumByColumn(int column)
{
	int sum = 0;
	for (int i = 0; i < this->getHeight(); i++) {
		Cell* cell = this->getCell(i, column);
		if (cell->getType() != NUMBER) return NULL;
		int value = cell->getValueAsInt();
		if (value != NULL)
			sum += value;
	}
	return sum;
}

int Table::sumByRow(int row)
{
	int sum = 0;
	for (int i = 0; i < this->getWidth(); i++) {
		Cell* cell = this->getCell(row, i);
		if (cell->getType() != NUMBER) return NULL;
		int value = cell->getValueAsInt();
		if (value != NULL)
			sum += value;
	}
	return sum;
}

int Table::getTheBiggestValue()
{
	int b = NULL;
	for (int i = 0; i < this->getHeight(); i++) {
		for (int j = 0; j < this->getWidth(); j++) {
			Cell* cell = this->getCell(i, j);
			if (cell->getType() != NUMBER) return NULL;
			int value = cell->getValueAsInt();
			if (value != NULL) {
				if (b == NULL)
					b = value;
				else if (value > b)
					b = value;
			}
		}
	}
	return b;
}

int Table::getLenOfTheLongestValue() {
	int len = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Cell* cell = this->getCell(i, j);
			if (cell != NULL) {
				std::string value = cell->getValue();
				if (value.length() > len)
					len = value.length();
			}
		}
	}
	return len;
}

int Table::getTheSmallestValue()
{
	int b = NULL;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Cell* cell = this->getCell(i, j);
			if (cell->getType() != NUMBER) return NULL;
			int value = cell->getValueAsInt();
			if (cell != NULL && value != NULL) {
				if (b == NULL)
					b = value;
				else if (value < b)
					b = value;
			}
		}
	}
	return b;
}

float Table::getAvgValue()
{
	int el = 0;
	float sum = NULL;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Cell* cell = this->getCell(i, j);
			if (cell->getType() != NUMBER) return NULL;
			int value = cell->getValueAsInt();
			if (cell != NULL && value != NULL) {
				el++;
				sum += value;
			}
		}
	}
	return el > 0 ? sum / el : NULL;
}

int Table::getWidth()
{
	return this->width;
}

int Table::getHeight()
{
	return this->height;
}

Cell ** Table::getTable()
{
	return this->table;
}
