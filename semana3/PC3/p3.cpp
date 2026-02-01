#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void construir(int** A){
    

    for (int* i = *A; i < *A+9*9; i+=9)
    {
        int c=1;
        for (int* j = i; j < i+9; j++)
        {
            *j=c;
            c++;
        }
        
        int* inicio=i;

        for (int n = 0; n < 20; n++)
        {
            swap(*(inicio+rand()%(9)),*(inicio+rand()%(9)));
        }   
    }
}

void modifica(int** A, int i, int j){
    int n=*(*A+i*9+j);

    cout<<"valor seleccionado: "<< n <<endl;

    for (int* F = *A; F < *A+9*9; F+=9)
    {
        if (F==*A+i*9)
        {
            continue;
        }

        while (*(F+j)!=n)
        {
            for (int k = 0; k < 8; k++)
            {
                swap(*(F+k),*(F+k+1));
            }
        }
    }
}

void imprimir(int **A){
    for (int* i = *A; i < *A+9*9; i+=9)
    {
        for (int* j = i; j < i+9; j++)
        {
            cout << *j<<" ";
        }cout<<endl;
    }
}


int main(){
    srand(time(NULL));
    int M[9][9];
    int* p=&M[0][0];
    int** A=&p;int i=0,j=0;

    construir(A);
    cout<<"matriz inicial:\n";
    imprimir(A);

    cout<<"\nfila inicial(1-9): ";cin>>i;
    cout<<"columna inicial(1-9): ";cin>>j;

    modifica(A,i-1,j-1);
    cout<< "\nmatriz final:\n";
    imprimir(A);

    return 0;
}