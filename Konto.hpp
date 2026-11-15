#ifndef KONTO_HPP
#define KONTO_HPP
#include <string>
#include <iostream>
#include "Transakcja.hpp"
using namespace std;

class Konto 
{
    protected:
        string numerKonta;
        double saldo;
        string wlasciciel;
        Transakcja** historia;
        int liczbaTransakcji;
        int pojemnoscHistorii;
        void dodajTransakcje(string typ, double kwota);
    public:
        Konto();
        Konto(string numer, double poczatkoweSaldo, string dane);
        virtual ~Konto();

        string getNumerKonta() const;
        double getSaldo() const;
        void setSaldo(double noweSaldo);


        virtual void wypiszInformacje() const;
        virtual bool wyplac(double kwota);
        void wplac(double kwota);
        Konto& operator+=(double kwota);
        friend ostream& operator<<(ostream& os, const Konto& k);
};
#endif