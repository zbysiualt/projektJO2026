#ifndef BANK_HPP
#define BANK_HPP
#include "Konto.hpp"
using namespace std;

class Bank 
{
    private:
        Konto** konta;
        int liczbaKont;
        int pojemnosc;
    public:
        Bank(int maxKont=20);
        ~Bank();
        bool dodajKonto(Konto* noweKonto);
        void wyswietlWszystkieKonta() const;
        int getLiczbaKont() const;
};
#endif