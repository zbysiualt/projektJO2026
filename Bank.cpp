#include "Bank.hpp"
#include <iostream>
using namespace std;

Bank::Bank(int maxKont) : liczbaKont(0), pojemnosc(maxKont) 
{
    konta = new Konto*[pojemnosc];
}
Bank::~Bank() 
{
    for (int i=0; i<liczbaKont;++i) 
    {
        delete konta[i];
    }
    delete[] konta;
}
bool Bank::dodajKonto(Konto* noweKonto) 
{
    if (liczbaKont < pojemnosc) 
    {
        konta[liczbaKont]=noweKonto;
        liczbaKont++;
        return true;
    }
    return false;
}
void Bank::wyswietlWszystkieKonta() const 
{
    for (int i=0; i <liczbaKont; ++i) 
    {
        konta[i]->wypiszInformacje();
    }
}
int Bank::getLiczbaKont() const 
{
    return liczbaKont;
}