#include <iostream>
#include <cstring>
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
    char temp[100];int i=0,j=0;

    while(*temp!='\0'){
        if (!isspace(frase[i]))
        {
            temp[j]=tolower(frase[i]);
            j++;
        }else{
            temp[j]=' ';
            j++;
        }
        i++;
    }

    temp[j]='\0';

    char* normal=new char[j+1];
    strcpy(normal,temp);

    return normal;
}

int main(){


    return 0;
}