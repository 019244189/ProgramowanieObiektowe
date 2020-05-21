#include <iostream>
#include "Table.h"
#include "TableViewer.h"
#include "Menu.h"

int main()
{
	Table *table = &Table();
	TableViewer *viewer = &TableViewer();
	Menu *menu = &Menu(table, viewer);
	menu->uruchom();
}