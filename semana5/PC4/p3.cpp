#include <iostream>
#include <cstring>
using namespace std;

struct Producto
{
    int codigo;
    char* nombre;
    double precio;
    int stock;
};

Producto crearProducto(int codigo, const char* nombre,double precio, int stock){
    Producto temp;

    int n=strlen(nombre);
    temp.nombre=new char[n+1];
    strcpy(temp.nombre,nombre);

    temp.codigo=codigo;
    temp.precio=precio;
    temp.stock=stock;

    return temp;
}

Producto* crearInventario(int n){
    Producto* temp=new Producto[n];
    char* nom=new char[30];

    for (Producto* i = temp; i < temp+n; i++)
    {
        cout<<"agregue nombre al producto"<<i-temp+1<<"°: ";
        cin.getline(nom,30);
        *i=crearProducto(100+(i-temp),nom,10.5*(1+i-temp),5*((i-temp)+1));
    }
    
    return temp;
}

Producto* buscarProducto(Producto* inventario,int n,int codigoBuscado){
    for (Producto* i = inventario; i < inventario+n; i++)
    {
        if (i->codigo==codigoBuscado)
        {
            return i;
        }
        
    }
    
    return nullptr;
}

void liberarInventario(Producto* inventario, int n){
    cout<<"\tINVENTARIO\n";
    for (Producto* i = inventario; i < inventario+n; i++)
    {
        cout<<"Codigo: "<<i->codigo<<" | Nombre: "<<i->nombre<<" | Precio: "<<i->precio<<" | Stock: "<<i->stock<<endl;
    }

    int m;
    cout<<"\nBuscando producto con codigo ";cin>>m;
    Producto* temp=buscarProducto(inventario,n,m);
    
    if (temp!=nullptr)
    {
        cout<<"Producto encontrado: "<<temp->nombre<<" | Precio: "<<temp->precio<<endl;
    }
    

    for (Producto* i = inventario; i < inventario+n; i++)
    {
        delete[] i->nombre;
    }
    
    delete[] inventario;
}

int main(){
    Producto* inventario=crearInventario(5);

    liberarInventario(inventario,5);

    return 0;
}