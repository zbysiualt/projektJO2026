#ifndef KONTOFIRMOWE_HPP
#define KONTOFIRMOWE_HPP
#include "Konto.hpp"
using namespace std;

class KontoFirmowe : public Konto 
{
private:
    double prowizja;
public:
    KontoFirmowe();
    KontoFirmowe(string numer, double poczatkoweSaldo, string dane, double prow);
    void wyplac(double kwota) override;
    void wypiszInformacje() const override;
};
#endif