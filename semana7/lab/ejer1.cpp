#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream archivo1;
    ifstream archivo2;
    ofstream salida("output/nombreM.txt");

    archivo1.open("input/archivo1.txt");
    archivo2.open("input/archivo2.txt");

    if (!archivo1 || !archivo2 || !salida)
    {
        cerr<<"error al abrir algun archivo\n";
        return 1;
    }
    
    int n1,n2;
    archivo1>>n1;archivo2>>n2;

    while (n1!=-1 && n2!=-1)
    {
        if (n1<n2)
        {
            salida<<n1<<endl;
            archivo1>>n1;
        }else{
            salida<<n2<<endl;   
            archivo2>>n2;
        }
    }

    archivo1.close();archivo2.close();salida.close();

    return 0;
}