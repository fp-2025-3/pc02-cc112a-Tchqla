#include <iostream>
#include <cstring>
using namespace std;

int separar_palabras(char* frase, char* palabras[]){
    int i=0;
    char* token= frase;

    while (*token!='\0')
    {
        if ((token==frase && *token!=' ') || (*(token-1)==' ' && *token!=' '))
        {
            *(palabras+i)=token;
            i++;
        }
        token++;
    }
    
    return i;
}

int comparar(const char* a, const char* b){
    return strcmp(a,b);
}

void ordenar(char* palabras[], int n){
    for (char** i = palabras; i < palabras+n-1; i++)
    {
        for (char** j = i+1; j < palabras+n; j++)
        {
            if (comparar(*i,*j)>0)
            {
                swap(*i,*j);
            }
        }
    }
}

void imprimir(char* palabras[], int n){
    for (char** i = palabras; i < (palabras+n); i++)
    {
        cout<<*i<<endl;
    }
}

int main(){
    char frase[200] ="aprender punteros exige mucha logica y practica";
    char* palabras[50]={};

    int n=separar_palabras(frase,palabras);
    cout<<"palabras:\n";
    imprimir(palabras,n);
    ordenar(palabras,n);
    cout<<"\npalabras en orden:\n";
    imprimir(palabras,n);

    return 0;
}