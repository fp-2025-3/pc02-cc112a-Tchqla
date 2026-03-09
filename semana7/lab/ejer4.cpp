#include <iostream>
#include <string>
using namespace std;

class Cuenta
{
private:
    int numero;
    string titular;
    double saldo;
public:
    Cuenta(int n,string t,double s):numero(n),titular(t),saldo(s){}
    Cuenta();
    ~Cuenta();
};
