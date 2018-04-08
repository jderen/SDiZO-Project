
#ifndef LISTAELEMENT_H_
#define LISTAELEMENT_H_

class ListaElement {
public:
	ListaElement *poprz;			//poprzedni element
	ListaElement *nast;				//nastepny element
	int wartosc;


	ListaElement(int wartosc, ListaElement *poprzedni, ListaElement *nastepny);
	virtual ~ListaElement();

};

#endif /* LISTAELEMENT_H_ */
