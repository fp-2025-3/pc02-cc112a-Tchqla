#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    char** funcion=new char*[21];

    for (char** i = funcion; i < funcion+21; i++)
    {
        *i=new char[80];
        for (char* j = *i; j < *i+80; j++)
        {
            *j=' ';
        }
    }

    double k=(2*M_PI)/(80-1);
    for (int i = 0; i < 81; i++)
    {
        double x=0+i*k;
        double y=sin(5*x);

        int en_y=(int)round((1-y)*(19-1)/2.0)+1;

        funcion[en_y][i]='*';
    }
    
    for (int i = 0; i < 21; i++)
    {
        if (funcion[i][0]==' ')
        {
            funcion[i][0]='|';
        } 
    }
    
    for (int i = 0; i < 80; i++)
    {
        if (funcion[10][i]==' ')
        {
            funcion[10][i]='-';
        }
    }

    ofstream file("output/grafico.txt");

    if (!file)
    {
        cerr<<"no se pudo abrir el archivo\n";
        return 1;
    }
    
    for (char** i = funcion; i < funcion+21; i++)
    {
        for (char* j = *i; j < *i+80; j++)
        {
            file<<*j;
        }
        file<<endl;
    }
    
    file.close();
    
    for (char** i = funcion; i < funcion+21; i++)
    {
        delete[] *i;
    }
    
    delete[] funcion;

    return 0;
}