#pragma once
#include "Table.h"
#include <string>

class TableViewer {
private:
	/**
	* @param[in] value - zawartosc komorki
	* @return - Sformatowana liczbe wedlug wzoru
	*/
	std::string formatString(int value);
public:
	TableViewer();
	/**
	* @param[in] table - obiekt Table
	*/
	void view(Table *table);
};