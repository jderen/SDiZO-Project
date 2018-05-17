#ifndef TABLICA_H_
#define TABLICA_H_

class Tablica {
public:

	int *head;					//wskaznik na glowe
	int rozmiar;				//rozmiar tablicy

	Tablica();
	~Tablica();

	void dodajPoczatek(int wartosc);
	void dodajGdzies(int wartosc, int miejsce);
	void dodajKoniec(int wartosc);

	void usunPoczatek();
	void usunGdzies(int miejsce);
	void usunKoniec();

	bool czyIstnieje(int wartosc);
	void wyswietlTablice();

	void wypelnij(int tablica[], int rozmiar2);
};

#endif /* TABLICA_H_ */
