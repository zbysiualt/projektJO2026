#include "Konto.hpp"
#include <iostream>
using namespace std;

Konto::Konto() : numerKonta(""), saldo(0.0), wlasciciel("") {}
Konto::Konto(string numer, double poczatkoweSaldo, string dane)
    : numerKonta(numer), saldo(poczatkoweSaldo), wlasciciel(dane) {}

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
    cout << "Konto: " << numerKonta<< " | Wlasciciel: " <<wlasciciel<< " | Saldo: " <<saldo<< "\n";
}

bool Konto::wyplac(double kwota) 
{
    if (kwota<=saldo) 
    {
        saldo -= kwota;
        return true;
    }
    return false;
}

void Konto::wplac(double kwota) 
{
    saldo +=kwota;
}