#include "KontoFirmowe.hpp"
#include <iostream>
using namespace std;

KontoFirmowe::KontoFirmowe() 
    : Konto(), prowizja(0.0) {}
KontoFirmowe::KontoFirmowe(string numer, double poczatkoweSaldo, string dane, double prow)
    : Konto(numer, poczatkoweSaldo, dane), prowizja(prow) {}



bool KontoFirmowe::wyplac(double kwota) 
{
    double calkowityKoszt = kwota+prowizja;
    if (calkowityKoszt <= saldo) 
    {
        saldo -= calkowityKoszt;
        return true;
    }
    return false;
}

void KontoFirmowe::wypiszInformacje() const 
{
    cout << "[FIRMOWE] Konto: " << numerKonta 
         << " | Wlasciciel: " << wlasciciel 
         << " | Saldo: "<<saldo 
         << " | Prowizja za przelew:" << prowizja << " PLN\n";
}