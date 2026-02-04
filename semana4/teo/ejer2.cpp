#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void asignar(int** p,int n, int m){
    for (int i = 0; i < n; i++)
    {
        p[i]=new int[m];
    }
}

void llenado(int** p, int n, int m){
    for (int** i = p; i < p+n; i++)
    {
        for (int* j = *i; j< *i+m; j++)
        {
            *j=rand()%(100-(-100)+1)-100;
        }
        
    }
    
}

bool* validas_fila(int** p, int n, int m, int &c_fila){
    bool* fila_val=new bool[n];
    
    for (int** i = p; i < p+n; i++)
    {
        int a= i-p;int temp_fila=0;
        for (int* j = *i; j< *i+m; j++)
        {
            temp_fila+=*j;
            
        }
        
        if (temp_fila%2==0)
        {
            *(fila_val+a)=true;
            c_fila++;
        }else{
            *(fila_val+a)=false;
        }
        
    }

    return fila_val;
}

bool* validas_col(int** p,int n, int m, int &c_col){
    bool* col_val=new bool[m];

    for (int j = 0; j < m; j++)
    {
        int temp_col=*(*p+j);
        for (int i = 0; i< n; i++)
        {
            if (temp_col<*(*(p+i)+j))
            {
                temp_col=*(*(p+i)+j);
            }
            
        }
        
        if (temp_col>0)
        {
            *(col_val+j)=true;
            c_col++;
        }else{
            *(col_val+j)=false;
        }
        
    }

    return col_val;
}

void crear_filtrada(int** &p, int n, int m, bool* v_filas, bool* v_cols, int col, int filas){
    int** nue=new int*[col];
    asignar(nue,filas,col);

    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
}

int main(){
    srand(time(0));
    int n,m,c=0,f=0;
    cin>>n>>m;
    int** A= new int*[n];
    asignar(A,n,m);
    llenado(A,n,m);
    bool* col=validas_col(A,n,m,c);
    bool* fil=validas_fila(A,n,m,f);


    return 0;
}