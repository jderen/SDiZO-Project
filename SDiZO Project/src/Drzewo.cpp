

#include "Drzewo.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Drzewo::Drzewo() {
	rozmiar=0;

	straznik.kolor='B';							//tworzenie straznika
	straznik.lewo=&straznik;
	straznik.prawo=&straznik;
	straznik.rodzic=&straznik;
	korzen=&straznik;

}

Drzewo::~Drzewo() {
	if(korzen){
		usunDrzewo();
	}
}

void Drzewo::rotacjaWLewo(DrzewoElement *element){

	DrzewoElement *y, *p;

	y=element->prawo;
	if(y!=&straznik){
		p=element->rodzic;
		element->prawo=y->lewo;
		if(element->prawo!=&straznik)
			element->prawo->rodzic=element;


		y->lewo=element;
		y->rodzic=p;
		element->rodzic=y;

		if(p!=&straznik){
			if(p->lewo==element)p->lewo=y;else p->prawo=y;
		}
		else korzen=y;

		}
	}

void Drzewo::rotacjaWPrawo(DrzewoElement *element){

	DrzewoElement *y, *p;

	y=element->lewo;
	if(y!=&straznik){
		p=element->rodzic;
		element->lewo=y->prawo;
		if(element->lewo!=&straznik)element->lewo->rodzic=element;

		y->prawo=element;
		y->rodzic=p;
		element->rodzic=y;

		if(p!=&straznik){
			if(p->lewo==element)p->lewo=y; else p->prawo=y;
		} else korzen=y;
	}
}

void Drzewo::wyszukajElement(int wartosc, DrzewoElement *korzenElementu,
			DrzewoElement *&szukany){
	if(korzenElementu!=&straznik){
		if(korzenElementu->wartosc==wartosc){
			szukany=korzenElementu;
			return;
		}
		wyszukajElement(wartosc, korzenElementu->lewo,szukany);
		wyszukajElement(wartosc, korzenElementu->prawo, szukany);
	}
}

DrzewoElement *Drzewo::wyszukajNastepnyElement(DrzewoElement *p){

	DrzewoElement *nastepnyElement;

	if(p!=&straznik){
		if(p->prawo!=&straznik)return wyszukajNajmniejszyElementDrzewa(p->prawo);
		else{
			nastepnyElement=p->rodzic;
			while((nastepnyElement!=&straznik)&&(p==nastepnyElement->prawo)){
				p=nastepnyElement;
				nastepnyElement=nastepnyElement->rodzic;
			}
				return nastepnyElement;
		}
	}
	return &straznik;
}

DrzewoElement *Drzewo::wyszukajNajmniejszyElementDrzewa(DrzewoElement *p){
	if(p!=&straznik)
		while(p->lewo!=&straznik)p=p->lewo;
	return p;
}


