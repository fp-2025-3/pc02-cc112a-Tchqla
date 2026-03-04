#include <iostream>
#include <cmath>
using namespace std;

struct Termino
{
    double coeficiente;
    int exponente;
};

struct Polinomio
{
    Termino* terminos;
    int cant;
};

void crearPolinomio(Polinomio &p,int n){
    p.terminos=new Termino[n];
    p.cant=n;
}

void leerPoinomio(Polinomio &p){
    for (Termino* i = p.terminos; i < p.terminos+p.cant; i++)
    {
        int c=i-p.terminos;
        cout<<"ingrse el exponente: ";cin>>i->exponente;
        cout<<"ingrese coeficinete: ";cin>>i->coeficiente;
    }
}

void mostrarpolinomio(const Polinomio &p){
    Polinomio temp=p;
    for (int i = 0; i < temp.cant-1; i++)
    {
        for (int j = 0; j < temp.cant-i-1; j++)
        {
            if (temp.terminos[j].exponente<temp.terminos[j+1].exponente)
            {
                swap(temp.terminos[j],temp.terminos[j+1]);
            }
        }
    }

    for (Termino* i = temp.terminos; i < temp.terminos+temp.cant; i++)
    {
        if (i-temp.terminos>0)
        {
            cout<<" + ";
        }
        
        if (i->exponente==0)
        {
            cout<<i->coeficiente;
        }else if(i->exponente==1){
            if (i->coeficiente!=1)
            {
                cout<<i->coeficiente;
            }
            cout<<"x^";
        }else{
            if (i->coeficiente!=1)
            {
                cout<<i->coeficiente;
            }
            cout<<"x^"<<i->exponente;
        }
    }
    
    cout<<endl;
}

void evaluarPolinomio(const Polinomio &p,double x){
    double temp=0;
    for (Termino* i = p.terminos; i < p.terminos+p.cant; i++)
    {
        temp+=i->coeficiente*pow(x,(double)i->exponente);
    }
    
    cout<<"P("<<x<<") = "<<temp<<endl;
}

void derivarPolinomio(const Polinomio &p, Polinomio &der){
    if (p.cant==1 && p.terminos->exponente==0)
    {
        der.terminos=new Termino[1];
        der.terminos->exponente=0;
        der.terminos->coeficiente=0;
        der.cant=1;
        return;
    }
    
    int n=0;
    for (Termino* i = p.terminos; i < p.terminos+p.cant; i++)
    {
        if (i->exponente!=0)
        {
            n++;
        }
    }

    der.terminos=new Termino[n];der.cant=n;n=0;
    for (Termino* i = p.terminos; i < p.terminos+p.cant; i++)
    {
        if (i->exponente!=0)
        {
            der.terminos[n].coeficiente=i->coeficiente*i->exponente;
            der.terminos[n].exponente=i->exponente-1;
            n++;
        }
    }
}

void liberarPolinomio(Polinomio &p){
    delete[] p.terminos;
    p.terminos=nullptr;
}

int main(){
    int n;
    cout<<"indique la cantidad de coeficientes: ";cin>>n;

    Polinomio p;
    crearPolinomio(p,n);
    leerPoinomio(p);
    
    cout<<"\npolinomio: P(x)=";
    mostrarpolinomio(p);

    Polinomio deriP;
    derivarPolinomio(p,deriP);
    cout<<"\nPolinomio derivado: P'(x)= ";
    mostrarpolinomio(deriP);

    double x;
    cout<<"indica el calor de x=";cin>>x;
    evaluarPolinomio(p,x);
    evaluarPolinomio(deriP,x);

    liberarPolinomio(p);liberarPolinomio(deriP);

    return 0;
}