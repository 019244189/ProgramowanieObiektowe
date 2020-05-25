#pragma once
#include <string>

enum CellType
{
	TEXT = 0,
	NUMBER = 1
};

class Cell {
private:
	std::string value;
	CellType type;

public:
	Cell();
	/**
	* @param[in] value - zawartosc komorki
	*/
	bool setValue(std::string value);
	/**
	* @return - Zwr�cenie warto�ci kom�rki
	*/
	std::string getValue();
	/**
	* @return - Zwr�cenie warto�ci kom�rki jako int,
	Je�li si� nie uda sparsowa� kom�rki to zwr�ci NULL
	*/
	int getValueAsInt();
	/**
	* @param[in] type - Typ kom�rki
	*/
	void setType(CellType type);
	/**
	* @return - zwraca typ kom�rki
	*/
	CellType getType();
};