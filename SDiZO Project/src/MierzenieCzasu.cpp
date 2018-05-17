#include "MierzenieCzasu.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void MierzenieCzasu::startCzas() {
	poczatek = high_resolution_clock::now();
}
void MierzenieCzasu::stopCzas() {
	koniec = high_resolution_clock::now();
}
long MierzenieCzasu::ileZajelo() {
	return duration_cast<nanoseconds>(
			MierzenieCzasu::koniec - MierzenieCzasu::poczatek).count();
}
