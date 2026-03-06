#include <iostream>
using namespace std;

int** crearMatriz(int n, int m){
    int** p=new int*[n];

    for (int i = 0; i < n; i++)
    {
        p[i]=new int[m];
    }
    
    return p;
}

void llenarMatriz(int** M,int n,int m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            M[i][j]=(i+1)*(j+1);
        }
        
    }
    
}

int* sumarFilas(int** M,int n,int m){
    int* filas=new int[n]{0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m; j++)
        {
            filas[i]+=M[i][j];
        }
        
    }
    
    return filas;
}

void liberarMatriz(int** M,int n){
    for (int i = 0; i < n; i++)
    {
        delete[] M[i];
    }
    
    delete[] M;
}

int main(){
    int n,m;

    cout<<"indique las filas: ";cin>>n;
    cout<<"indique las columnas: ";cin>>m;

    int** A=crearMatriz(n,m);
    llenarMatriz(A,n,m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    

    int* suma=sumarFilas(A,n,m);

    cout<<"\nvector suma filas: ";
    for (int i = 0; i < n-1; i++)
    {
        cout<<suma[i]<<" , ";
    }cout<<suma[n-1]<<endl;
    
    liberarMatriz(A,n);
    delete[] suma;

    return 0;
}