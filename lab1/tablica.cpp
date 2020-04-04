#include <iostream>
#include <string>

static int wielkoscTablicy = 1;
static std::string *tablica = new std::string[wielkoscTablicy];

static void zmienWielkoscTablicy(int wielkosc) {
	std::string* temp = new std::string[wielkosc];
	
	for (int i = 0; i < (wielkoscTablicy > wielkosc ? wielkosc : wielkoscTablicy); i++) {
		temp[i] = tablica[i];
	}

	delete [] tablica;
	tablica = temp;
	wielkoscTablicy = wielkosc;
}

static void zmienZawartoscLinii(int nr, std::string wartosc) {
	tablica[nr - 1] = wartosc;
}