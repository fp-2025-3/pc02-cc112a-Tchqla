#include <iostream>
#include <cstring>
using namespace std;

int separar_palabras_strtok(char* texto, char* palabras[]){
    int i=0;
    char* token= strtok( texto," ");

    while (token!=nullptr)
    {
        *(palabras+i)=strtok(token," ");
        token++;i++;
    }
    
    return i;
}

int main(){
    char frase[] = "aprender punteros exige mucha logica y practica";

    return 0;
}