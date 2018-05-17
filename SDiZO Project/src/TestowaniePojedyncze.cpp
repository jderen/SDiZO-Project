/*
 * TestowaniePojedyncze.cpp
 *
 *  Created on: 15 kwi 2018
 *      Author: kuba
 */

#include "TestowaniePojedyncze.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"
#include "ZapisanieRezultatow.h"
#include <iostream>
#include <chrono>

using namespace std;

void TestowaniePojedyncze::testowanieTablicy(Tablica tablica) {
	int wartosc = 0;
	int miejsce = 0;
	int wybor = 99;
	ZapisanieRezultatow plikRezultaty;

	while (wybor != 0) {
		cout << "Podaj liczbe funkcji z ktorej chcesz skorzystac" << endl;
		cout << "1.Dodanie na początek" << endl;
		cout << "2.Dodanie gdzieś" << endl;
		cout << "3.Dodanie na koniec" << endl;
		cout << "4.Usuniecie pierwszego" << endl;
		cout << "5.Usuniecie gdzies" << endl;
		cout << "6.Usun koniec" << endl;
		cout << "7.Wyswietlenie tablicy" << endl;
		cout << "8.Znalezienie elementu" << endl;
		cout << "0. Wyjscie" << endl;
		cin >> wybor;
		switch (wybor) {
		case 0: {
			break;
		}

		case 1: {
			cout << "Jaką wartość chcesz dodać? ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();
			tablica.dodajPoczatek(wartosc);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas dodawania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 2: {
			cout << "Jaką wartość chcesz dodać?: ";
			cin >> wartosc;
			cout << "Na jakim miejscu chcesz dodać?: ";
			cin >> miejsce;
			auto start = std::chrono::system_clock::now();
			tablica.dodajGdzies(wartosc, miejsce);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas dodawania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 3: {
			cout << "Jaką wartość chcesz dodać?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();

			tablica.dodajKoniec(wartosc);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas dodawania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 4: {
			auto start = std::chrono::system_clock::now();

			tablica.usunPoczatek();

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas usuwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 5: {
			cout << "Z której pozycji chcesz usunąć: ";
			cin >> miejsce;
			auto start = std::chrono::system_clock::now();

			tablica.usunGdzies(miejsce);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas usuwania" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 6: {
			auto start = std::chrono::system_clock::now();

			tablica.usunKoniec();

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas usuwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 7: {
			auto start = std::chrono::system_clock::now();

			tablica.wyswietlTablice();

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas wyswietlania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 8: {
			cout << "Jaką wartość chcesz znalezc?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();

			if (tablica.czyIstnieje(wartosc))
				cout << "Wartosc istnieje";
			else
				cout << "Nie ma tej wartosci w tablicy";

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas wyszukiwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());

			break;
		}
		default: {
			cout << "Podaj prawidlowy numer" << endl;
		}
		}

	}
}

void TestowaniePojedyncze::testowanieListy(Lista lista) {
	int wartosc = 0;
	int miejsce = 0;
	int wybor = 99;
	ZapisanieRezultatow plikRezultaty;

	while (wybor != 0) {
		cout << "Podaj liczbe funkcji z ktorej chcesz skorzystac" << endl;
		cout << "1.Dodanie na początek" << endl;
		cout << "2.Dodanie gdzieś" << endl;
		cout << "3.Dodanie na koniec" << endl;
		cout << "4.Usuniecie pierwszego" << endl;
		cout << "5.Usuniecie gdzies" << endl;
		cout << "6.Usun koniec" << endl;
		cout << "7.Wyswietlenie tablicy" << endl;
		cout << "8.Znalezienie elementu" << endl;
		cout << "0. Wyjscie" << endl;
		cin >> wybor;
		switch (wybor) {
		case 0: {
			break;
		}
		case 1: {
			cout << "Jaką wartość chcesz dodać? ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();

			lista.dodajPoczatek(wartosc);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas dodawania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 2: {
			cout << "Jaką wartość chcesz dodać?: ";
			cin >> wartosc;
			cout << "Na jakim miejscu chcesz dodać?: ";
			cin >> miejsce;
			auto start = std::chrono::system_clock::now();

			lista.dodajGdzies(wartosc, miejsce);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas dodawania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 3: {
			cout << "Jaką wartość chcesz dodać?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();

			lista.dodajKoniec(wartosc);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas dodawania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 4: {
			auto start = std::chrono::system_clock::now();

			lista.usunPoczatek();

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas usuwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());

			break;
		}
		case 5: {
			cout << "Z której pozycji chcesz usunąć: ";
			cin >> miejsce;
			auto start = std::chrono::system_clock::now();

			lista.usunGdzies(miejsce);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas usuwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 6: {
			auto start = std::chrono::system_clock::now();

			lista.usunKoniec();

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas usuwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 7: {
			auto start = std::chrono::system_clock::now();

			lista.wyswietlListe();

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas wyswietlania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 8: {
			cout << "Jaką wartość chcesz znalezc?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();
			if (lista.czyIstnieje(wartosc))
				cout << "\nWartosc istnieje\n";
			else
				cout << "\nWartosc nie wystepuje w liscie\n";
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas wyszukania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		default: {
			cout << "Podaj prawidlowa liczbe" << endl;
		}
		}

	}
}

void TestowaniePojedyncze::testowanieKopca(Kopiec kopiec) {
	int wartosc = 0;
	int index = 0;
	int wybor = 10;
	ZapisanieRezultatow plikRezultaty;
	while (wybor != 0) {
		cout << "Podaj liczbe funkcji z ktorej chcesz skorzystac" << endl;
		cout << "1.Dodanie" << endl;
		cout << "2.Usuniecie" << endl;
		cout << "3.Wyswietlenie" << endl;
		cout << "4.Wyszukanie" << endl;
		cout << "0. Wyjscie" << endl;
		cin >> wybor;
		switch (wybor) {
		case 0: {
			break;
		}
		case 1: {
			cout << "Jaka wartosc chcesz dodac?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();
			kopiec.dodaj(wartosc);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas dodawania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 2: {
			cout << "Jaka wartosc chcesz usunac?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();

			kopiec.usun(wartosc);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas usuwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());

			break;
		}
		case 3: {
			auto start = std::chrono::system_clock::now();

			kopiec.wyswietl("","",0);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas wyswietlania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());

			break;
		}
		case 4: {
			cout << "Jaka wartosc chcesz znalezc?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();
			if (kopiec.czyIstnieje(wartosc))
				cout << "\nWartosc istnieje\n";
			else
				cout << "\nWartosc nie istnieje w kopcu\n";
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas wyszukiwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());

			break;
		}
		default: {
			cout << "Podaj prawidlowa liczbe" << endl;
			break;
		}
		}

	}
}

void TestowaniePojedyncze::testowanieDrzewa(Drzewo drzewo) {
	int wartosc = 0;
	int index = 0;
	int wybor = 10;
	ZapisanieRezultatow plikRezultaty;
	while (wybor != 0) {
		cout << "Podaj liczbe funkcji z ktorej chcesz skorzystac" << endl;
		cout << "1.Dodanie" << endl;
		cout << "2.Usuniecie" << endl;
		cout << "3.Wyswietlenie" << endl;
		cout << "4.Wyszukanie" << endl;
		cout << "0. Wyjscie" << endl;
		cin >> wybor;
		switch (wybor) {
		case 0: {
			break;
		}
		case 1: {
			cout << "Jaka wartosc chcesz dodac?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();
			drzewo.dodaj(wartosc);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas dodawania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 2: {
			cout << "Jaka wartosc chcesz usunac?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();

			drzewo.usun(wartosc);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas usuwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());
			break;
		}
		case 3: {
			auto start = std::chrono::system_clock::now();

			drzewo.wyswietlDrzewo("", "", drzewo.korzen);

			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas wyswietlania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());

			break;
		}
		case 4: {
			cout << "Jaka wartosc chcesz znalezc?: ";
			cin >> wartosc;
			auto start = std::chrono::system_clock::now();
			if (drzewo.czyIstnieje(wartosc))
				cout << "\nWartosc istnieje\n";
			else
				cout << "\nWartosc nie istnieje w drzewie\n";
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = end - start;
			cout << "\nCzas wyszukiwania:" << fp_ms.count() << "ms";
			plikRezultaty.zapiszDoPliku(fp_ms.count());

			break;
		}
		default: {
			cout << "Podaj prawidlowa liczbe" << endl;
			break;
		}
		}

	}
}
