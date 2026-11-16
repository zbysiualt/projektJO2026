#ifndef KONTOOSZCZEDNOSCIOWE_HPP
#define KONTOOSZCZEDNOSCIOWE_HPP
#include "Konto.hpp"
using namespace std;

class KontoOszczednosciowe : public Konto 
{
private:
    double oprocentowanie;
public:
    KontoOszczednosciowe();
    KontoOszczednosciowe(string numer, double poczatkoweSaldo, string dane, double stopa);
    void naliczOdsetki() override;
    void wypiszInformacje() const override;
};
#endif