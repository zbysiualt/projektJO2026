# Symulator Banku
Symulator banku napisany w C++ w ramach projektu zaliczeniowego. Program pozwala na zakładanie różnych typów kont, robienie wpłat i wypłat, naliczanie odsetek oraz podgląd historii transakcjii

## Co jest w plikach

* `Konto` - zwykłe konto bankowe (ma numer, właściciela, saldo i tablicę z historią operacji)
* `KontoOszczednosciowe` - dziedziczy po zwykłym koncie, ma dodatkowo oprocentowanie i nalicza odsetki
* `KontoFirmowe` - dziedziczy po koncie, przy każdej wypłacie zabiera dodatkową prowizję
* `Bank` - trzyma wszystkie konta w dynamicznej tablicy wskaźników (`Konto**`) i czyści pamięć przy zamykaniu
* `Transakcja` - pojedynczy wpis do historii (typ operacji i kwota)
* `Wyjatki.hpp` - klasy wyjątków (jak brakuje pieniedzy, lub ktoś poda zły numer konta albo ujemną kwotę)
* `main.cpp` - główne menu w konsoli 
* `UML.md` - schemat klas UML.

## Co zostało użyte 

* Podział na pliki `.hpp` i `.cpp`
* Hermetyzacja - `private`, `protected`
* Dziedziczenie i polimorfizm -metody `virtual` i wirtualny destruktor
* Dynamiczna pamięć 
* Przeciążanie operatorów : `+=` do szybkiej wpłaty i `<<` do wypisania danych konta z historią
* Obsługa błędów na `try`, `throw`, `catch`

## Jak odpalić
W terminalu w folderze z projektem:

```bash
g++ main.cpp Bank.cpp Konto.cpp KontoOszczednosciowe.cpp KontoFirmowe.cpp Transakcja.cpp -o symulator
./symulator