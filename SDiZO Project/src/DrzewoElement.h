

#ifndef DRZEWOELEMENT_H_
#define DRZEWOELEMENT_H_

class DrzewoElement {
public:
	int wartosc;
	char kolor;
	DrzewoElement *lewo;
	DrzewoElement *prawo;
	DrzewoElement *rodzic;

	DrzewoElement();
	~DrzewoElement();
};

#endif /* DRZEWOELEMENT_H_ */
