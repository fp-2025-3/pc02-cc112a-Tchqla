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
    Item temp;
    int n=strlen(descripcion)+1;
    temp.descripcion=new char[n];
    strcpy(temp.descripcion,descripcion);

    temp.cantidad=cantidad;temp.precioUnitario=precio;

    return temp;
}

Pedido* crearPedido(int numero,const char* cliente,int cantidadItems){
    Pedido* temp=new Pedido;temp->numeroPedido=numero;int n=strlen(cliente)+1;
    temp->nombreCliente=new char[n];strcpy(temp->nombreCliente,cliente);

    temp->cantidadItems=cantidadItems;
    temp->items=new Item[cantidadItems];
    
    int cant=1;double precio=100;
    for (Item* i = temp->items; i < temp->items+cantidadItems; i++)
    {
        char desc[30];cin.getline(desc,30);
        
        *i=crearItem(desc,cant,precio);
        cant++;precio+=100;
    }
    
    return temp;
}

double calcularTotal(const Pedido* p){
    double total=0;
    for (int i = 0; i < p->cantidadItems; i++)
    {
        total+=p->items[i].precioUnitario*p->items[i].cantidad;
    }
    
    return total;
}

Item* itemMasCaro(Pedido* p){
    Item* caro=p->items;

    for (Item* j = p->items; j < p->items+p->cantidadItems; j++)
    {
        if (j->precioUnitario>caro->precioUnitario)
        {
            caro=j;
        }
    }
        
    return caro;
}

void liberarPedido(Pedido* p){
    for (Item* i = p->items; i < p->items+p->cantidadItems; i++)
    {
        delete[] i->descripcion;
    }
    
    delete[] p->items;
    delete[] p->nombreCliente;
    delete p;
}

int main(){
    Pedido* pedido=crearPedido(101,"carlos perez",3);

    cout<<"pedido N°: "<<pedido->numeroPedido<<"\ncliente: "<<pedido->nombreCliente<<"\n\nitems:\n";
    for (Item* i = pedido->items; i < pedido->items+pedido->cantidadItems; i++)
    {
        cout<<"- "<<i->descripcion<<" | Cant: "<<i->cantidad<<" | Precio: "<<i->precioUnitario<<endl;
    }
    
    double total=calcularTotal(pedido);cout<<"total: "<<total<<endl;

    Item* caro=itemMasCaro(pedido);
    cout<<"item mas caro: "<<caro->descripcion<<" | Precio: "<<caro->precioUnitario<<endl;

    liberarPedido(pedido);

    return 0;
}