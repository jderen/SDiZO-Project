
#include "Kopiec.h"
//#include <iostream>
//#include <string>

using namespace std;

Kopiec::Kopiec() {
	Kopiec::zbior = NULL;
	Kopiec::rozmiar = 0;
}

Kopiec::~Kopiec() {
	if (Kopiec::rozmiar > 0) {
		delete[] zbior;
	}
}

bool Kopiec::czyIstnieje(int wartosc) {

	for (int i = 0; i < rozmiar; i++) {
		if (zbior[i] == wartosc) {
			cout << "Podana wartość jest w zbiorze kopca na miejscu[" << i
					<< "]" << endl;
			return true;
		}
	}
	cout << "Brak szukanej wartosci \n";
	return false;
}

void Kopiec::uporzadkuj() {
	int pomocnicza = 0;						//zmienna do sortowania

	for (int i = rozmiar; i > 0; i--) {	//ukladamy wartosci kopca w odpowiedniej kolejnosci
		if (zbior[i - 1] < zbior[i]) {
			pomocnicza = zbior[i - 1];
			zbior[i - 1] = zbior[i];
			zbior[i] = pomocnicza;
		}
	}
}

void Kopiec::dodaj(int wartosc) {
	if (!Kopiec::czyIstnieje(wartosc)) {//jezeli wartosc nie istnieje jeszcze w kopcu to dodaj
		int *nowyZbior = new int[rozmiar + 1];

		for (int i = 0; i < rozmiar; i++) {	//przepisanie wartosci do nowego zbioru
			nowyZbior[i] = zbior[i];
		}
		nowyZbior[rozmiar] = wartosc;				//dodanie wartosci do kopca
		delete[] zbior;
		zbior = nowyZbior;
		Kopiec::uporzadkuj();	//wartosci musza byc w dobrej kolejnosci w kopcu
		rozmiar++;
	}
}

void Kopiec::usun(int wartosc) {

	int *newTable=new int[rozmiar-1];
	    int valueIndex=-1;

	
	    for(int i=0;i<rozmiar;i++){
	        if(zbior[i]==wartosc){
	            valueIndex=i;
	        }
	
	        if(valueIndex==-1){
	            newTable[i]=zbior[i];
	        }

	        if(i>=valueIndex && valueIndex!=-1){
	            newTable[i]=zbior[i+1];
	        }
	    }

	   
	    delete zbior;
	    zbior=newTable;

	    if(valueIndex!=-1){
	      rozmiar--;
	    }

	  
	this->uporzadkuj();
}


void Kopiec::wyswietlKopiec() {
	if (zbior) {						//jesli sa elementy w kopcu to wyswietl
		for (int i = 0; i < rozmiar; i++) {
			cout << "Element [" << i << "] " << zbior[i] << "\n";
		}
	} else {
		cout << "Kopiec jest pusty";
	}
}
//algorytmy Tarnów
void Kopiec::wyswietl(string sp, string sn, int v) {
	string cl, cr, cp;
	cr = cl = cp = "  ";
	cr[0] = 218;
	cr[1] = 196;
	cl[0] = 192;
	cl[1] = 196;
	cp[0] = 179;
	string s;

	if (v < rozmiar) {
		s = sp;
		if (sn == cr)s[s.length() - 2] = ' ';
		wyswietl(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << zbior[v] << endl;

		s = sp;
		if (sn == cl)s[s.length() - 2] = ' ';
		wyswietl(s + cp, cl, 2 * v + 1);
	}
}

