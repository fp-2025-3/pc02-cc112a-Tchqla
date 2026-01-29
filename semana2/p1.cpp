#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(const double* coef, int grado, int k, double* res, int& gradoRes) {
    // Escriba su codigo aqui
    gradoRes = grado - k;

    const double* ori = coef;
    double* der = res;
    for (int i = 0; i <= grado; i++) {
        *der = *ori;
        der++;
        ori++;
    }
    
    for (int i = 0; i < k; i++)
    {
        ori=res+1;
        der=res;
        for (int j = 1; j <= grado; j++)
        {
            *(der)=*(ori)*j;
            ori++;
            der++;
        }
    }
}

// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double* p, int grado) {
    for (int i = grado; i > 0; i--)
    {
        cout<< *(p+i)<<"x^"<<i<<" + ";
    }
    cout << *p<<endl;
}

int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const int grado = 3;

    double resultado[10]={}; // espacio suficiente
    int gradoResultado;

    int k = 2; // derivada de orden 2

    derivadaK(coef,grado,k,resultado,gradoResultado);// Llamar a su funcion derivadaK

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada
    cout <<"Polinomio original:\n";
    imprimirPolinomio(coef, grado);
    cout <<"Derivada de orden "<<k<<":\n";
    imprimirPolinomio(resultado,gradoResultado);

    return 0;
}