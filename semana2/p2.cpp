#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui 
    for (int* i = inicio; i < fin; i++)
    {
        if (equivale(clave,*i))
        {
            cout<<"encontrado valor: "<< *i<<" Pos: ";
            return i;
        }
        
    }
    cout<<"valor no encontrado: "<<"Pos: ";
    return nullptr;
}

// Implemente aqui los Criterios de equivalencia
bool igual(int a, int b){
    return a==b;
}

bool mismaParidad(int a, int b){
    if ((a%2==0 && b%2==0) || (a%2!=0 && b%2!=0))
    {
        return true;
    }

    return false;
}

bool divideA(int a, int b){
    return b%a==0;
}

int cifras(int n,int c){
    if (n==0)
    {
        return c;
    }
    
    n=n-n%10;
    n=n/10;
    return cifras(n,c+1);
}

bool mismaCantidadDigitos(int a, int b){
    int tempa=a, tempb=b;

    if (cifras(tempa,0)==cifras(tempb,0))
    {
        return true;
    }

    return false;
}

bool minimoResiduoMod5(int a, int b){
    return a%5==b%5;
}
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida


int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    // Imprima el arreglo
    cout<<"arreglo: ";
    for (int* i = inicio; i < fin; i++)
    {
        cout<< *i<<" ";
    }
    cout<<endl<<endl<<"clave: "<<clave<<endl;

    // Llame a la funcion buscar para cada criterio implementado
    cout<<"\ningualdad exacta: "<<buscar(inicio,fin,igual,clave);
    cout<<"\nmisma paridad: "<<buscar(inicio,fin,mismaParidad,clave);
    cout<<"\ndivide a: "<<buscar(inicio,fin,divideA,clave);
    cout<<"\nmisma cantidad de digitos: "<<buscar(inicio,fin,mismaCantidadDigitos,clave);
    cout<<"\nmismo residuo modulo 5: "<<buscar(inicio,fin,minimoResiduoMod5,clave)<<endl;

    return 0;
}