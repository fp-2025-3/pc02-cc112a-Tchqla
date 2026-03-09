#include <iostream>
#include <fstream>
using namespace std;

const int dias=7;

int main(){
    ofstream archivo("ventas.txt",ios::app);

    if (!archivo)
    {
        cerr<<"error al abrir"<<endl;
        return 1;
    }
    
    double total=0;
    double myVenta;
    double meVenta;

    double venta;
    for (int i = 1; i <= dias; i++)
    {
        cout<<"ingrese la venta del dia: ";cin>>venta;

        archivo<<venta<<endl;
        total+=venta;

        if (i==1)
        {
            myVenta=venta;meVenta=venta;
        }else if (venta>myVenta)
        {
            myVenta=venta;
        }else if (meVenta>venta){
            meVenta=venta;
        }
        
    }
    
    archivo<<"-------------------------\nRESUMEN\n";
    archivo<<"total: "<<total<<endl;
    
    double prom=total/dias;
    archivo<<"promedio: "<<prom<<"\nMayor venta: "<<myVenta<<"\nMenor venta: "<<meVenta;

    archivo.close();

    return 0;
}