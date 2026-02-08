#include <iostream>
#include <climits>
using namespace std;

int costMax(int* arr, int n, int i){
    cout<<"entrada: costo maximo (i="<<i<< ")\n";

    if (i==n)
    {
        cout <<"final i= "<<i<<"\n\n";
        return 0;
    }
    
    int max=INT_MIN;
    int produc=1;

    for (int j = i; j < n; j++)
    {
        produc*=arr[j];

        int costRest=costMax(arr,n,j+1);

        int total=produc+costRest;

        if (total>max)
        {
            max=total;
        }
        
    }

    cout<<"salida: costo maximo (i="<<i<<")\nvalor maximo: "<<max<<"\n\n";
    
    return max;
}

int main(){
    int n=0;

    while (n>15 || n<1)
    {
        cout<<"cuantos numeros habran en el arreglo?: ";cin>>n;
    }
    int* A=new int[n];

    for (int* i = A; i < A+n; i++)
    {
        cin>>*i;
    }
    
    int resul= costMax(A,n,0);

    cout<<"costo maximo: "<< resul<<endl;

    delete[] A;
    A=nullptr;

    return 0;
}