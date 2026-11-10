#include "Bank.hpp"
#include "Konto.hpp"
#include <iostream>
using namespace std;

int main() 
{
    Bank mojBank(10);
    Konto* k1 = new Konto("1001", 1500.0, "Jan Kowalski");
    Konto* k2 = new Konto("1002", 3200.0, "Anna Nowak");

    mojBank.dodajKonto(k1);
    mojBank.dodajKonto(k2);
    mojBank.wyswietlWszystkieKonta();
    return 0;
}