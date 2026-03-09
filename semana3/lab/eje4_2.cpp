//profesor si podria revisarlo:
//me acabo de dar cuenta que *(*(A+i)+j) no es equivalente a *(A+i*col+j)
//son para casos distintos
//se puede hacer de esta manera para la pc?
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void construir(int** A){
    srand(time(NULL));

    for (int** i = A; i < A+9; i++)
    {
        int c=1;
        for (int* j = *i; j < *i+9; j++)
        {
            *j=c;c++;
        }

        int* p= *i;
        for (int k = 0; k < 20; k++)
        {
            swap(*(p+rand()%(8-0+1)),*(p+rand()%(8-0+1)));
        }
    }
    
}

void imprimir(int** A){
    for (int** i = A; i < A+9; i++)
    {
        for (int* j = *i; j < *i+9; j++)
        {
            cout<<*j<<" ";
        }
        cout<<endl;
    }
}

void actualizar(int** A, int i, int j){
    int n=*(*(A+i)+j);
    cout<<"valor seleccionado: "<< n <<endl;

    for (int** fila = A; fila < A+9; fila++)
    {
        if (fila==A+i)
        {
            continue;
        }
        
        while (*(*(fila)+j)!=n)
        {
            for (int k = 0; k < 8; k++)
            {
                swap(*(*(fila)+k),*(*(fila)+k+1));
            }
        }
    }
}

int main(){
    int M[9][9], i=0, j=0;

    int* p[9];
    for (int i = 0; i < 9; i++)
    {
        p[i]=M[i];
    }
    
    int** A=p;

    construir(A);
    imprimir(A);
    cout<<"\nfila inicial (1-9): ";cin>>i;
    cout<<"columna inicial (1-9): ";cin>>j;
    actualizar(A,i-1,j-1);

    cout<<"\ntablero final:\n";
    imprimir(A);

    return 0;
}