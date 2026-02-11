/*
dado una lista de nombres
char nombres[][20]={
    "lesly",
    "americo",
    "xingbeck",
    "william",
    "julio",
    "darwin",
    "kevin"
}

1. ordenar la lista en orden alfabetico ascendente
2. no usar []
    use aritmetica de punteros
    puede usar las funciones 
    el intercambio debe realizarlo copiando
*/

#include <iostream>
#include <cstring>
using namespace std;

void orden(const char** p,int n){
    char temp[30];
    for (const char** i = p, i < p+n-1; i++)
    {
        for (const char** j = i; j <p+ n; j++)
        {
            /* code */
        }
        
    }
    
    
}

int main(){
    const char* nombres[]={
    "lesly",
    "americo",
    "xingbeck",
    "william",
    "julio",
    "darwin",
    "kevin"
    };

    cout<< sizeof(nombres)<<endl;

    return 0;
}