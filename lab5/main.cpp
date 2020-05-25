#include <iostream>
#include "Table.h"
#include "TableViewer.h"
#include "Menu.h"
#include <string>
#include <cstdint>

int main()
{
	Table *table = &Table();
	TableViewer *viewer = &TableViewer();
	Menu *menu = &Menu(table, viewer);
	menu->uruchom();
}