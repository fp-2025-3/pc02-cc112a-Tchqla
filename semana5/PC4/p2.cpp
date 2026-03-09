#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct selecciones
{
    string nombre;
    int PG,PE,PP,GF,GC,DG;
    float rendimiento,puntaje;
};

void generar(selecciones* pais,int n){
    int gf,gc;
    for (selecciones* i = pais; i < pais+n; i++)
    {
        i->PG=0;i->PE=0;i->PP=0;i->GF=0;i->GC=0;i->DG=0;i->puntaje=0;

        cout<<"ingrese el nombre de la seleccion "<<(i-pais)+1<<": ";
        getline(cin,i->nombre);

        for (int j = 0; j < 100; j++)
        {
            gf=rand()%(6);gc=rand()%(6);
            if (gf>gc)
            {
                (i->PG)++;
                i->puntaje+=3;
            }else if (gf==gc)
            {
                (i->PE)++;
                i->puntaje++;
            }else
            {
                (i->PP)++;
            }
            i->GF+=gf;i->GC+=gc;
        }
        i->DG=i->GF-i->GC;
        i->rendimiento=(i->puntaje)/3.0;
    }
    
}

void ordenar(selecciones* pais,int n){
    for (selecciones* i = pais; i < pais+n-1 ; i++)
    {
        for (selecciones* j = i+1; j < pais+n ; j++)
        {
            if (i->puntaje<j->puntaje)
            {
                swap(*i,*j);
            }else if (i->puntaje==j->puntaje && i->DG>j->DG)
            {
                swap(*i,*j);
            }else if (i->DG==j->DG && i->GF<j->GF)
            {
                swap(*i,*j);
            }
        }
        
    }
    
}

void imprimirTabla(selecciones* pais,int n){
    cout<<"\n\t\t\t\t\t-----\nseleccion\tPG\tPE\tPP\tGF\tGC\tDG\tpts\trend(%)\n-------------------------------------------------------------------------------\n";
    for (selecciones* i = pais; i < pais+n; i++)
    {
        cout<<i->nombre<<"\t\t"<<i->PG<<"\t"<<i->PE<<"\t"<<i->PP<<"\t"<<i->GF<<"\t"<<i->GC<<"\t"<<i->DG<<"\t"<<fixed<<setprecision(0)<<i->puntaje<<"\t"<<fixed<<setprecision(1)<<i->rendimiento<<endl;
    }
    
    cout<<"CAMPEON: "<<pais->nombre<<" | puntaje: "<<fixed<<setprecision(0)<<pais->puntaje<<" | DG: "<<pais->DG<<" | rendimiento: "<<fixed<<setprecision(1)<<pais->rendimiento<<"%\n";
}

int main(){
    srand(time(0));
    selecciones* pais=new selecciones[5];

    generar(pais,5);
    
    ordenar(pais,5);

    imprimirTabla(pais,5);

    delete[] pais;pais=nullptr;

    return 0;
}