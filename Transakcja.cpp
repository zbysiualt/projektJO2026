#include "Transakcja.hpp"
using namespace std;

Transakcja::Transakcja() : typ(""), kwota(0.0) {}
Transakcja::Transakcja(string t, double k) : typ(t), kwota(k) {}
void Transakcja::wypisz() const 
{
    cout <<"  - "<< typ <<": "<< kwota<<" PLN\n";
}