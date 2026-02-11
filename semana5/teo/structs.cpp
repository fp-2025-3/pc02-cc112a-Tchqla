#include <iostream>
using namespace std;

struct estuadiantes
{
    int codigo;
    float promedio;
};

void leer(estuadiantes* &salon, int n){
    for (estuadiantes* i = salon; i < salon+n; i++)
    {
        int j=i-salon;
        cout<<"ingrese el codigo del "<<j+1<<"° alumno: ";cin>>i->codigo;
        cout<<"ingrese su promedio: ";cin>>i->promedio;
    }
    
}

void soloAprobados(estuadiantes* salon,int n){
    cout<<"\nlos aprobados son:\n";
    for (estuadiantes* i = salon; i < salon+n; i++)
    {
        if (i->promedio>=10)
        {
            cout<<"promedio:"<<i->codigo<<"\tpromedio:"<<i->promedio<<endl;
        }
        
    }
    
}

int main(){
    int n;
    cout<<"cantidad de estudiantes: ";cin>>n;

    estuadiantes* sec=new estuadiantes[n];

    leer(sec,n);
    soloAprobados(sec,n);

    delete[] sec;

    return 0;
}