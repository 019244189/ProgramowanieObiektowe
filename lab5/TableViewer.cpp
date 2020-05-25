#include "TableViewer.h"
#include <iostream>
#include <string>


TableViewer::TableViewer()
{
}

void TableViewer::view(Table *table)
{
	int len = table->getLenOfTheLongestValue();
	if (len < 6) len = 6;
	for (int i = -1; i < table->getHeight(); i++) {
		if (i == -1) std::cout << this->formatString(len, "|");
		else std::cout << this->formatString(len, (i < 9 ? "0" : "") + std::to_string(i + 1) + "_|");
		for (int j = 0; j < table->getWidth(); j++) {
			if (i == -1) {
				std::cout << this->formatString(len + 1, (j < 9 ? "0" : "") + std::to_string(j + 1) + "_|");
			}
			else {
				Cell* cell = table->getCell(i, j);
				if (cell != NULL)
					std::cout << this->formatString(len, cell->getValue());
				else std::cout << this->formatString(len, "");
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}
}

std::string TableViewer::formatString(int len, std::string value)
{
	std::string val("");
	for (int i = 0; i < len - value.length(); i++)
		val.append("_");
	val.append(value);
	return val;
}