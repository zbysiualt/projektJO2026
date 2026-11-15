#ifndef TRANSAKCJA_HPP
#define TRANSAKCJA_HPP
#include <string>
#include <iostream>
using namespace std;

class Transakcja 
{
private:
    string typ;
    double kwota;
public:
    Transakcja();
    Transakcja(string t, double k);
    void wypisz() const;
};
#endif