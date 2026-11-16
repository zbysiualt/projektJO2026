#include "Bank.hpp"
#include "Konto.hpp"
#include "KontoOszczednosciowe.hpp"
#include "KontoFirmowe.hpp"
#include "Wyjatki.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    Bank mojBank(20);
    mojBank.dodajKonto(new Konto("1001", 1000.0, "Jan_Kowalski"));
    mojBank.dodajKonto(new KontoOszczednosciowe("2001", 5000.0, "Anna_Nowak", 5.0));
    mojBank.dodajKonto(new KontoFirmowe("3001", 2000.0, "wessby", 10.0));

    int wybor;
    do {
        cout << "\n========================================\n";
        cout << "           SYMULATOR BANKU\n";
        cout << "========================================\n";
        cout << "1. Wyswietl wszystkie konta\n";
        cout << "2. Otworz nowe konto\n";
        cout << "3. Wplac srodki\n";
        cout << "4. Wyplac srodki\n";
        cout << "5. Nalicz odsetki (konto oszczednosciowe)\n";
        cout << "6. Pokaz szczegoly i historie konta\n";
        cout << "0. Wyjscie\n";
        cout << "----------------------------------------\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        try 
        {
            switch (wybor) 
            {
                case 1: 
                {
                    mojBank.wyswietlWszystkieKonta();
                    break;
                }
                case 2: 
                {
                    int typ;
                    string numer, wlasciciel;
                    double saldo;

                    cout << "Typ konta (1 - Standardowe, 2 - Oszczednsciowe, 3 - Firmowe): ";
                    cin >> typ;
                    cout << "Podaj numer konta: ";
                    cin >> numer;
                    cout << "Podaj wlasciciela (bez spacji, np. Jan_Kowalski): ";
                    cin >> wlasciciel;
                    cout << "Podaj saldo poczatkowe: ";
                    cin >> saldo;

                    if (saldo<0) 
                    {
                        throw NieprawidlowaKwotaException();
                    }


                    bool dodano = false;
                    if (typ == 1) 
                    {
                        dodano = mojBank.dodajKonto(new Konto(numer, saldo, wlasciciel));
                    } 
                    else if (typ == 2) 
                    {
                        double stopa;
                        cout << "Podaj oprocentowanie (%): ";
                        cin >> stopa;
                        dodano = mojBank.dodajKonto(new KontoOszczednosciowe(numer, saldo, wlasciciel, stopa));
                    } 
                    else if (typ == 3) 
                    {
                        double prowizja;
                        cout << "Podaj prowizje za przelew (PLN): ";
                        cin >> prowizja;
                        dodano = mojBank.dodajKonto(new KontoFirmowe(numer, saldo, wlasciciel, prowizja));
                    } 
                    else 
                    {
                        cout << "Nieznany typ konta.\n";
                        break;
                    }

                    if (dodano) 
                    {
                        cout << "Konto zostalo utworzone.\n";
                    } else 
                    {
                        cout << "Bank osiagnal maksymalna pojemnosc.\n";
                    }
                    break;
                }
                case 3: 
                {
                    string numer;
                    double kwota;
                    cout << "Podaj numer konta: ";
                    cin >> numer;
                    Konto* k = mojBank.znajdzKonto(numer);
                    cout << "Podaj kwote wplaty: ";
                    cin >> kwota;
                    *k += kwota;
                    cout << "Wplata zakonczona sukcesem.\n";
                    break;
                }
                case 4: 
                {
                    string numer;
                    double kwota;
                    cout << "Podaj numer konta: ";
                    cin >> numer;
                    Konto* k = mojBank.znajdzKonto(numer);
                    cout << "Podaj kwote wyplaty: ";
                    cin >> kwota;
                    k->wyplac(kwota);
                    cout << "Wyplata zakonczona sukcesem.\n";
                    break;
                }
                case 5: 
                {
                    string numer;
                    cout << "Podaj numer konta oszczednosciowego: ";
                    cin >> numer;
                    Konto* k = mojBank.znajdzKonto(numer);
                    k->naliczOdsetki();
                    cout << "Operacja naliczania odsetek zakonczona.\n";
                    break;
                }
                case 6: 
                {
                    string numer;
                    cout << "Podaj numer konta: ";
                    cin >> numer;
                    Konto* k = mojBank.znajdzKonto(numer);
                    cout << "\n" << *k;
                    break;
                }
                case 0: 
                {
                    cout << "Zamykanie programu...\n";
                    break;
                }
                default: 
                {
                    cout << "Nieznana opcja.\n";
                    break;
                }
            }
        }
        catch (BrakSrodkowException) 
        {
            cout << "[BLAD]: Brak wystarczajacych srodkow na koncie!\n";
        }
        catch (NieznaneKontoException) 
        {
            cout << "[BLAD]: Nie znaleziono konta o podanym numerze!\n";
        }
        catch (NieprawidlowaKwotaException) 
        {
            cout << "[BLAD]: Kwota musi byc wieksza od zera!\n";
        }
    } 
    while (wybor != 0);
    return 0;
}