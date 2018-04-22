/*
 * ZapisanieRezultatow.cpp
 *
 *  Created on: 22 kwi 2018
 *      Author: kuba
 */

#include "ZapisanieRezultatow.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

void ZapisanieRezultatow::zapiszDoPliku(double czas){
    ofstream plik;
    plik.open("Result.txt",ios_base::app);
    if(plik.is_open()){

        plik<<czas<<"\n";
        plik.close();
    }
    else{
        cout<<"Blad otwarcia/zapisu pliku";
    }

}
void ZapisanieRezultatow::usunPlik(){
    if( remove( "Result.txt" ) != 0 )
    cout<< "Blad w znalezieniu pliku\n";
  else
    cout<<  "\nPlik odnaleziony\n" ;
}