void Drzewo::dodaj(int wartosc){

	DrzewoElement *X, *Y;

	X=new DrzewoElement;						//tworzymy nowy węzeł dla drzewa
	X->wartosc=wartosc;
	X->rodzic=korzen;
	X->lewo=&straznik;
	X->prawo=&straznik;

	if(X->rodzic==&straznik){					//jeżeli rodzic jest straznikiem to X zostaje korzeniem
		korzen=X;
	}
	else{										//w przeciwnym razie zastępujemy liść
		while(true){							//szukamy który liść zastąpić przez X (prawy czy lewy)
			if(wartosc>X->rodzic->wartosc){		//w tej sytuacji X zastępuje prawy liść
				if(X->rodzic->prawo==&straznik){
					X->rodzic->prawo=X;
					break;
				}
				X->rodzic=X->rodzic->prawo;
			}
			else if(wartosc<X->rodzic->wartosc){
				if(X->rodzic->lewo==&straznik){
					X->rodzic->lewo=X;
					break;
				}
				X->rodzic=X->rodzic->lewo;
			}
			else{									//w przeciwnym razie występuje brak możliwości zastąpienia liścia
				delete X;
				return;
		}

	}

		X->kolor='R';								//Kolorujemy węzeł na czerwono
		while((X!=korzen)&&(X->rodzic->kolor=='R')){
			if(X->rodzic==X->rodzic->rodzic->lewo){
				Y=X->rodzic->rodzic->prawo;

				if(Y->kolor=='R'){					//przypadek pierwszy
					X->rodzic->kolor='B';
					Y->kolor='B';
					X->rodzic->rodzic->kolor='R';
					X=X->rodzic->rodzic;
					continue;
				}

				if(X==X->rodzic->prawo){			//przypadek drugi
					X=X->rodzic;
					rotacjaWLewo(X);
				}

				X->rodzic->kolor='B';
				X->rodzic->rodzic->kolor='R';
				rotacjaWPrawo(X->rodzic->rodzic);
				break;
			}
			else{									//teraz rozpatrujemy przypadki lustrzane
				Y=X->rodzic->rodzic->lewo;

				if(Y->kolor=='R'){					//przypadek pierwszy (lustrzany)
					X->rodzic->kolor='B';
					Y->kolor='B';
					X->rodzic->rodzic->kolor='R';
					X=X->rodzic->rodzic;
					continue;
				}

				if(X==X->rodzic->lewo){				//przypadek drugi (lustrzany)
					X=X->rodzic;
					rotacjaWPrawo(X);
				}

				X->rodzic->kolor='B';
				X->rodzic->rodzic->kolor='R';
				rotacjaWLewo(X->rodzic->rodzic);
				break;
			}
		}

		korzen->kolor='B';
		rozmiar++;									//zwiekszamy rozmiar drzewa o jeden
	}
}

void Drzewo::usun(int wartosc){

	DrzewoElement *elementDoUsuniecia;
	wyszukajElement(wartosc, korzen, elementDoUsuniecia);

	DrzewoElement *W, *Y, *Z;

	if((elementDoUsuniecia->lewo==&straznik)||(elementDoUsuniecia->prawo==&straznik)){
		Y=elementDoUsuniecia;
	}
	else{
		Y=wyszukajNastepnyElement(elementDoUsuniecia);
	}

	if(Y->lewo!=&straznik){
		Z=Y->lewo;
	}
	else{
		Z=Y->prawo;
	}

	Z->rodzic=Y->rodzic;

	if(Y->rodzic==&straznik){
		korzen=Z;
	}
	else if(Y==Y->rodzic->lewo){
		Y->rodzic->lewo=Z;
	}
	else{
		Y->rodzic->prawo=Z;
	}

	if(Y!=elementDoUsuniecia){
		elementDoUsuniecia->wartosc=Y->wartosc;
	}

	if(Y->kolor=='B')									//naprawiamy strukturę drzewa czerwono-czarnego
		while((Z!=korzen)&&(Z->kolor=='B'))
			if(Z==Z->rodzic->lewo){
				W=Z->rodzic->prawo;

				if(W->kolor=='R'){						//przypadek pierwszy
					W->kolor='B';
					Z->rodzic->kolor='R';
					rotacjaWLewo(Z->rodzic);
					W=Z->rodzic->prawo;
				}

				if((W->lewo->kolor=='B')&&(W->prawo->kolor=='B')){	//przypadek drugi
					W->kolor='R';
					Z=Z->rodzic;
					continue;
				}

				if(W->prawo->kolor=='B'){							//przypadek trzeci
					W->lewo->kolor='B';
					W->kolor='R';
					rotacjaWPrawo(W);
					W=Z->rodzic->prawo;
				}

				W->kolor=Z->rodzic->kolor;							//przypadek czwarty
				Z->rodzic->kolor='B';
				W->prawo->kolor='B';
				rotacjaWLewo(Z->rodzic);

				Z=korzen;											//koniec petli
			}
			else{													//rozpatrzymy przypadki lustrzane
				W=Z->rodzic->lewo;

				if(W->kolor=='R'){									//pierwszy przypadek (lustrzany)
					W->kolor='B';
					Z->rodzic->kolor='R';
					rotacjaWLewo(Z->rodzic);
					W=Z->rodzic->lewo;
				}

				if((W->lewo->kolor=='B')&&(W->prawo->kolor=='B')){	//drugi przypadek(lustrzany)
					W->kolor='R';
					Z=Z->rodzic;
					continue;
				}

				if(W->lewo->kolor=='B'){							//trzeci przypadek(lustrzany)
					W->prawo->kolor='B';
					W->kolor='R';
					rotacjaWLewo(W);
					W=Z->rodzic->lewo;
				}

				W->kolor=Z->rodzic->kolor;							//czwarty przypadek(lustrzany)
				Z->rodzic->kolor='B';
				W->lewo->kolor='B';
				rotacjaWPrawo(Z->rodzic);

				Z=korzen;											//koniec petli
			}

	Z->kolor='B';
	delete Y;
}

