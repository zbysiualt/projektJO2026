#ifndef KONTO_HPP
#define KONTO_HPP
#include <string>
using namespace std;

class Konto 
{
    protected:
        string numerKonta;
        double saldo;
        string wlasciciel;
    public:
        Konto();
        Konto(string numer, double poczatkoweSaldo, string dane);
        virtual ~Konto() =default;

        string getNumerKonta() const;
        double getSaldo() const;
        void setSaldo(double noweSaldo);


        virtual void wypiszInformacje() const;
        virtual bool wyplac(double kwota);
        void wplac(double kwota);
};
#endif