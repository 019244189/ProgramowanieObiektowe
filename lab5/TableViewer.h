#pragma once
#include "Table.h"
#include <string>

class TableViewer {
private:
	/**
	* @param[in] len - na ile znaków na sformatowaæ wartoœæ
	* @param[in] value - zawartosc komorki
	* @return - Sformatowana liczbe wedlug wzoru
	*/
	std::string formatString(int len, std::string value);
public:
	TableViewer();
	/**
	* @param[in] table - obiekt Table
	*/
	void view(Table *table);
};