#include <iostream>
#include <fstream>
using namespace std;

struct Producto
{
    int id,stock;
    char nombre[30];
    double precio;
    bool activo;
};

int buscarProductoID(const char* nombre,int IDbuscar){
    ifstream archivo(nombre,ios::binary);

    if (!archivo)
    {
        cerr<<"error al abrir el archivo\n";
        return -1;
    }

    Producto p;
    int i=0;

    while (archivo.read((char*)&p,sizeof(Producto)))
    {
        if (p.id==IDbuscar) 
        {
            return i;
        }
        i++;
    }
    
}

void registrarProducto(const char* nombreArchivo){
    Producto p;

    cout<<"ingrese ID:";cin>>p.id;

    if (buscarProductoID(nombreArchivo,p.id)!=-1)
    {
        cerr<<"ERROR: el id ya existe o no se pudo abrir el archivo\n";
        return;
    }
    
    cin.ignore();
    cout<<"ingrese el nombre: ";cin.getline(p.nombre,30);

    cout<<"ingrese el precio: ";cin>>p.precio;

    if (p.stock<0)
    {
        cout<<"precio invalido\n";
        return;
    }
    
    p.activo=true;

    ofstream archivo(nombreArchivo,ios::binary);

    if (!archivo)
    {
        cerr<<"no se pudo abrir el archivo\n";
        return;
    }

    archivo.write((char*)&p,sizeof(Producto));
    archivo.close();
    
}

int main(){

    
    return 0;
}