#include "Tablica.h"
#include <iostream>

using namespace std;

Tablica::Tablica() {

	Tablica::head = NULL;
	Tablica::rozmiar = 0;

}

Tablica::~Tablica() {

	if (head) {
		delete[] head;
	}
}

void Tablica::wypelnij(int tablica[], int rozmiar2) {
	delete head;
	head = tablica;
	rozmiar = rozmiar2;
}

void Tablica::dodajPoczatek(int wartosc) {

	int *nowyHead = new int[rozmiar + 1];			//nowa tablica o 1 większa
	nowyHead[0] = wartosc;//podana wartość zostaje pierwsza wartością w nowej tablicy

	for (int i = 0; i < rozmiar; i++) {			//przepisanie wartości do nowej

		nowyHead[i + 1] = head[i];

	}

	delete head;						//zwolnienie pamięci poprzedniej tablicy
	head = nowyHead;						//nowy wskaznik na poczatek tablicy

	rozmiar++;								//powiekszenie rozmiaru tablicy o 1
}

void Tablica::dodajGdzies(int wartosc, int miejsce) {

	if (miejsce > rozmiar || miejsce < 0) {	//sprawdzenie czy poprawnie podane miejsce
		cout << "Nie ma takiego miejsca w tablicy";
	} else {
		int *nowyHead = new int[rozmiar + 1];		//nowa tablica o 1 większa
		nowyHead[miejsce] = wartosc;//podana wartość zostaje wpisana do nowej tablicy
		for (int i = 0; i < miejsce; i++) {
			nowyHead[i] = head[i];//przepisanie do nowej tablicy do wybranego miejsca
		}
		for (int i = miejsce; i < rozmiar; i++) {//przepisanie do nowej od wybranej pozycji
			nowyHead[i + 1] = head[i];
		}
		delete head;
		head = nowyHead;
		rozmiar++;

	}
}

void Tablica::dodajKoniec(int wartosc) {		//to nie jestem pewny czy dobrze

	int *nowyHead = new int[rozmiar + 1];					//nowa tablica
	nowyHead[rozmiar] = wartosc;						//przypisanie na koniec

	for (int i = 0; i < rozmiar; i++) {	//przepisanie wartosci do nowej tablicy
		nowyHead[i] = head[i];
	}

	delete head;
	head = nowyHead;
	rozmiar++;
}

void Tablica::usunPoczatek() {

	if (rozmiar > 0) {					//sprawdzenie czy tablica nie jest pusta

		int *nowyHead = new int[rozmiar - 1];		//nowa tablica o 1 mniejsza
		for (int i = 0; i < rozmiar - 1; i++) {	//przepisanie wartosci starej tablicy do nowej oprocz pierwszego
			nowyHead[i] = head[i + 1];
		}

		delete[] head;
		head = nowyHead;
		rozmiar--;
	} else {
		cout << "Brak wartości w tablicy";
	}
}

void Tablica::usunGdzies(int miejsce) {

	if (rozmiar>0||miejsce>0||miejsce<rozmiar) {//sprawdzenie czy pusta i czy prawidlowe miejsce
		int *nowyHead = new int[rozmiar - 1];

		for (int i = 0; i < miejsce; i++) {	//przepisanie do wybranego miejsca
			nowyHead[i] = head[i];
		}

		for (int i = miejsce; i < rozmiar - 1; i++) {//przepisanie od wybranego miejsca

			nowyHead[i] = head[i + 1];

		}
		delete head;
		head = nowyHead;
		rozmiar--;

	} else {
		cout << "Brak takiego miejsca w tablicy \n";
	}

}

void Tablica::usunKoniec() {

	if (rozmiar > 0) {									//sprawdzenie czy pusta

		int *nowyHead = new int[rozmiar - 1];

		for (int i = 0; i < rozmiar - 1; i++) {
			nowyHead[i] = head[i];
		}
		delete[] head;
		head = nowyHead;
		rozmiar--;
	} else {
		cout << "Tablica jest pusta \n";
	}
}

bool Tablica::czyIstnieje(int wartosc) {

	for (int i = 0; i < rozmiar; i++) {
		if (head[i] == wartosc) {
			cout << "Podana wartość jest w tablicy na miejscu[" << i << "]"
					<< "\n";	//jezeli wartosc jest w tablicy zwracamy true
			return true;
		}
	}
	cout << "Podanej wartości nie ma w tablicy \n";
	return false;

}

void Tablica::wyswietlTablice() {

	if (head) {
		for (int i = 0; i < rozmiar; i++) {
			cout << "[" << i << "] " << head[i] << "\n";
		}

	} else {
		cout << "Tablica jest pusta \n";
	}

}
