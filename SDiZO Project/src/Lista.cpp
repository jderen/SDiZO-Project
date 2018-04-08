

#include "Lista.h"
using namespace std;

Lista::Lista() {
	Lista::rozmiar=0;
	Lista::poczatek=NULL;
	Lista::obecny=NULL;
	Lista::koniec=NULL;

}

Lista::~Lista() {
	for(int i=0;i<Lista::rozmiar;i++){
		obecny=poczatek->nast;					//przypisanie nastepnego elementu zeby usunac poczatek
		delete poczatek;
		poczatek=obecny;						//obecny element zostaje pierwszym
	}
}


void Lista::dodajPoczatek(int wartosc){
	if(poczatek){
		obecny=poczatek;										//ustawiamy wskaznik na pierwszy element
		poczatek=new ListaElement(wartosc,NULL,obecny);			//tworzymy poczatkowy element
		obecny->poprz=poczatek;									//poprzedni poczatek staje drugim elementem

	}
	else{
		poczatek=new ListaElement(wartosc,NULL,NULL);			//mamy jeden element wiec ustawiamy go jako poczatek i koniec
		koniec=poczatek;
	}
	rozmiar++;
}
void Lista::dodajGdzies(int wartosc,int miejsce){
	if(miejsce==0){										//jesli dodajemy na poczatek to wywolujemy odpowiednia funkcje
		Lista::dodajPoczatek(wartosc);
		return;
	}
	if(miejsce==rozmiar-1){								//jesli dodajemy na koniec to wywolujemy funkcje dodajKoniec
		Lista::dodajKoniec(wartosc);
		return;
	}
	if(miejsce>rozmiar||miejsce<0){						//sprawdzenie czy miejsce zawiera sie w liscie
		cout<<"Błędnie podane miejsce";
		return;
	}
	if(miejsce<rozmiar/2){								//jesli miejsce jest w pierwszej polowie zaczynamy od poczatku
		obecny=poczatek;
		for(int i=1;i<miejsce-1;++i){					//przesuwamy wszystkie elementy o jeden do przodu
			obecny=obecny->nast;
		}
	}
	else{
		obecny=koniec;									//w przeciwnym razie zaczynamy od konca
		for(int i=0;i<rozmiar-miejsce-1;++i){
			obecny=obecny->poprz;						//przesuwamy wszystkie poprzednie o jeden do tyłu
		}
	}
	ListaElement *dodany=new ListaElement(wartosc,obecny->nast,obecny);
	obecny->nast->poprz=dodany;												//ustawienie nowego elemetu
	obecny->nast=dodany;													//

	rozmiar++;
}


void Lista::dodajKoniec(int wartosc){
	if(poczatek){										//jesli mamy juz jakis element listy
		obecny=koniec;
		koniec=new ListaElement(wartosc, obecny,NULL);
		obecny->nast=koniec;

	}
	else{												//jesli nie mamy jeszcze zadnych elementow w liscie
		koniec=new ListaElement(wartosc,NULL,NULL);
		poczatek=koniec;
	}
	rozmiar++;
}

void Lista::usunPoczatek(){
	obecny=poczatek->nast;								//ustawiamy na element po poczatku zeby usunac poczatek
	delete poczatek;

	if(rozmiar>1){										//jesli mamy wiecej elementow niz jeden to ustawiamy nowy poczatek
		obecny->poprz=NULL;
		poczatek=obecny;
	}
	else{												//jesli nie to zerujemy listę
		poczatek=NULL;
		obecny=NULL;
		koniec=NULL;
	}
	rozmiar--;											//dekrementujemy rozmiar listy
}

void Lista::usunGdzies(int miejsce){

	if(miejsce==0){										//czy to pierwszy element
		usunPoczatek();
		return;
	}
	if(miejsce==rozmiar-1){								//czy to ostatni element
		usunKoniec();
		return;
	}
	if(miejsce>rozmiar||miejsce<0){						//sprawdzenie czy poprawnie podane miejsce
		cout<<"Blednie podane miejsce"<<endl;
	}
	if(miejsce<rozmiar/2){								//jesli w pierwszej polowie to zaczynamy od poczatku
		obecny=poczatek;

		for(int i=1;i<miejsce-1;++i){
			obecny=obecny->nast;						//przesuwamy wszystkie do miejsca o jeden do przodu
		}
	}
	else{												//jesli nie to zaczynamy od konca
		obecny=koniec;
		for(int i=0;i<rozmiar-miejsce-1;i++){			//przesuwamy wszystkie do miejsca o jeden do tylu
			obecny=obecny->poprz;
		}
	}

	ListaElement *dodany=obecny->nast;					//tworzzmy nowy ustawiajac na miejsce
	obecny->nast=dodany->nast;
	obecny->nast->poprz=dodany;
	delete[]dodany;
	rozmiar--;
}

void Lista::usunKoniec(){
	obecny=koniec->poprz;								//ustawiamy na przedostatni element
	delete koniec;

	if(rozmiar>1){										//jezeli mamy wiecej niz jeden element to ustawiamy przedostatni el jako ostatni
		obecny->nast=NULL;
		koniec=obecny;
	}
	else{												//w przeciwnym razie zerujemy liste
		poczatek=NULL;
		obecny=NULL;
		koniec=NULL;
	}
	rozmiar--;
}
bool Lista::czyIstnieje(int wartosc){
	if(!rozmiar){										//jesli w liscie nie ma elementow to false
		return false;
	}
	obecny=poczatek;
	for(int i=0;i<rozmiar;i++){
		if(obecny->wartosc==wartosc){					//jesli znajdziemy to zwracamy true
			cout<<"Podana wartość jest na liscie na miejscu["<<i<<"]"<<"\n";
			return true;
		}
		obecny=obecny->nast;							//przesuwamy wskaznik na nastepny element
	}
	cout<<"Brak takiej wartosci"<<endl;
	return false;
}
void Lista::wyswietlListe(){
	obecny=poczatek;									//wyswietlamy od poczatku

	for(int i=0;i<rozmiar;i++){
		cout<<"["<<i<<"] "<<obecny->wartosc<<"\n";
		obecny=obecny->nast;							//przesuwamy wskaznik na nastepny
	}
}
