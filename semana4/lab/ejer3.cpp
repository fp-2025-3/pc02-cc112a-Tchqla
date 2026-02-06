#include <iostream>
using namespace std;

/*void seleccion(int arr[], int n) {
    for(int i = 0; i < n -1; ++i) {
        int indMin = i;
        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[indMin]) {
                indMin = j; 
            }
        }

        swap(arr[i],arr[indMin]);
    }
}

void insercion(int arr[], int n) {
    for (int i = 1; i < n ; ++i) {
        int temp = arr[i];
        int j = i -1;

        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;

    }
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}*/

void leerDatos(int codi[],int faltas[], float notas[], int N){
    for (int i = 0; i < N; i++)
    {
        cout<<"\nalumno "<<i+1<<":\ncodigo: ";cin>>codi[i];
        cout<<"nota final: ";cin>>notas[i];
        cout<<"faltas: ";cin>>faltas[i];
    }
    
}

void ordenarPorNota(int codi[],int faltas[], float notas[], int N){
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-i-1; j++)
        {
            if (notas[j]<notas[j+1])
            {
                swap(notas[j],notas[j+1]);
                swap(faltas[j],faltas[j+1]);
                swap(codi[j],codi[j+1]);
            }
            else if (notas[j]==notas[j+1] && faltas[j]>faltas[j+1])
            {
                swap(faltas[j],faltas[j+1]);
                swap(codi[j],codi[j+1]);
            }

        }
        
    }
}

float prome(float notas[],int n){
    float prom=0;

    for (int i = 0; i < n; i++)
    {
        prom+=notas[i];
    }
    
    return prom/n;
}

int desaprobados(float notas[], int n){
    int cont=0;
    for (int i = 0; i < n; i++)
    {
        if (notas[i]<10)
        {
            cont++;
        }
        
    }
    
    return cont;
}

int buscar(int codigo[], int n, int k){
    for (int i = 0; i < n; i++)
    {
        if (codigo[i]==k)
        {
            return i+1;
        }
        
    }
    
    return -1;
}

void ranking(int codi[],int faltas[], float notas[], int N){
    cout<<"primeros 5 puestos:\n";
    for (int i = 0; i < 5; i++)
    {
        cout<<endl<<i+1<<"°\ncodigo: "<<codi[i]<<endl;
        cout<<"nota final: "<<notas[i]<<endl;
        cout<<"faltas: "<<faltas[i]<<endl;
    }
    
    cout<<"\npromedio del curso: "<<prome(notas,N)<<endl;

    cout<<"cantidad de desaprobados (nota < 10): "<<desaprobados(notas,N)<<endl;
}

void ordenarCodigo(int codi[],int faltas[], float notas[], int N){
    for(int i = 0; i < N -1; ++i) {
        int indMin = i;
        for(int j = i + 1; j < N; ++j) {
            if(codi[j] < codi[indMin]) {
                indMin = j; 
            }
        }

        swap(codi[i],codi[indMin]);
        swap(notas[i],notas[indMin]);
        swap(faltas[i],faltas[indMin]);
    }
}

int busquedaBinaria(int codigo[], int n, int clave){
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (codigo[mid] == clave) {
            return mid;
        } else if (codigo[mid] < clave) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int N=10, key;
    int codigo[N];
    float nota[N];
    int faltas[N];

    leerDatos(codigo,faltas,nota,N);

    ordenarPorNota(codigo,faltas,nota,N);
    ranking(codigo,faltas,nota,N);

    cout<<"\ningrese codigo a buscar: ";
    cin>>key;
    int posicion=buscar(codigo,N,key);
    if (posicion==-1)
    {
        cout<<"no existe el codigo introducido\n";
    }else{
        cout<<endl<<posicion<<"°\ncodigo: "<<codigo[posicion-1]<<endl;
        cout<<"nota final: "<<nota[posicion-1]<<endl;
        cout<<"faltas: "<<faltas[posicion-1]<<endl;
    }

    ordenarCodigo(codigo,faltas,nota,N);

    posicion=buscar(codigo,N,key);

    return 0;
}