/*void Drzewo::wyswietlDrzewo(){

}*/

/*string Drzewo::wyswietlDrzewo(){
	string wynik;
	wynik=wynik+wyswietlDrzewoKontynuuj(wynik,korzen);
	return wynik;
}

string Drzewo::wyswietlDrzewoKontynuuj(string wynik, DrzewoElement *p){
	stringstream strumien;
	if(p){
		wynik=wyswietlDrzewoKontynuuj(wynik,p->lewo);
		strumien<<p->wartosc;
		wynik=wynik+""+strumien.str();
		wynik=wyswietlDrzewoKontynuuj(wynik, p->prawo);
	}
	return wynik;
}
*/

void Drzewo::wyswietlDrzewo(string sp, string sn, DrzewoElement *element){
	string cr = "  ";
		string cl = "  ";
		string cp = "  ";
		cr[0] = 218;
		cr[1] = 196;
		cl[0] = 192;
		cl[1] = 196;
		cp[0] = 179;
		 string t;

		  if(element!= &straznik)
		  {
		    t = sp;
		    if(sn == cr) t[t.length() - 2] = ' ';
		    wyswietlDrzewo(t+cp,cr,element->prawo);

		    t = t.substr(0,sp.length()-2);
		    cout << t << sn << element->kolor << ":" << element->wartosc << endl;

		    t = sp;
		    if(sn == cl) t[t.length() - 2] = ' ';
		    wyswietlDrzewo(t+cp,cl,element->lewo);
		  }

}

void Drzewo::wyszukajWartosc(int wartosc, DrzewoElement* korzenElementu,
			bool &wyszukany){

	if(korzenElementu!=&straznik){
		if(korzenElementu->wartosc==wartosc){
			wyszukany=true;
			return;
		}
		wyszukajWartosc(wartosc,korzenElementu->lewo, wyszukany);
		wyszukajWartosc(wartosc, korzenElementu->prawo, wyszukany);
	}
}

bool Drzewo::czyIstnieje(int wartosc){
	bool znaleziony=false;
	wyszukajWartosc(wartosc,korzen,znaleziony);

	if(znaleziony){
		cout<<wartosc<<"wystepuje w drzewie"<<endl;
		return true;
	}
	else{
		cout<<wartosc<<"nie wystepuje w drzewie"<<endl;
		return false;
	}
}

void Drzewo::usunElement(DrzewoElement *element){

	if(element!=&straznik){

		usunElement(element->lewo);
		usunElement(element->prawo);
		delete element;

		Drzewo::rozmiar--;									//dekrementacja rozmiaru drzewa
	}
	else{
		cout<<"Wybrany element nie jest straznikiem"<<endl;
	}
}

void Drzewo::usunDrzewo(){

	usunElement(korzen);

	straznik.kolor='B';								//inicjalizujemy straznika
	straznik.rodzic=&straznik;
	straznik.lewo=&straznik;
	straznik.prawo=&straznik;
	korzen=&straznik;

	Drzewo::rozmiar=0;
}
