

#ifndef LISTA_H_
#define LISTA_H_

#include "ListaElement.h"
#include <iostream>


class Lista {
public:

	int rozmiar;
	ListaElement *poczatek;
	ListaElement *obecny;
	ListaElement *koniec;

	Lista();
	virtual ~Lista();

	void dodajPoczatek(int wartosc);
	void dodajGdzies(int wartosc, int miejsce);
	void dodajKoniec(int wartosc);
	void usunPoczatek();
	void usunGdzies(int miejsce);
	void usunKoniec();
	bool czyIstnieje(int wartosc);
	void wyswietlListe();



};

#endif /* LISTA_H_ */
