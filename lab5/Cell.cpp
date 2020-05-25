#include "Cell.h"
#include <string>
#include <iostream>


Cell::Cell() {
	this->setType(TEXT);
}

bool Cell::setValue(std::string value) {
	if (this->type == NUMBER) {
		try {
			std::stoi(value);
			this->value = value;
			return true;
		}
		catch (...) {
			return false;
		}
	}
	else {
		this->value = value;
		return true;
	}
}

std::string Cell::getValue() {
	return this->value;
}

int Cell::getValueAsInt() {
	try {
		return std::stoi(this->value);
	}
	catch (...) {
		return NULL;
	}
}

void Cell::setType(CellType type) {
	this->type = type;
}

CellType Cell::getType() {
	return this->type;
}
