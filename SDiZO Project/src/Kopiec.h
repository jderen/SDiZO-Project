

#ifndef KOPIEC_H_
#define KOPIEC_H_

class Kopiec {
public:

	int *zbior;
	int rozmiar;

	Kopiec();
	~Kopiec();

	void dodaj(int wartosc);
	void usun(int wartosc);
	bool czyIstnieje(int wartosc);
	void wyswietlKopiec();
	void uporzadkuj();
};

#endif /* KOPIEC_H_ */
