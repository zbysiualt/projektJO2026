#include "KontoFirmowe.hpp"
#include <iostream>
using namespace std;

KontoFirmowe::KontoFirmowe() 
    : Konto(), prowizja(0.0) {}
KontoFirmowe::KontoFirmowe(string numer, double poczatkoweSaldo, string dane, double prow)
    : Konto(numer, poczatkoweSaldo, dane), prowizja(prow) {}



void KontoFirmowe::wyplac(double kwota) 
{
    if (kwota <= 0) 
    {
        throw NieprawidlowaKwotaException();
    }
    double calkowityKoszt = kwota+prowizja;
    if (calkowityKoszt > saldo) 
    {
        throw BrakSrodkowException();
    }
    saldo -= calkowityKoszt;
    dodajTransakcje("WYPLATA Z PROWIZJA", calkowityKoszt);
}

void KontoFirmowe::wypiszInformacje() const 
{
    cout << "[FIRMOWE] Konto: " << numerKonta 
         << " | Wlasciciel: " << wlasciciel 
         << " | Saldo: "<<saldo 
         << " | Prowizja za przelew:" << prowizja << " PLN\n";
}