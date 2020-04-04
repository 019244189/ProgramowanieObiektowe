#include <iostream>
#include <string>
#include "tablica.cpp"
#include "tablica_wysw.cpp"

static void wyswietlMenu(std::ostream& cout) {
	cout << "----------------------------" << std::endl;
	cout << "Dostepne opcje:" << std::endl;
	cout << "1. Zmien wielkosc tablicy." << std::endl;
	cout << "2. Edytuj dana linie tablicy." << std::endl;
	cout << "3. Wyswietl tablice." << std::endl;
	cout << "4. Wyjdz z programu." << std::endl;
	cout << "----------------------------" << std::endl << std::endl;

	cout << "Wpisz nr polecenia: ";
}

static void zmienWielkoscMenu(std::ostream& cout, std::istream& cin) {
	int w;
	do {
		cout << "Wpisz wielkosc tablicy: ";
		cin >> w;
	} while (w <= 0);
	zmienWielkoscTablicy(w);
	cout << "Zmieniono wielkosc tablicy na " << w;
}

static void zmienLinieMenu(std::ostream& cout, std::istream& cin) {
	int nr;
	do {
		cout << "Wpisz nr linii: ";
		cin >> nr;
	} while (nr <= 0 || nr > wielkoscTablicy);

	cout << "Wpisz tekst ktory chcesz umiescic w linii nr " << nr << ": ";
	std::string tekst;

	std::cin.ignore();
	std::getline(std::cin, tekst);
	
	zmienZawartoscLinii(nr, tekst);
	cout << "Zmieniono zawartosc lini nr " << nr << " na: " << tekst;
}

static void uruchom(std::ostream& cout, std::istream& cin) {
	bool dziala = true;
	while (dziala) {
		wyswietlMenu(cout);

		int polecenie;

		do {
			cin >> polecenie;
		} while (polecenie != 1 && polecenie != 2 && polecenie != 3 && polecenie != 4);

		switch (polecenie) {
		case 1:
			zmienWielkoscMenu(cout, cin);
			break;
		case 2:
			zmienLinieMenu(cout, cin);
			break;
		case 3:
			wyswietlTablice(cout, tablica, wielkoscTablicy);
			break;
		case 4:
			dziala = false;
		default:
			break;
		}

		cout << std::endl << std::endl;
	}
}