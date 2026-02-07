#include <iostream>
#include <cstring>
using namespace std;

void leer(char** nombres, int* tiempo, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"\ncorredor "<<i+1<<" (max. 20 caracteres): ";cin.getline(*(nombres+i),21);

        cout<<"tiempo (en segundos): ";cin>>*(tiempo+i);
        while (*(tiempo+i)<=0)
        {
            cout<<"tiempo (en segundos): ";cin>>*(tiempo+i);
        }
        cin.ignore();
    }
    
}

void ranking(char** &nombres, int* tiempo, int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (*(tiempo+j)>*(tiempo+j+1))
            {
                swap(*(tiempo+j),*(tiempo+j+1));
                swap(*(nombres+j),*(nombres+j+1));
            }
            
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"\ncorredor "<<i+1<<"°:\n"<<*(nombres+i);
        cout<<"\ntiempo: "<<*(tiempo+i)<<endl;
    }
    
    
}

int comparar(char* a, char* b){
    while (*a==*b && *a!='\0' && *b!='\0')
    {
        a++;b++;
    }
    
    return *a-*b;
}

int buscar(char** nombres, int n, char* key){
    for (int i = 0; i < n; i++)
    {
        if (comparar(*(nombres+i),key)==0)
        {
            return i;
        }
        
    }
    
    return -1;
}

void rango(char** nombres, int* tiempo, int n, int min, int max){
    for (int i = 0; i < n; i++)
    {
        if (*(tiempo+i)>=min && *(tiempo+i)<=max)
        {
            cout<<*(nombres+i)<<"\t--\t"<<*(tiempo+i)<<" segundos\n";
        }
        
    }
    
}

int main(){
    char** corredores=new char*[30];
    int tiempo[30], n=0, min, max;
    char* key=new char[21];

    cout<<"ingrese la cantidad de corredores (min. 1, max. 30): ";
    cin>>n;

    while (n<1 || n>30)
    {
        cout<<"ingrese la cantidad de corredores (min. 1, max. 30): ";
        cin>>n;
    }cin.ignore();

    for (int i = 0; i < n; i++)
    {
        corredores[i]=new char[21];
    }

    leer(corredores,tiempo,n);
    
    cout<<"\nRANKING FINAL";
    ranking(corredores,tiempo,n);

    cout<<"\ningrese nombre a buscar: ";cin.getline(key,21);

    int posicion=buscar(corredores,n,key);
    if(posicion==-1){
        cout<<"no existe el corredor\n";
    }else{
        cout<<"corredor encontrado\nposicion: "<<posicion+1<<" tiempo: "<<*(tiempo+posicion);
    }

    cout<<"\n\ningrese timepo minimo y maximo: ";cin>>min>>max;
    cout<<"\ncorredores en el rango ["<<min<<", "<<max<<"]:\n";
    rango(corredores,tiempo,n,min,max);

    for (int i = 0; i < n; i++)
    {
        delete[] corredores[i];
    }
    
    delete[] key; delete[] corredores;

    return 0;
}