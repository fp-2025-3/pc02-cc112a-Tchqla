#include <iostream>
using namespace std;

void asignar(float** p, int n, int k){
    for (int i = 0; i < k; i++)
    {
        *(p+i)=new float[n];
    }
}

void completar(float** p, int n, int k){
    for (int i = 0; i < n; i++)
    {
        while (*(*(p+k-1)+i)>=20 && *(*(p+k-1)+i)<=0)
        {
            cin>>*(*(p+k-1)+i);
        }
    }
    
}

void busq_minMax(float** p, int n, int k,float &max, float &min){
    for (float** i = p; i < p+k; i++)
    {
        for (float* j = *i; j < *i+n; j++)
        {
            if (max<*j)
            {
                max=*j;
            }
            if (min>*j)
            {
                min=*j;
            }
        }
        
    }
    
}

float* promedio(float** p, int n , int k){
    float* prom=new float[k]();
    for (float** i = p; i < p+k; i++)
    {
        int c= i-p;
        for (float* j = *i; j < *i+n; j++)
        {
            *(prom+c)+=*j;
        }
        
        *(prom+c)=*(prom+c)/n;
    }
    
    return prom;
}

void liberacion(float** &p,int k){
    for (int i = 0; i < k; i++)
    {
        delete[] *(p+i);
    }

    delete[] p;
    p=nullptr;
}

void redimencionar(float** &p, int n, int &k){
    k++;

    float** nuevo=new float*[k];
    asignar(nuevo,n,k);

    for (float** i = p; i < p+k-1; i++)
    {
        int I=i-p;
        for (float* j = *i; j < *i+n; j++)
        {
            int J=j-*i;
            *(*(nuevo+I)+J)=*j;
        }
        
    }
    
    liberacion(p,k-1);

    p=nuevo;
}

int main(){
    int n,k=1,opc;
    
    cout<<"ingrese la cantidad de notas: ";cin>>n;
    
    float** lista= new float*[k];

    asignar(lista,n,k);
    completar(lista,n,k);float max=lista[0][0], min=lista[0][0];
    cout<<endl;
    busq_minMax(lista,n,k,max,min);

    float* prom=promedio(lista,n,k);
    for (float* i = prom; i < prom+k; i++)
    {
        cout<<*i<<endl;
    }
    cout<<"maximo: "<<max<<"\tminimo: "<<min<<endl;
    delete[] prom;prom=nullptr;

    do
    {   
        cout<<"\n1. agregar un estudiante y sus notas.\n";
        cout<<"2. lista completa.'\n";
        cout<<"cualquier otro numero para salir.\n";
        cin >>opc;cout<<endl;

        switch (opc)
        {
        case 1:
            redimencionar(lista,n,k);
            completar(lista,n,k);

            busq_minMax(lista,n,k,max,min);
            prom=promedio(lista,n,k);

            cout<<"\npromedios de alumnos:\n";
            for (float* i = prom; i < prom+k; i++)
            {
                cout<<*i<<endl;
            }
            cout<<"maximo: "<<max<<"\tminimo: "<<min<<endl;

            delete[] prom;prom=nullptr;
            break;

        case 2:
            cout<<"lista completa:\n";
            
            for (float** i = lista; i < lista+k; i++)
            {
                int a=i-lista;cout<<"\nalumno "<<a<<"\t";
                for (float* j = *i; j < *i+n; j++)
                {
                    cout<<*j<<" ";
                }
                
            }
            break;
                
        default:
            break;
        }
    } while(opc<3);

    liberacion(lista,k);

    return 0;
}