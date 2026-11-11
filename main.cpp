#include "Bank.hpp"
#include "Konto.hpp"
#include "KontoOszczednosciowe.hpp"
#include "KontoFirmowe.hpp"
#include <iostream>
using namespace std;

int main() 
{
    Bank mojBank(10);
    Konto* k1 = new Konto("1001", 1000.0, "Jan Kowalski");
    KontoOszczednosciowe* k2 = new KontoOszczednosciowe("2001", 5000.0, "Anna Nowak", 5.0);
    Konto* k3 = new KontoFirmowe("3001", 2000.0, "wessby", 10.0);



    mojBank.dodajKonto(k1);
    mojBank.dodajKonto(k2);
    mojBank.dodajKonto(k3);


    cout << "Stan poczatkowy kont:\n";
    mojBank.wyswietlWszystkieKonta();
    cout << "\nOperacje na kontach:\n";
    k1->wyplac(200.0);
    k2->naliczOdsetki();
    k3->wyplac(500.0);
    cout << "\nStan kont po operacjach:\n";
    mojBank.wyswietlWszystkieKonta();
    return 0;
}