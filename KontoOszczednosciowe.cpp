#include "KontoOszczednosciowe.hpp"
#include <iostream>
using namespace std;

KontoOszczednosciowe::KontoOszczednosciowe() 
    : Konto(), oprocentowanie(0.0) {}
KontoOszczednosciowe::KontoOszczednosciowe(string numer, double poczatkoweSaldo, string dane, double stopa)
    : Konto(numer, poczatkoweSaldo, dane), oprocentowanie(stopa) {}
void KontoOszczednosciowe::naliczOdsetki() 
{
    double odsetki = saldo*(oprocentowanie/100.0);
    saldo += odsetki;
    dodajTransakcje("NALICZENIE ODSETEK", odsetki);
}
void KontoOszczednosciowe::wypiszInformacje() const 
{
    cout << "[OSZCZEDNOSCIOWE] Konto : " << numerKonta 
         << " | Wlasciciel:" << wlasciciel 
         << " | Saldo: " << saldo 
         << " | Oprocentowanie: " << oprocentowanie << "%\n";
}