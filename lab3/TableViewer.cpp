#include "TableViewer.h"
#include <iostream>
#include <string>


TableViewer::TableViewer()
{
}

void TableViewer::view(Table *table)
{
	/*
	___|__1__|__2__|__3__|__4__|  
	1._|1____|_____|_____|_____|
	2._|2____|_____|200__|_____|
	3._|10___|_____|_____|_____|


	*/


	for (int i = -1; i < table->getHeight(); i++) {
		if (i == -1) std::cout << "____|";
		else std::cout << (i < 9 ? "0" : "") << i + 1 << "._|";
		for (int j = 0; j < table->getWidth(); j++) {
			if (i == -1) {
				std::cout << "__" << (j < 9 ? "0" : "")  << j + 1 << "__|";
			}
			else {
				int value = table->getCellValue(i, j);
				if (value != NULL)
					std::cout << this->formatString(value);
				else std::cout << "______";
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}
}

std::string TableViewer::formatString(int value)
{
	std::string str_value = std::to_string(value);
	std::string val("");
	for (int i = 0; i < 6 - str_value.size(); i++)
		val.append("_");
	val.append(str_value);
	return val;
}