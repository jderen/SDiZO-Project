/*
 * TestowaniePojedyncze.h
 *
 *  Created on: 15 kwi 2018
 *      Author: kuba
 */

#ifndef TESTOWANIEPOJEDYNCZE_H_
#define TESTOWANIEPOJEDYNCZE_H_

#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"

class TestowaniePojedyncze {
public:
	void testowanieTablicy(Tablica tablica);
	void testowanieListy(Lista lista);
	void testowanieKopca(Kopiec kopiec);
	void testowanieDrzewa(Drzewo drzewo);
};

#endif /* TESTOWANIEPOJEDYNCZE_H_ */
