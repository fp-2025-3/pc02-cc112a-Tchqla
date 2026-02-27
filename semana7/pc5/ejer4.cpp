#include <iostream>
#include <fstream>
using namespace std;

struct Venta
{
    int idVenta;
    int idVenderor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int main(){
    ifstream file("input/ventas.dat",ios::binary);

    if (!file)
    {
        cerr<<"error al abrir el archivo\n";
        return 1;
    }
    

    return 0;
}