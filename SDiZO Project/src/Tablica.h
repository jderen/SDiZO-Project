/*
 * Tablica.h
 *
 *  Created on: 7 kwi 2018
 *      Author: kuba
 */

#ifndef TABLICA_H_
#define TABLICA_H_

class Tablica {
public:

	int *head;					//wskaznik na glowe
	int rozmiar;				//rozmiar tablicy
	Tablica();
	~Tablica();

	void dodajPoczatek(int wartosc);
	void dodajKoniec(int wartosc);
	void dodajGdzies(int wartosc, int miejsce);

	void usunPoczatek();
	void usunKoniec();
	void usunGdzies(int miejsce);

	bool czyIstnieje(int wartosc);
	void wyswietlTablice();


};

#endif /* TABLICA_H_ */