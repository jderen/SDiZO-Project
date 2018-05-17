#include <iostream>
#include <cstdlib>
#include "TestowaniePojedyncze.h"
#include "Generator.h"
#include "Testowanie.h"
#include "ZapisanieRezultatow.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

	TestowaniePojedyncze testowaniePojedyncze;
	Generator generator;
	Testowanie testowanie;
	ZapisanieRezultatow plikRezultaty;

	int wybor = 0;
	int rozmiar = 0;

	plikRezultaty.usunPlik();				//czyszczenie pliku z Rezultatami
	cout << "Generowanie pliku z losowymi liczbami:\n";
	cout << "Wybierz rozmiar pliku:";
	cin >> rozmiar;

	generator.stworzPlik(rozmiar);

	cout << "Wybierz strukture do sprawdzenia:\n" << "1.Tablica\n"
			<< "2.Lista\n" << "3.Kopiec\n" << "4.Drzewo\n";
	cin >> wybor;
	switch (wybor) {
	case 1:
		cout << "Test tablicy";
		testowanie.testowanieTablicy(rozmiar);
		break;
	case 2:
		cout << "Test listy";
		testowanie.testowanieListy();
		break;
	case 3:
		testowanie.testowanieKopca();
		break;
	case 4:
		testowanie.testowanieDrzewa();
		break;
	default:
		cout << "Zly numer";
		break;
	}
	return 0;
}
