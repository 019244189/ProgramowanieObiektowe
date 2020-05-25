#include <iostream>
#include <string>
#include "Menu.h"

Menu::Menu(Table *table, TableViewer *viewer)
{
	this->table = table;
	this->viewer = viewer;
}

void Menu::wyswietlMenu() {
	std::cout << std::endl;
		std::cout << "----------------------------" << std::endl;
		std::cout << "Dostepne opcje:" << std::endl;
		std::cout << "1. Zmien wielkosc tablicy." << std::endl;
		std::cout << "2. Edytuj dana wartosc komorki." << std::endl;
		std::cout << "3. Wyswietl tablice." << std::endl;
		std::cout << "4. Sumuj wszystkie wartosci z danej kolumny." << std::endl;
		std::cout << "5. Sumuj wszystkie wartosci z danego wiersza." << std::endl;
		std::cout << "6. Znajdz najwiesza wartosc." << std::endl;
		std::cout << "7. Znajdz najmniejsza wartosc." << std::endl;
		std::cout << "8. Wylicz sredna wartosc." << std::endl;
		std::cout << "9. Wyjdz z programu." << std::endl;
		std::cout << "10. Zmien typ tabeli." << std::endl;
		std::cout << "----------------------------" << std::endl << std::endl;

		std::cout << "Wpisz nr polecenia: ";
	}


	void Menu::zmienWielkoscMenu() {
		int w;
		do {
			std::cout << "Wpisz ilosc kolumn: ";
			std::cin >> w;
		} while (w <= 0);
		int h;
		do {
			std::cout << "Wpisz ilosc wierszy: ";
			std::cin >> h;
		} while (h <= 0);
		this->table->resize(w, h);
		this->table->save();
		std::cout << "Zmieniono wielkosc arkuszu na " << w << "x" << h;
	}

	void Menu::zmienLinieMenu() {
		int row = 0;
		do {
			std::cout << "Wpisz nr wiersza: ";
			std::cin >> row;
		} while (row <= 0 || row > this->table->getHeight());


		int column = 0;
		do {
			std::cout << "Wpisz nr kolumny: ";
			std::cin >> column;
		} while (column <= 0 || column > this->table->getWidth());

		std::cout << "Wpisz wartosc " << row << "x" << column << ": ";
		std::string value;

		std::cin.ignore();
		std::getline(std::cin, value);

		Cell* cell = this->table->getCell(row - 1, column - 1);
		bool success = cell->setValue(value);
		if (!success) {
			std::cout << "Blad! Jestes pewien ze tabela ma taki typ danych?";
		}
		else {
			this->table->save();
			std::cout << "Zmieniono zawartosc komorki " << row << "x" << column << " na: " << value;
		}
	}

	void Menu::sumaKolumnyMenu()
	{
		int column = 0;
		do {
			std::cout << "Wpisz nr kolumny: ";
			std::cin >> column;
		} while (column <= 0 || column > this->table->getWidth());

		std::cout << "Suma wartosci z kolumny " << column << " wynosi: " << this->table->sumByColumn(column - 1);
	}

	void Menu::sumaWierszaMenu()
	{
		int row = 0;
		do {
			std::cout << "Wpisz nr wiersza: ";
			std::cin >> row;
		} while (row <= 0 || row > this->table->getWidth());

		std::cout << "Suma wartosci z wiersza " << row << " wynosi: " << this->table->sumByRow(row - 1);
	}

	void Menu::najwieszaWartoscMenu()
	{
		int value = this->table->getTheBiggestValue();
		if (value != NULL)
			std::cout << "Najwiesza wartosc w arkuszu wynosi: " << value;
		else
			std::cout << "Nie znaleziono zadnych wartosci.";
	}

	void Menu::najmniejszaWartoscMenu()
	{
		int value = this->table->getTheSmallestValue();
		if (value != NULL)
			std::cout << "Najmniejsza wartosc w arkuszu wynosi: " << value;
		else
			std::cout << "Nie znaleziono zadnych wartosci.";
	}

	void Menu::sredniaWartoscMenu()
	{
		int value = this->table->getAvgValue();
		if (value != NULL)
			std::cout << "Srednia wartosc w arkuszu wynosi: " << value;
		else
			std::cout << "Nie znaleziono zadnych wartosci.";
	}

	void Menu::zmienTypTabeli() {
		int typ = 0;
		do {
			std::cout << "Dostepne typy tabeli: 0=TEXT, 1=NUMBER:";
			std::cin >> typ;
		} while (typ != 0 && typ != 1);

		CellType t = CellType(typ);
		std::cout << "Zmieniono typ tabeli na: " << t;
		this->table->setTabelType(t);
	}

	void Menu::uruchom() {
		bool dziala = true;
		while (dziala) {
			wyswietlMenu();

			int polecenie;

			do {
				std::cin >> polecenie;
			} while (polecenie < 1 || polecenie > 10);

			switch (polecenie) {
			case 1:
				zmienWielkoscMenu();
				break;
			case 2:
				zmienLinieMenu();
				break;
			case 3:
				this->viewer->view(this->table);
				break;
			case 4:
				sumaKolumnyMenu();
				break;
			case 5:
				sumaWierszaMenu();
				break;
			case 6:
				najwieszaWartoscMenu();
				break;
			case 7:
				najmniejszaWartoscMenu();
				break;
			case 8:
				sredniaWartoscMenu();
				break;
			case 9:
				dziala = false;
			case 10:
				zmienTypTabeli();
			default:
				break;
			}
		}
	}