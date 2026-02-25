#include <iostream>
#include <fstream>
using namespace std;

struct Venta
{
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

void vendedor(Venta* ventas,int cant){
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    
}

int main(){
    int cantidad;
    double montoTotal=0;
    ifstream file("input/ventas.dat",ios::binary);

    if (!file)
    {
        cerr<<"error al abrir el archivo\n";
        return 1;
    }
    
    file.read((char*)&cantidad,sizeof(int));
    
    Venta* ventas=new Venta[cantidad];
    double* totalVendedor=new double[cantidad]();
    
    for (Venta* i = ventas; i < ventas+cantidad; i++)
    {
        file.read((char*)i,sizeof(Venta));
        montoTotal+=i->cantidad*i->precioUnitario;

    }

    cout<<ventas->cantidad<<" "<<ventas->idProducto<<" "<<ventas->idVendedor<<" "<<ventas->idVenta<<endl;

    delete[] ventas;ventas=nullptr;

    return 0;
}