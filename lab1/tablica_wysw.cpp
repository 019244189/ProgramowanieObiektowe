#include <iostream>
#include <string>

static void wyswietlTablice(std::ostream& cout, std::string tablica[], int wielkoscTablicy) {
	for (int i = 0; i < wielkoscTablicy; i++) {
		cout << (i + 1) << ". " << tablica[i] << std::endl;
	}
}