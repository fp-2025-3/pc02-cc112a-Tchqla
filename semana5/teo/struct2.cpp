#include <iostream>
#include <string>
using namespace std;

struct fecha
{
    int dia,mes,año;
};


struct contacto
{
    string nombre;
    fecha nacimiento;
};

void leer(contacto* alguien, int n){
    for (contacto* i = alguien; i < alguien+n; i++)
    {
        cin.ignore();
        cout<<"nombre: ";getline(cin,i->nombre);
        cout<<"fecha nacimiento:\ndia: ";cin>>i->nacimiento.dia;
        cout<<"mes: ";cin>>i->nacimiento.mes;
        cout<<"año: ";cin>>i->nacimiento.año;
    }
    
}

void buscar(contacto* alguien, int n, int m){
    for (contacto* i = alguien; i < alguien+n; i++)
    {
        if (i->nacimiento.año==m)
        {
            cout<<"nombre: "<<i->nombre<<endl;
        }
        
    }
    
}

int main(){
    int n,año;
    cout<<"ingrese la cantidad de contactos: ";cin>>n;

    contacto* persona=new contacto[n];

    leer(persona,n);

    cout<<"ingrese el año a buscar:";cin>>año;
    buscar(persona,n,año);

    delete[] persona;

    return 0;
}