#include <iostream>
using namespace std;

void duplicar(int* &arr, float* &arr2, int &n){
    int* nueint=new int[2*n];
    float* nueflo=new float[2*n];

    for (int i = 0; i < n; i++)
    {
        *(nueint+i)=*(arr+i);
        *(nueflo+i)=*(arr2+i);
    }

    delete[] arr;delete[] arr2;
    arr2=nueflo;arr=nueint;
    
    n=2*n;
}

void redimensionarDesapro(int* &arr, float* &arr2, int &n){
    int c=0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr2+i)<10)
        {
            c++;
        }
    }

    int k=n-c,j=0;
    int* nueint=new int[k];
    float* nueflo=new float[k];

    for (int i = 0; i < n; i++)
    {
        if (*(arr2+i)>=10)
        {
            *(nueint+j)=*(arr+i);
            *(nueflo+j)=*(arr2+i);
            j++;
        }
        
        
    }

    delete[] arr;delete[] arr2;
    arr2=nueflo;arr=nueint;

    n=k;
}

int llenado(int* &arr, float* &arr2, int &n, int c){
    int i=0;
    while (i<c)
    {
        if(i==n){
            duplicar(arr,arr2,n);
        }

        cout<<"codigo: ";cin>>*(arr+i);
        cout<<"promedio: ";cin>>*(arr2+i);
        i++;
    }

    return i;
}

int main(){
    int n=5,cant;
    int* codigos=new int[n];
    float* promedios=new float[n];

    cout<<"cuantos estudiantes seran: ";cin>>cant;
    int total=llenado(codigos,promedios,n,cant);

    cout<<"\nfiltrando estudiantes desaprobados...\n";
    redimensionarDesapro(codigos,promedios,total);
    
    cout<<"\nestudiantes aprobados:\n";

    for (int i = 0; i < total; i++)
    {
        cout<<"codigo: "<<*(codigos+i)<<" promedio: "<<*(promedios+i)<<endl;
    }

    delete[] codigos; delete[] promedios;
    
    return 0;
}
