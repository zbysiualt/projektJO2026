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
    if (liczbaKont == 0) 
    {
        cout << "Brak kont w banku.\n";
        return;
    }
    for (int i=0; i <liczbaKont; ++i) 
    {
        konta[i]->wypiszInformacje();
    }
}
int Bank::getLiczbaKont() const 
{
    return liczbaKont;
}
Konto* Bank::znajdzKonto(string numer) const 
{
    for (int i=0; i <liczbaKont; ++i) 
    {
        if (konta[i]->getNumerKonta() == numer) 
        {
            return konta[i];
        }
    }
    throw NieznaneKontoException();
}