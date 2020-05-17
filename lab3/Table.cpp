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
					this->setCellValue(row, column, stoi(value));
				column++;
			}
			row++;
		}
		myfile.close();
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
				int value = this->getCellValue(i, j);
				if (value != NULL)
					myfile << value;
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

void Table::setCellValue(int row, int column, int value)
{
	this->table[row][column] = value;
}

int *x = new int[1];
int Table::getCellValue(int row, int column)
{
	int not_initialized = x[0];
	if (row > this->height || column > this->width)
		return NULL;
	int value = this->table[row][column];
	return value != not_initialized ? value : NULL;
}

void Table::resize(int width, int height) {
	if (this->width <= 0) {
		this->width = width;
		this->height = height;
		this->table = new int*[height];
		for (int i = 0; i < width; i++)
			this->table[i] = new int[width];
		return;
	}

	int **temp = new int*[height];
	for (int i = 0; i < width; i++)
		temp[i] = new int[width];


	for (int i = 0; i < (this->height < height ? this->height : height); i++) {
		temp[i] = new int[width];
		for (int j = 0; j < (this->width < width ? this->width : width); j++)
			temp[i][j] = this->table[i][j];
	}

	delete[] this->table;
	this->table = temp;
	this->width = width;
	this->height = height;
}

int Table::sumByColumn(int column)
{
	int sum = 0;
	for (int i = 0; i < this->getHeight(); i++) {
		int value = this->getCellValue(i, column);
		if (value != NULL)
			sum += value;
	}
	return sum;
}

int Table::sumByRow(int row)
{
	int sum = 0;
	for (int i = 0; i < this->getWidth(); i++) {
		int value = this->getCellValue(row, i);
		if (value != NULL)
			sum += value;
	}
	return sum;
}

int Table::getTheBiggestValue()
{
	int b = NULL;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int value = this->getCellValue(i, j);
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

int Table::getTheSmallestValue()
{
	int b = NULL;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int value = this->getCellValue(i, j);
			if (value != NULL) {
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
			int value = this->getCellValue(i, j);
			if (value != NULL) {
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

int ** Table::getTable()
{
	return this->table;
}
