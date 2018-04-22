#include <iostream>
#include <chrono>


#ifndef MIERZENIECZASU_H_
#define MIERZENIECZASU_H_

using namespace std;
using namespace std::chrono;

class MierzenieCzasu{
public:
	high_resolution_clock::time_point poczatek;
	high_resolution_clock::time_point koniec;

	void startCzas();
	void stopCzas();
	long ileZajelo();
};

#endif /* MIERZENIECZASU_H_ */
