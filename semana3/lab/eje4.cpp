#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void construir(int** A){
    srand(time(NULL));
    for (int** i = A; i < A+9; i++)
    {
        for (int* j = *i; j < *A+9; j++)
        {
            *j=rand()%(9-1+1);
        }
        
    }
    
}

int main(){
    int M[9][9];
    int* p=&M[0][0];
    int** A=&p;


    return 0;
}