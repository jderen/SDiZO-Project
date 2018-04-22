#include "Testowanie.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"
#include "TestowaniePojedyncze.h"
#include "ZapisanieRezultatow.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;


void Testowanie::testowanieTablicy(int rozmiar){
    Tablica tablica;										//otwarcie tablicy i zapisanie wartosci do tablicy
    TestowaniePojedyncze testowaniePojedyncze;
    ZapisanieRezultatow plikRezultaty;

    int linia;
    ifstream plik;
    plik.open("Losowe.txt");
    if(plik.is_open()){										//przeczytanie wartosci i dodanie ich do tabeli

        int *newTablica=new int[rozmiar];					//zainicjalizowanie tabeli o rozmiarze wybranym
        int index=0;

        auto start = std::chrono::system_clock::now();
        while(plik>>linia){
//            table.addTail(line);
            newTablica[index]=linia;
            index++;
        }
        tablica.wypelnij(newTablica,rozmiar);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> fp_ms = end - start;
        cout<<"\nCzas dodawania elementow do tablicy:"<<fp_ms.count()<<"ms";
//        resultFile.deleteFile();
        plikRezultaty.zapiszDoPliku(fp_ms.count());		//dodanie nowych rezultatow
        plik.close();
    }
    else{
        cout<<"Nie mozna otworzyc i przeczytac";
    }
    testowaniePojedyncze.testowanieTablicy(tablica);

}
void Testowanie::testowanieListy(){
    Lista lista;										//otwarcie kopca i zapisanie wartosci do tablicy
    TestowaniePojedyncze testowaniePojedyncze;
    ZapisanieRezultatow plikRezultaty;

    int linia;
    ifstream plik;
    plik.open("Losowe.txt");
    if(plik.is_open()){										//przeczytanie wartosci i dodanie ich do tabeli

        auto start = std::chrono::system_clock::now();
        while(plik>>linia){
        	lista.dodajKoniec(linia);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> fp_ms = end - start;
        cout<<"\nCzas dodawania elementow do listy:"<<fp_ms.count()<<"ms";
//        resultFile.deleteFile();
        plikRezultaty.zapiszDoPliku(fp_ms.count());		//dodanie nowych rezultatow
        plik.close();
    }
    else{
        cout<<"Nie mozna otworzyc i przeczytac";
    }
    testowaniePojedyncze.testowanieListy(lista);


}
void Testowanie::testowanieKopca(){

    Kopiec kopiec;										//otwarcie kopca i zapisanie wartosci do tablicy
    TestowaniePojedyncze testowaniePojedyncze;
    ZapisanieRezultatow plikRezultaty;

    int linia;
    ifstream plik;
    plik.open("Losowe.txt");
    if(plik.is_open()){										//przeczytanie wartosci i dodanie ich do tabeli

        auto start = std::chrono::system_clock::now();
        while(plik>>linia){
        	kopiec.dodaj(linia);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> fp_ms = end - start;
        cout<<"\nCzas dodawania elementow do kopca:"<<fp_ms.count()<<"ms";
//        resultFile.deleteFile();
        plikRezultaty.zapiszDoPliku(fp_ms.count());		//dodanie nowych rezultatow
        plik.close();
    }
    else{
        cout<<"Nie mozna otworzyc i przeczytac";
    }
    testowaniePojedyncze.testowanieKopca(kopiec);

}

void Testowanie::testowanieDrzewa(){
	Drzewo drzewo;
	TestowaniePojedyncze testowaniePojedyncze;
	ZapisanieRezultatow plikRezultaty;

	int linia;
	ifstream plik;
	plik.open("Losowe.txt");
	if(plik.is_open()){
		auto start=std::chrono::system_clock::now();
		while(plik>>linia){
			drzewo.dodaj(linia);
		}
		auto end=std::chrono::system_clock::now();
		std::chrono::duration<double,std::milli>fp_ms=end-start;
		cout<<"\nCzas dodawania elementow do drzewa:"<<fp_ms.count()<<"ms";
		plikRezultaty.zapiszDoPliku(fp_ms.count());
		plik.close();
	}
	else{
		cout<<"Nie mozna otworzyc i przeczytac";
	}
	testowaniePojedyncze.testowanieDrzewa(drzewo);
}

