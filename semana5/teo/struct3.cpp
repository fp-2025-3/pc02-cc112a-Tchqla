#include <iostream>
using namespace std;

struct producto
{
    int codigo;
    float precio;
    producto *sig;
};

int main(){
    producto* cabeza=nullptr;

    for (int i = 0; i < 2; i++)
    {
        producto* nue=new producto;
        cout<< "codigo: ";cin>>nue->codigo;
        cout<<"precio: ";cin>>nue->precio;
        nue->sig=cabeza;
        cabeza=nue;
    }
    

    return 0;
}