#ifndef DRZEWO_H_
#define DRZEWO_H_

#include "DrzewoElement.h"
#include <iostream>
using namespace std;

class Drzewo {
public:
	int rozmiar;
	DrzewoElement *korzen;
	DrzewoElement straznik;
	string cr,cl,cp;

	Drzewo();
	~Drzewo();

	void dodaj(int wartosc);
	void usun(int wartosc);
	void usunDrzewo();
	void usunElement(DrzewoElement *element);
	bool czyIstnieje(int wartosc);
	//void wyswietlDrzewo();
	void wyszukajElement(int wartosc, DrzewoElement *korzenElementu,
			DrzewoElement *&szukany);
	void wyszukajWartosc(int wartosc, DrzewoElement* korzenElementu,
			bool &wyszukany);
	DrzewoElement *wyszukajNastepnyElement(DrzewoElement *element);
	DrzewoElement *wyszukajNajmniejszyElementDrzewa(DrzewoElement *p);

	void rotacjaWPrawo(DrzewoElement *element);
	void rotacjaWLewo(DrzewoElement *element);

	//string wyswietlDrzewo();
	//string wyswietlDrzewoKontynuuj(string wynik, DrzewoElement *p);

	void wyswietlDrzewo(string sp, string sn, DrzewoElement* v);
};

#endif /* DRZEWO_H_ */
