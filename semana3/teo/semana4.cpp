#include <iostream>
#include <cstring>
using namespace std;

void imprimir(const char* p){
    while (*p!='\0')
    {
        cout << *p;
        p++;
    }
    
}

int my_strlen(const char* str){
    int c=0;
    while (*str!='\0')
    {
        str++;
        c++;
    }
    
    return c;
}



int main(){
    char texto[]="hola";
    char* p=texto;
    
    cout << my_strlen(p)<<endl<< strlen(p)<<endl;

    cout << p <<endl;
    return 0;
}