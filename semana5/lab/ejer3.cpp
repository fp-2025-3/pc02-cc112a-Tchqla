#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct seleccion
{
    string nombre;
    int puntos,PG,PP,PE;
    float rendimiento;
};

void llenado(seleccion* countryxd,int n){
    for (seleccion* i = countryxd; i < countryxd+n; i++)
    {
        cin.ignore();
        cout<<"ingrese nombre de la seleccion: ";getline(cin,i->nombre);
        i->PG=rand()%(100-0+1);
        i->PP=rand()%(100-(i->PG)-0+1);
        i->PE=100-(i->PG+i->PP);

        i->puntos=3*(i->PG)+(i->PE);

        float temp=(i->puntos)/300.0;

        i->rendimiento=temp*100;
    }
    
}

void tabla(seleccion* countryxd,int n){
    float max=countryxd->rendimiento;
    int m=0;
    cout<<"seleccion\t\tPG\tPP\tPE\tpuntaje\trendimiento\n";
    for (seleccion* i = countryxd; i < countryxd+n; i++)
    {
        cout<<i->nombre<<"\t\t"<<i->PG<<"\t"<<i->PP<<"\t"<<i->PE<<"\t"<<i->puntos<<"\t\t"<<setprecision(1)<<i->rendimiento<<endl;
        if (max<(i->rendimiento))
        {
            max=i->rendimiento;
            m=i-countryxd;
        }
    }
    
    cout<<"\nla seleccion con mejor rendimiento es: "<<(countryxd+m)->nombre<<" rendimiento: "<<max<<endl;
}

int main(){
    srand(time(0));

    seleccion* pais=new seleccion[5];

    llenado(pais,5);

    tabla(pais,5);

    delete[] pais;

    return 0;
}