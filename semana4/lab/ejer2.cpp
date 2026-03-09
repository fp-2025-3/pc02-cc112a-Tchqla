#include <iostream>
using namespace std;

bool esFilaDominante(int (*M)[5], int fila){
    for (int j = 0; j < 5; j++)
    {
        int temp=*(*(M+fila)+j);

        for (int k = 0; k < 5; k++)
        {
            if (k==fila)
            {
                continue;
            }
            
            if (*(*(M+k)+j)>temp)
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
    int posAnte=-1;

    for (int (*i)[5] = M; i < M+5; i++)
    {
        int posActu=-1;

        for (int j= 0; j < 5; j++)
        {
            if (*(*i+j)!=0)
            {
                posActu=j;
                break;
            }
            
        }

        if (posActu!=-1)
        {
            if (posActu <= posAnte)
            {
                return false;
            }
            
            posAnte=posActu;
        }
                
    }
    
    return true;
}

int valorNucleo(int (*M)[5]){
    for (int i = 0; i < 5; i++)
    {
        int maxFila=*(*(M+i)), iColum=0;
        for (int j = 1; j < 5; j++)
        {
            if (maxFila<*(*(M+i)+j))
            {
                maxFila=*(*(M+i)+j);
                iColum=j;
            }
            
        }

        bool minCol=true;
        for (int i = 0; i < 5; i++)
        {
            if (*(*(M+i)+iColum)<maxFila)
            {
                minCol=false;
            }
        }

        if (minCol)
        {
            return maxFila;
        }
        
    }

    return -1;
}

int main(){
    const int N = 5;
    int M[N][N]= {
        {0, 0, 7, 8, 9},
        {0, 0, 0, 5, 6},
        {0, 0, 0, 0, 4},
        {1, 2, 3, 4 ,5},
        {9, 8, 7, 6, 5}
    };

    for (int i = 0; i < N; i++)
    {
        if (esFilaDominante(M,i))
        {
            cout << "la fila "<<i+1<<" si es dominante.\n";
        }
        else{
            cout<<"la fila "<<i+1<<" no es dominante.\n";
        }
        
    }
    
    cout<< "\nhay "<<contarColumnasCriticas(M)<<" columnas criticas.\n";

    if (esMatrizEscalonada(M))
    {
        cout<<"\nes matriz escalonada.\n";
    }else
    {
        cout<<"\nno es matriz escalonada\n";
    }

    if (valorNucleo(M)!=-1)
    {
        cout<<"\nnucleo: "<<valorNucleo(M)<<endl;
    }else
    {
        cout<<"\nno tiene nucleo\n";
    }

    return 0;
}