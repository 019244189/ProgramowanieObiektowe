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
	* @return - Zwrócenie wartoœci komórki
	*/
	std::string getValue();
	/**
	* @return - Zwrócenie wartoœci komórki jako int,
	Jeœli siê nie uda sparsowaæ komórki to zwróci NULL
	*/
	int getValueAsInt();
	/**
	* @param[in] type - Typ komórki
	*/
	void setType(CellType type);
	/**
	* @return - zwraca typ komórki
	*/
	CellType getType();
};