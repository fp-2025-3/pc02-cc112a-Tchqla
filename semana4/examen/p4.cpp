#include <iostream>
using namespace std;

void duplicar(int* &arr, float* &arr2, int n){
    int* nueint=new int[2*n];
    float* nueflo=new float[2*n];

    for (int i = 0; i < n; i++)
    {
        *(nueint+i)=*(arr+i);
        *(nueflo+i)=*(arr2+i);
    }

    arr2=nueflo;arr=nueint;
    
    delete[] nueflo;delete[] nueint;
    nueflo=nullptr;nueint=nullptr;n=2*n;
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
    
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (*(arr2+j)<10)
            {
                swap(*(arr2+j),*(arr2+j+1));
            }
            
        }
        
    }

    int k=n-c;
    int* nueint=new int[k];
    float* nueflo=new float[k];

    for (int i = 0; i < k; i++)
    {
        *(nueint+i)=*(arr+i);
        *(nueflo+i)=*(arr2+i);
    }

    arr=nullptr;arr2=nullptr;
    
    arr2=nueflo;arr=nueint;
    
    delete[] nueflo;delete[] nueint;
    nueflo=nullptr;nueint=nullptr;n=k;
}

int llenado(int* &arr, float* &arr2, int &n, int c){
    int i=0;
    while (i<c && i<=n)
    {
        cout<<"codigo: ";cin>>*(arr+i);
        cout<<"promedio: ";cin>>*(arr2+i);
        i++;
    
        if(i==n){
            duplicar(arr,arr2,n);
        }
    }

    return i;
}

int main(){
    int n=5,cant;
    int* codigos=new int[n];
    float* promedios=new float[n];

    cout<<"cuantos estudiantes seran: ";cin>>cant;
    int total=llenado(codigos,promedios,n,cant);

    cout<<"filtrando estudiantes desaprobados...";
    redimensionarDesapro(codigos,promedios,total);
    cout<<"estudiantes desaprobados:\n";

    for (int i = 0; i < total; i++)
    {
        cout<<"codigo: "<<*(codigos+i)<<" promedio: "<<*(promedios+i);
    }
    
    return 0;
}
