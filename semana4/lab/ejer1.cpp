#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char* leer(){
    char temp[1000];
    cout<<"ingrese su frase: ";
    cin.getline(temp,1000);

    int lon=strlen(temp);

    char* frase=new char[lon+1];
    
    for (int i = 0; i <= lon; i++)
    {
        *(frase+i)=*(temp+i);
    }

    return frase;
}

char* normaliza(char* frase){
    char temp[1000];int j=0;
    char* src=frase;

    while (*src!='\0' && isspace(*src))
    {
        src++;
    }
    
    bool espPrev=false;
    while(*(src)!='\0'){
        if (!isspace(*src))
        {
            *(temp+j)=tolower(*src);
            j++;
            espPrev=false;
        }else{
            if (!espPrev)
            {
                temp[j]=' ';
                j++;
                espPrev=true;
            }
            
        }
        src++;
    }

    if (temp[j-1]==' ' && j>0)
    {
        j--;
    }

    temp[j]='\0';

    char* normal=new char[j+1];
    strcpy(normal,temp);

    return normal;
}

int contar(char* frase){
    int con=0;
    bool palabra=false;

    for (int i = 0; frase[i]!='\0'; i++)
    {
        if (!isspace(frase[i]) && !palabra)
        {
            con++;
            palabra=true;
        }
        if (isspace(frase[i]))
        {
            palabra=false;
        }
        
    }
    
    return con;
}

char** separar(char* frase, int n){
    char** palabras=new char*[n];
    char* temp=frase;int j=0;

    while (*temp!='\0')
    {
        while (isspace(*temp))
        {
            temp++;
        }
        
        int lon=0;
        int ini=temp-frase;

        while (*temp!='\0' && !isspace(*temp))
        {
            temp++;lon++;
        }
        
        palabras[j]=new char[lon+1];

        for (int i = 0; i < lon; i++)
        {
            palabras[j][i]=*(frase+ini+i);
        }
        
        palabras[j][lon]='\0';
        j++;
    }
    
    return palabras;
}

void imprimi(char** palabras, int n){
    cout<<endl;
    for (char** i = palabras; i < palabras+n; i++)
    {
        cout<< *i<<"\t"<<strlen(*i)<<endl;        
    }
    
}

void liberar(char** palabras, int n){
    for (int i = 0; i < n; i++)
    {
        delete[] palabras[i];
    }
    
    delete[] palabras;
}

int main(){
    char* frase=leer();cout<<"\nnormalizado:\n";

    char* normal=normaliza(frase);

    int contPalabras=contar(normal);

    char** palabras=separar(normal,contPalabras);

    cout<<normal<<endl;

    imprimi(palabras,contPalabras);

    delete[] frase;frase=nullptr;

    delete[] normal;normal=nullptr;

    liberar(palabras,contPalabras);
    palabras=nullptr;

    return 0;
}