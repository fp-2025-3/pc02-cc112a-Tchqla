#include <iostream>
using namespace std;

bool pico(int (*p)[5],int f, int c){
    int val= *(*(p+f)+c);
    bool mayor= false;
    
    if (f>0)
    {
        int arriba= *(*(p+f-1)+c);
        if (val<arriba)
        {
            return false;
        }if (val>arriba)
        {
            mayor=true;
        }
    }
    
    if (f<3)
    {
        int abajo= *(*(p+f)+1+c);
        if (val<abajo)
        {
            return false;
        }if (val>abajo)
        {
            mayor=true;
        }
    }

    if (c>0)
    {
        int izquierda= *(*(p+f)+c-1);
        if (val<izquierda)
        {
            return false;
        }if (val>izquierda)
        {
            mayor=true;
        }
    }

    if (c<4)
    {
        int derecha= *(*(p+f)+c+1);
        if (val<derecha)
        {
            return false;
        }if (val>derecha)
        {
            mayor=true;
        }
    }

    return mayor;
}

void recorrido(int(*p)[5]){
    for (int (*i)[5] = p; i < p+4; ++i) {
        for (int* j = *i; j <*i+ 5; ++j) {
            int f= i-p;
            int c= j-*i;

            if (pico(p,f,c))
            {
                cout << "pico en (" << f <<","<< c << "): " << *j <<endl;
            }
        }
    }
}

int main(){
    const int f=4,c=5;
    int A[f][c]={{3,3,3,3,3},{3,4,4,2,3},{3,4,5,4,3},{3,3,3,3,3}};
    int (*p)[c]=A;

    recorrido(p);

    return 0;
}