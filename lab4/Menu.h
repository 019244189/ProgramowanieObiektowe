#pragma once
#include "TableViewer.h"
#include "Table.h"

class Menu {
private:
	TableViewer *viewer;
	Table *table;
public:
	/**
	* @param[in] table - obiekt Table
	* @param[in] viewer - obiekt TableViewer
	*/
	Menu(Table *table, TableViewer *viewer);
	void wyswietlMenu();
	void zmienWielkoscMenu();
	void zmienLinieMenu();
	void sumaKolumnyMenu();
	void sumaWierszaMenu();
	void najwieszaWartoscMenu();
	void najmniejszaWartoscMenu();
	void sredniaWartoscMenu();
	void uruchom();
};
