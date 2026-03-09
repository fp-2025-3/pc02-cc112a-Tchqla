#include <iostream>
#include <cmath>
using namespace std;

struct Punto
{
    double x;
    double y;
};

void leerPunto(Punto* p){
    cout<<"x: ";cin>>p->x;
    cout<<"y: ";cin>>p->y;
}

double distaciaOrigen(const Punto* p){
    double sumCuadrados=pow(p->x,2)+pow(p->y,2);

    return sqrt(sumCuadrados);
}

Punto* masLejano(Punto* p1,Punto* p2){
    if (distaciaOrigen(p1)<distaciaOrigen(p2))
    {
        return p2;
    }
    
    return p1;
}

int main(){
    Punto* p1=new Punto;
    Punto* p2=new Punto;

    cout<<"para punto 1:\n";
    leerPunto(p1);

    cout<<"\npara punto 2:\n";
    leerPunto(p2);

    Punto* masLejos=masLejano(p1,p2);

    cout<<"\nel mas lejano tiene coordenadas:"
        <<"\nx: "<<masLejos->x
        <<"\ny: "<<masLejos->y<<endl;

    return 0;
}