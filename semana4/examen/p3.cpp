#include <iostream>
using namespace std;
const int N=4;

bool esFilaDominanteEstricta(int (*M)[N], int f){
    for (int j = 0; j < N; j++)
    {
        int temp=*(*(M+f)+j);

        for (int k = 0; k < N; k++)
        {
            if (k==f)
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

bool esFilaFuertementeDominante(int (*M)[N], int f){
    if(!esFilaDominanteEstricta(M,f)){
        return false;
    }

    int temp[N]={};
    for (int i = 0; i < N; i++)
    {
        
        for (int j = 0; j < N; j++)
        {
            *(temp+i)+=*(*(M+i)+j);
        }
        
    }
    
    for (int j = 0; j < N; j++)
    {
        int fila=*(temp+f);
        for (int k = 0; k < N; k++)
        {
            if (k==f)
            {
                continue;
            }
            
            if (fila<*(temp+k))
            {
                return false;
            }

        }

    }

    return true;
}

int main(){
    int M[N][N]={{2,3,1,4},{1,2,3,2},{5,6,7,8},{0,1,2,1}};
    cout<<"Fila\tDominante Estricta\tFuertemente Dominante\n";
    cout<<"-----------------------------------------------------------------\n";
    for (int i = 0; i < N; i++)
    {
        cout<<i<<"\t";
        if (esFilaDominanteEstricta(M,i))
        {
            cout<<"SI";
        }else{
            cout<<"NO";
        }
        cout<<"\t\t\t";
        if (esFilaFuertementeDominante(M,i))
        {
            cout<<"SI";
        }else{
            cout<<"NO";
        }cout<<endl;
        
    }
    

    return 0;
}