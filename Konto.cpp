#include "Konto.hpp"
#include <iostream>
using namespace std;

Konto::Konto() : numerKonta(""), saldo(0.0), wlasciciel(""), liczbaTransakcji(0), pojemnoscHistorii(50) 
{
    historia= new Transakcja*[pojemnoscHistorii];
}
Konto::Konto(string numer, double poczatkoweSaldo, string dane)
    : numerKonta(numer), saldo(poczatkoweSaldo), wlasciciel(dane), liczbaTransakcji(0), pojemnoscHistorii(50) 
    {
        historia = new Transakcja*[pojemnoscHistorii];
        if (poczatkoweSaldo>0) 
        {
            dodajTransakcje("WPLATA POCZATKOWA", poczatkoweSaldo);
        }
    }

Konto::~Konto() 
{
    for (int i = 0; i < liczbaTransakcji; ++i) 
    {
        delete historia[i];
    }
    delete[] historia;
}

void Konto::dodajTransakcje(string typ, double kwota) 
{
    if (liczbaTransakcji<pojemnoscHistorii) 
    {
        historia[liczbaTransakcji] = new Transakcja(typ, kwota);
        liczbaTransakcji++;
    }
}
string Konto::getNumerKonta() const 
{
    return numerKonta;
}

double Konto::getSaldo() const 
{
    return saldo;
}

void Konto::setSaldo(double noweSaldo) 
{
    saldo=noweSaldo;
}

void Konto::wypiszInformacje() const 
{
    cout << "Konto: " << numerKonta<< " | Wlasciciel: " <<wlasciciel<< " | Saldo: " <<saldo<< " PLN\n";
}

bool Konto::wyplac(double kwota) 
{
    if (kwota<=saldo) 
    {
        saldo -= kwota;
        dodajTransakcje("WYPLATA", kwota);
        return true;
    }
    return false;
}

void Konto::wplac(double kwota) 
{
    saldo +=kwota;
    dodajTransakcje("WPLATA", kwota);
}
Konto& Konto::operator+=(double kwota) {
    wplac(kwota);
    return *this;
}
ostream& operator<<(ostream& os, const Konto& k) 
{
    k.wypiszInformacje();
    os << "Historia operacji (" << k.liczbaTransakcji << "):\n";
    for (int i=0; i<k.liczbaTransakcji; ++i) 
    {
        k.historia[i]->wypisz();
    }
    return os;
}