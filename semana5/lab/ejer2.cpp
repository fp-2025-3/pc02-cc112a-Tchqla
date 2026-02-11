#include <iostream>
#include <cmath>
using namespace std;

struct Punto
{
    int x,y,z;
};

double distanciaEuclidiana(Punto a, Punto b){
    double D, temp;
    temp=pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2);
    D=sqrt(temp);
    
    return D;
}

int main(){
    Punto d1,d2;

    cout<<"ingrese las coordenadas del primer punto:\nX: ";cin>>d1.x;
    cout<<"Y: ";cin>>d1.y;
    cout<<"Z: ";cin>>d1.z;

    cout<<"ingrese las coordenadas del segundo punto:\nX: ";cin>>d2.x;
    cout<<"Y: ";cin>>d2.y;
    cout<<"Z: ";cin>>d2.z;

    double dist=distanciaEuclidiana(d1,d2);
    cout<<"la distancia entre los 2 puntos es: "<<dist<<endl;
    
    return 0;
}