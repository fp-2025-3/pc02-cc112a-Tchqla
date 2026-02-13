#include <iostream>
#include <cstring>
using namespace std;

struct Item
{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};

struct Pedido
{
    int numeroPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};

Item crearItem(const char* descripcion,int cantidad,double precio){

}

Pedido* crearPedido(int numero,const char* cliente,int cantidadItems){
    Pedido temp;temp.numeroPedido=numero;
    temp.cantidadItems=cantidadItems;
    temp.items=new Item[cantidadItems];
    int n=strlen(cliente);temp.nombreCliente=new char[n+1];
    strcpy(temp.nombreCliente,cliente);
}

double calcularTotal(const Pedido* p){
    for (int i = 0; i < p->cantidadItems; i++)
    {
        /* code */
    }
    
}

Item* itemMasCaro(Pedido* p);

void liberarPedido(Pedido* p);

int main(){

    return 0;
}