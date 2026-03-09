#include <iostream>
using namespace std;

int sumarReg(int (*p)[5],int i1, int j1, int i2, int j2){
    int suma=0;

    for (int (*i)[5] = p+i1; i <= p+i2; i++)
    {
        for (int* j = *i+j1; j <= *i+j2; j++)
        {
            suma+=*j;
        }
        
    }
    
    return suma;
}

void submatriz(int (*p)[5],int f, int c){
    int sumMax=-3-1;//un numero q sea menor al menor elemento de la matriz
    int mejor_i1 = 0, mejor_j1 = 0;
    int mejor_i2 = 0, mejor_j2 = 0;

    for (int i1 = 0; i1 < f; i1++)
    {
        for (int i2 = i1; i2 < f; i2++)
        {
            for (int j1 = 0; j1 < c; j1++)
            {
                for (int j2 = j1; j2 < c; j2++)
                {
                    int actual=sumarReg(p,i1,j1,i2,j2);

                    if (actual>sumMax)
                    {
                        sumMax= actual;
                        mejor_i1=i1;
                        mejor_i2=i2;
                        mejor_j1=j1;
                        mejor_j2=j2;
                    }
                    
                }
                
            }
            
        }
        
    }

    cout<<"submatriz de suma maxima:\n";
    cout<<"esquina superior izquierda: ("<<mejor_i1<<","<<mejor_j1<<")\n";
    cout<<"esquina inferior derecha: ("<<mejor_i2<<","<<mejor_j2<<")\n";
    cout<<"suma maxima: "<<sumMax<<endl;
}

int main(){
    int A[4][5]={{-2,1,-3,4,-1},{2,3,-2,1,-5},{-1,4,2,-3,2},{1,-2,3,4,-1}};
    int (*ini)[5]=A;

    for (int (*i)[5] = ini; i < ini+4; i++)
    {
        for (int* j = *i; j < *i+5; j++)
        {
            cout<<*j<<"\t";
        }
        cout<<endl;
    }
    
    submatriz(ini,4,5);

    return 0;
}