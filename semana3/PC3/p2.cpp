#include <iostream>
using namespace std;

int num_vocal(char* cadena){
    char* p[30];int np=0, nv=0;
    char* temp=cadena;

    while (*temp!='\0')
    {
        if ((temp==cadena && *temp!=' ') || (*(temp-1)==' ' && *temp!=' '))
        {
            *(p+np)=temp;
            np++;
        }
        temp++;
    }

    for (char** i = p; i < (p+np); i++)
    {
        if (**i!='a' && **i!='e' && **i!='i' && **i!='o' && **i!='u')
        {
            if (**i!='A' && **i!='E' && **i!='I' && **i!='O' && **i!='U')
            {
                continue;
            }
            else{
                nv++;
            }
            
        }
        else{
            nv++;
        }
        
    }
    
    return nv;
}

int main(){
    char texto[50]="    Este es   un ejemplo en c++  END'";
    char* p=texto;

    cout<<"texto: ";
    while (*p!='\0')
    {
        cout<<*p;p++;
    }cout<<endl;
    
    int n=num_vocal(texto);
    cout<<"numero de palabras que comienzan con vocal: "<<n<< endl;

    return 0;
}