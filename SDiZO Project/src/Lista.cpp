
#include "Lista.h"
#include "ListaElement.h"
using namespace std;

Lista::Lista() {
	Lista::rozmiar = 0;
	Lista::poczatek = NULL;
	Lista::obecny = NULL;
	Lista::koniec = NULL;

}

Lista::~Lista() {
	for (int i = 0; i < Lista::rozmiar; i++) {
		obecny = poczatek->nast;//przypisanie nastepnego elementu zeby usunac poczatek
		delete poczatek;
		poczatek = obecny;					//obecny element zostaje pierwszym
	}
}

void Lista::dodajPoczatek(int wartosc) {
	if (poczatek) {
		obecny = poczatek;				//ustawiamy wskaznik na pierwszy element
		poczatek = new ListaElement(wartosc, NULL, obecny);	//tworzymy poczatkowy element
		obecny->poprz = poczatek;	//poprzedni poczatek staje drugim elementem

	} else {
		poczatek = new ListaElement(wartosc, NULL, NULL);//mamy jeden element wiec ustawiamy go jako poczatek i koniec
		koniec = poczatek;
	}
	rozmiar++;
}
void Lista::dodajGdzies(int wartosc, int miejsce) {
	if(miejsce<0 || miejsce>rozmiar){
	        cout<<"nieprawidlowe miejsce";
	    }
	    else{
	        ListaElement *temp=new ListaElement;
	        ListaElement *current=new ListaElement;

	        temp->wartosc=wartosc;


	        current=poczatek;
	
	        for(int i=1;i<miejsce;i++){
	            current=current->nast;
	        }

	        temp->nast=current->nast;
	        current->nast=temp;
	        rozmiar++;
	}
}

void Lista::dodajKoniec(int wartosc) {
	if (poczatek) {							//jesli mamy juz jakis element listy
		obecny = koniec;
		koniec = new ListaElement(wartosc, obecny, NULL);
		obecny->nast = koniec;

	} else {				//jesli nie mamy jeszcze zadnych elementow w liscie
		koniec = new ListaElement(wartosc, NULL, NULL);
		poczatek = koniec;
	}
	rozmiar++;
}

void Lista::usunPoczatek() {
	obecny = poczatek->nast;//ustawiamy na element po poczatku zeby usunac poczatek
	delete poczatek;

	if (rozmiar > 1) {//jesli mamy wiecej elementow niz jeden to ustawiamy nowy poczatek
		obecny->poprz = NULL;
		poczatek = obecny;
	} else {									//jesli nie to zerujemy listę
		poczatek = NULL;
		obecny = NULL;
		koniec = NULL;
	}
	rozmiar--;									//dekrementujemy rozmiar listy
}

void Lista::usunGdzies(int miejsce) {

	  if(miejsce<0 || miejsce>=rozmiar){
	        cout<<"nieprawidlowe miejsce";
	    }

	    if(miejsce==0 && poczatek->nast ==nullptr){
	        delete poczatek;
	        poczatek=nullptr;
	        koniec=nullptr;
	        rozmiar--;

	    }
	//
	    else if(miejsce==0 && poczatek->nast!=nullptr){

	        this->usunPoczatek();

	    }
	    else{
	        ListaElement *before=new ListaElement();
	        ListaElement *current=new ListaElement();

	        current=poczatek;
	        for(int i=1;i<=miejsce;i++){
	            before = current;
	            current=before->nast;
	        }
	        before->nast=current->nast;
	        delete current;
	        rozmiar--;

	}
}


void Lista::usunKoniec() {
	obecny = koniec->poprz;					//ustawiamy na przedostatni element
	delete koniec;

	if (rozmiar > 1) {//jezeli mamy wiecej niz jeden element to ustawiamy przedostatni el jako ostatni
		obecny->nast = NULL;
		koniec = obecny;
	} else {								//w przeciwnym razie zerujemy liste
		poczatek = NULL;
		obecny = NULL;
		koniec = NULL;
	}
	rozmiar--;
}
bool Lista::czyIstnieje(int wartosc) {
	if (!rozmiar) {					//jesli w liscie nie ma elementow to false
		return false;
	}
	obecny = poczatek;
	for (int i = 0; i < rozmiar; i++) {
		if (obecny->wartosc == wartosc) {	//jesli znajdziemy to zwracamy true
			cout << "Podana wartość jest na liscie na miejscu[" << i << "]"
					<< "\n";
			return true;
		}
		obecny = obecny->nast;		//przesuwamy wskaznik na nastepny element
	}
	cout << "Brak takiej wartosci" << endl;
	return false;
}
void Lista::wyswietlListe() {
	obecny = poczatek;								//wyswietlamy od poczatku

	for (int i = 0; i < rozmiar; i++) {
		cout << "[" << i << "] " << obecny->wartosc << "\n";
		obecny = obecny->nast;				//przesuwamy wskaznik na nastepny
	}
}
