#include <iostream>
using namespace std;

int guardaDirecciones(char* texto,char** indice){
    char* temp=texto;int n=0;

    while (*temp!='\0')
    {
        if ((temp==texto && *temp!=' ') || (*(temp-1)==' ' && *temp!=' '))
        {
            *(indice+n)=temp;
            n++;
        }
        temp++;
    }
    
    return n;
}

int comparar(const char* a, const char* b){
    while (*a==*b && *a!=' ' && *b!=' ')
    {
        a++;b++;
    }
    
    return *a-*b;
}

void ordenarIndice(char** indice, int n){
    for (char** i = indice; i < indice+n-1; i++)
    {
        for (char** j = i+1; j < indice+n; j++)
        {
            if (comparar(*i,*j)>0)
            {
                swap(*i,*j);
            }
            
        }
        
    }
    
}

void imprimir(char* texto, char** indice, int n){
    
    for (int i = 0; i < n; i++)
    {
        char* p= *(indice+i);
        char*coo=p;

        while (*coo!=' ' && *coo!='\0')
        {
            cout <<*coo;coo++;
        }
        
        int pos=p-texto;
        cout<<"\t\t(posicion "<<pos<<")"<<endl;
    }
    
}

int main(){
    char texto[]="los punteros no se copian se referencian y se ordenan";
    char* indice[50];

    int n=guardaDirecciones(texto, indice);

    ordenarIndice(indice,n);

    imprimir(texto, indice, n);

    return 0;
}