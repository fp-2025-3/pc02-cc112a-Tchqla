#include <iostream>
using namespace std;

bool esFilaDominante(int (*M)[5], int fila){
    for (int j = 0; j < 5; j++)
    {
        int temp=M[fila][j];

        for (int k = 0; k < 5; k++)
        {
            if (temp==M[k][j])
            {
                continue;
            }else if (M[k][j]>temp)
            {
                return false;
            }
                
        }
            
    }
    
    return true;
}

int contarColumnasCriticas(int (*M)[5]){
    int temp=0, max=0,c=0;

    for (int i = 0; i < 5; i++)
    {
        temp=0;
        for (int j = 0; j < 5; j++)
        {
            temp+=M[i][j];
        }
        
        if (temp>max)
        {
            max=temp;
        }
        
    }
    
    for (int i = 0; i < 5; i++)
    {
        temp=0;
        for (int j = 0; j < 5; j++)
        {
            temp+=M[j][i];
        }

        if (temp>max)
        {
            c++;
        }
        
    }
    
    return c;
}

bool esMatrizEscalonada(int (*M)[5]){
    

}

int valorNucleo(int (*M)[5]){
    bool es_nucle=false;

    for (int i = 0; i < 5; i++)
    {
        int max=M[0][0],min=M[0][0];
        for (int j = 0; j < 5; j++)
        {
            if (max<M[i][j])
            {
                max=M[i][j];
            }
            
            
        }
        
    }
    
}

int main(){
    const int N = 5;
    int M[N][N];

    return 0;
}