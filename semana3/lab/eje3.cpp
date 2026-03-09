#include <iostream>
using namespace std;

int construir_indice(char* texto, char* indice[]){
    char* p= texto;
    int i=0;
    while (*p!='\0')
    {
        if ((p==texto && *p!=' ') || (*(p-1)==' ' && *p!=' '))
        {
            *(indice+i)=p;
            i++;
        }
        p++;
    }

    return i;
}

int comparar(const char* a, const char* b){
    while (*a==*b && *a!='\0' && *b!='\0' && *a!=' ' && *b!=' ')
    {
        a++;b++;
    }
    
    return *a-*b;
}

void ordenar_indice(char* indice[], int n){
    for (char** i = indice; i < indice+n-1; i++)
    {
        for (char** j = i+1; j < indice+n; j++)
        {
            if(comparar(*i,*j)>0){
                swap(*i,*j);
            }
        }

    }
    
}

void imprimir_indice(char* texto, char* indice[], int n){
    for (char** i = indice; i < (indice+n); i++)
    {
        char *p=*i;

        while (*p!=' ' && *p!='\0')
        {
            cout << *p;
            p++;
        }

        int posic=*i-texto;

        cout <<"\t(posicion "<<posic<<")"<<endl;
    }
}

int main(){
    char texto[300] = "los punteros no se copian se referencian y se ordenan";
    char* indice[60];

    int n=construir_indice(texto,indice);
    cout<<"palabras:\n";
    imprimir_indice(texto,indice,n);
    ordenar_indice(indice,n);
    
    cout<<"\npalabras ordenadas:\n";
    imprimir_indice(texto,indice,n);

    return 0;
}