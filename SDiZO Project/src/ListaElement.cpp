#include "ListaElement.h"

ListaElement::ListaElement(int wartosc, ListaElement *poprzedni,
		ListaElement *nastepny) {
	ListaElement::wartosc = wartosc;
	ListaElement::poprz = poprzedni;
	ListaElement::nast = nastepny;

}

ListaElement::~ListaElement() {
	// TODO Auto-generated destructor stub
}

ListaElement::ListaElement(){

}
