#include <iostream>
#include <string>
using namespace std;

struct Procesos
{
    int ID;
    string nombre;
    float memoria;
    Procesos* siguiente;
};

struct ListaProcesos
{
    Procesos* cabeza;
};

int main(){
    ListaProcesos lista;
    lista.cabeza=nullptr;
}