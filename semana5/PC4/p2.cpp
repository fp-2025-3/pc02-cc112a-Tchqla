#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct selecciones
{
    string nombre;
    int PG=0,PE=0,PP=0,GF=0,GC=0,DG=0;
    float rendimiento,puntaje=0;
};

void generar(selecciones* &pais,int n){
    int gf,gc;
    for (selecciones* i = pais; i < pais+n; i++)
    {
        i->PG=0;i->PE=0;i->PP=0;i->GF=0;i->GC=0;i->DG=0;i->puntaje=0;
        getline(cin,i->nombre);
        for (int j = 0; j < 100; i++)
        {
            gf=rand()%(6);gc=rand()%(6);
            if (gf>gc)
            {
                (i->PG)++;
            }else if (gf==gc)
            {
                (i->PE)++;
            }else
            {
                (i->PP)++;
            }
            i->GF+=gf;i->GC+=gc;
        }
        i->DG=i->GF-i->GC;
        i->puntaje=3*(i->PG)+(i->PE);
        i->rendimiento=(i->puntaje)/3.0;
        cin.ignore();
    }
    
}

void ordenar(selecciones* &pais,int n){
    for (selecciones* i = pais; i < pais+n ; i++)
    {
        for (selecciones* j = i; j < pais-n-1; j++)
        {
            if (i->puntaje<j->puntaje)
            {
                swap(i,j);
            }else if (i->puntaje==j->puntaje && i->DG>j->DG)
            {
                swap(i,j);
            }else if (i->DG==j->DG && i->GF<j->GF)
            {
                swap(i,j);
            }
        }
        
    }
    
}

void imprimirTabla(selecciones* pais,int n){
    cout<<"seleccion\tPG\tPE\tPP\tGF\tDG\tpts\trend(%)\n--------------------------------------------------------------------\n";
    for (selecciones* i = pais; i < pais+n; i++)
    {
        cout<<i->nombre<<"\t"<<i->PG<<"\t"<<i->PE<<"\t"<<i->PP<<"\t"<<i->GF<<"\t"<<i->GC<<"\t"<<i->DG<<"\t"<<i->puntaje<<"\t"<<i->rendimiento<<endl;
    }
    
    cout<<"CAMPEON: "<<pais->nombre<<" | puntaje: "<<pais->puntaje<<" | DG: "<<pais->DG<<" | rendimiento: "<<pais->rendimiento<<"%\n";
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