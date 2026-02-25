#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream archivo("input/baseUNI.txt");

    if (!archivo)
    {
        cerr<<"no se pudo abrir el archivo";
        return 1;
    }
    
    string linea,nombreMax;
    double promMax=-1;

    cout<<"Num\tApellidos\tNombre\tNota1\tNota2\tPromedio\n";
    while (getline(archivo,linea,'.'))
    {
        int num=stoi(linea);
        cout<<num<<"\t";

        string apellidos;
        getline(archivo,apellidos,',');
        cout<<apellidos<<"\t";

        string nombre;
        getline(archivo,nombre,'-');
        cout<<nombre<<"\t";

        getline(archivo,linea,'-');
        double n1=stod(linea);
        cout<<n1<<"\t";

        getline(archivo,linea);
        double n2=stod(linea);
        cout<<n2<<"\t";

        double prom=(n1+n2)/2.0;
        cout<<prom<<"\n";

        if (prom>promMax)
        {
            promMax=prom;
            nombreMax=nombre+" "+apellidos;
        }
    }
    
    cout<<"\nel promedio maximo: "<<promMax;
    cout<<"\nalumno: "<<nombreMax<<endl;

    return 0;
}