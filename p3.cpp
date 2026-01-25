#include <iostream>
using namespace std;

int* pico(int (*p)[],int f, int c){
    if (f==0 && c==0)
    {
        if (*(p)>*(p+1))
        {
            /* code */
        }
        
    }
    
}

void recorrido(int (*p)[]){
    for (int (*fila)[3] = p; fila < p + 2; ++fila) {
        for (int* col = *fila; col < *fila + 3; ++col) {
            cout << *col << " ";
        }
        cout << endl;
    }
}

int main(){
    const int f=4,c=5;
    int A[f][c]={{3,3,3,3,3},{3,4,4,2,3},{3,4,5,4,3},{3,3,3,3,3}};
    int (*ini)[c]=A;int (*fin)[c]=A+c;

    return 0;
}