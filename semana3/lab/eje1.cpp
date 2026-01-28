#include <iostream>
using namespace std;

int separar_palabras(char* texto, char* palabras[]){
    int i=0;
    char* p=texto;
    while (*p!='\0')
    {
        if ((p==texto && *p!=' ') || (*(p-1)==' ' && *p!=' '))
        {
            palabras[i]=p;
            i++;
        }
        p++;
    }
    
    return i;
}

int longitud_palabra(const char* p){//*(p+i)?? maybe debe ser asi para el arreglo palabra
    const char* str= p;
    while (*str!=' ' && *str!='\0')
    {
        str++;
    }
    
    return str-p;
}

void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl){
    for (char** i = palabras; i < palabras+n; i++)
    {
        if (longitud_palabra(*(i))<5)
        {
            *(cortas+nc)=*i;nc++;
        } else{
            *(largas+nl)=*i;nl++;
        }
    }
}

int comparar_palabras(const char* a, const char* b){
    while (*a==*b && *a!='\0' && *b!='\0')
    {
        a++;b++;
    }
    
    return *a-*b;
}

void my_swap(char** a, char** b){
    char* temp= *a;
    *a=*b;
    *b=temp;
}

void ordenar(char* v[], int n){
    for (char** i = v; i < v+n-1; i++)
    {
        for (char** j = i+1; j < v+n; j++)
        {
            if (comparar_palabras(*i,*j)>0)
            {
                /*char* temp= *i;
                *i=*j;
                *j=temp;*/
               my_swap(i,j);
            }
            
        }
        
    }
    
}

void imprimir_grupo(const char* titulo, char* v[], int n){
    while (*titulo!='\0')
    {
        cout<<*titulo;
        titulo++;
    }cout<<endl;

    for (int i = 0; i < n; i++)
    {
        char* p=*(v+i);

        while (*p!='\0' && *p!=' ')
        {
            cout<< *p;
            p++;
        }
        cout<<endl;
    }
}

int main(){
    char texto[300];
    char* palabra[60];
    char* cortas[60];
    char* largas[60];
    int nc=0, nl=0;

    cout<< "ingrese el texto a evaluar:\n";cin.getline(texto,300);

    int n=separar_palabras(texto,palabra);
    clasificar(palabra,n,cortas,nc,largas,nl);
    imprimir_grupo("palabras separadas:",palabra,n);
    cout<<"\n\n";
    imprimir_grupo("palabras cortas:",cortas,nc);
    cout<< "\n\n";
    imprimir_grupo("palabras largas:",largas,nl);
    ordenar(palabra,n);ordenar(cortas,nc);ordenar(largas,nl);
    cout<<"\n\n";
    imprimir_grupo("palabras en orden:",palabra,n);
    cout<<"\n\n";
    imprimir_grupo("cortas en orden:",cortas,nc);
    cout<<"\n\n";
    imprimir_grupo("largas en orden:",largas,nl);

    return 0;
}