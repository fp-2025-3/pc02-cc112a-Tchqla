#include <iostream>
using namespace std;

int sumarReg(int (*p)[5],int i1, int j1, int i2, int j2){
    int suma=0;

    for (int (*i)[5] = p; i < p+4; i++)
    {
        for (int* j = *i; j < *i+5; j++)
        {
            suma+=*j;
        }
        
    }
    
    return suma;
}

int main(){
    int A[4][5]={{-2,1,-3,4,-1},{2,3,-2,1,-5},{-1,4,2,-3,2},{1,-2,3,4,-1}};
    int (*ini)[5]=A;
    
    return 0;
}