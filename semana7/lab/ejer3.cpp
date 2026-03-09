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

//structs auxiliares
struct Auxiliar1
{
    int idVendedor;
    double venta;
};

struct Auxiliar2
{
    int idProducto;
    int cantidad;
};

Auxiliar1 mejorVendedor(Venta* ventas,int cant){
    Auxiliar1* resumen=new Auxiliar1[cant]();
    int c=1;
    resumen[0].idVendedor=ventas[0].idVendedor;
    resumen[0].venta=ventas[0].cantidad*ventas[0].precioUnitario;

    int max=0;
    for (int i = 1; i < cant; i++)
    {
        int id_actual=ventas[i].idVendedor;
        bool nuevo_id=false;

        for (int j = 1; j < c; j++)
        {
            if (resumen[j].idVendedor==id_actual)
            {
                resumen[j].venta+=ventas[i].cantidad*ventas[i].precioUnitario;
                nuevo_id=true;
                break;
            }
            
        }

        if (!nuevo_id)
        {
            resumen[c].idVendedor=id_actual;
            resumen[c].venta=ventas[i].cantidad*ventas[i].precioUnitario;
            c++;
        }
    }
    
    Auxiliar1 vendedor;
    double cantidadMax=-1;
    int mejor_producto=-1;
    for (Auxiliar1* i = resumen; i < resumen+c ; i++)
    {
        if (i->venta>cantidadMax)
        {
            cantidadMax=i->venta;
            mejor_producto=i->idVendedor;
        }
    }
    
    delete[] resumen;resumen=nullptr;

    vendedor.idVendedor=mejor_producto;vendedor.venta=cantidadMax;
    
    return vendedor;
}

Auxiliar2 productoMasVendido(Venta* ventas,int cant){
    Auxiliar2* resumen=new Auxiliar2[cant]();
    int c=1;
    resumen[0].idProducto=ventas[0].idProducto;
    resumen[0].cantidad=ventas[0].cantidad;

    int max=0;
    for (int i = 1; i < cant; i++)
    {
        int id_actual=ventas[i].idProducto;
        bool nuevo_id=false;

        for (int j = 1; j < c; j++)
        {
            if (resumen[j].idProducto==id_actual)
            {
                resumen[j].cantidad+=ventas[i].cantidad;
                nuevo_id=true;
                break;
            }
            
        }

        if (!nuevo_id)
        {
            resumen[c].idProducto=id_actual;
            resumen[c].cantidad=ventas[i].cantidad;
            c++;
        }
    }
    
    Auxiliar2 producto;
    int cantidadMax=-1;
    int mejor_producto=-1;
    for (Auxiliar2* i = resumen; i < resumen+c ; i++)
    {
        if (i->cantidad>cantidadMax)
        {
            cantidadMax=i->cantidad;
            mejor_producto=i->idProducto;
        }
    }

    delete[] resumen;

    producto.idProducto=mejor_producto;producto.cantidad=cantidadMax;
    
    return producto;
}

Venta* ventasSospechosas(Venta* ventas, int cant,int &c){
    Venta* temp=new Venta[cant];

    for (int i = 0; i < cant; i++)
    {
        if (ventas[i].cantidad>100)
        {
            temp[c]=ventas[i];
            c++;
        }
        
    }
    
    Venta* sospechosas=new Venta[c];
    for (int i = 0; i < c; i++)
    {
        sospechosas[i]=temp[i];
    }
    
    delete[] temp;

    return sospechosas;
}

int main(){
    int registros;
    double montoTotal=0;
    ifstream file("input/ventas.dat",ios::binary);

    if (!file)
    {
        cerr<<"error al abrir el archivo\n";
        return 1;
    }
    
    file.read((char*)&registros,sizeof(int));
    
    Venta* ventas=new Venta[registros];
    
    for (Venta* i = ventas; i < ventas+registros; i++)
    {
        file.read((char*)i,sizeof(Venta));
        montoTotal+=i->cantidad*i->precioUnitario;
    }

    ofstream f("output/reporte.txt");
    
    if (!f)
    {
        cerr<<"error al abrir el archivo\n";
        return 1;
    }

    int sospechosa=0;
    Auxiliar1 mejor_vendedor=mejorVendedor(ventas,registros);
    Auxiliar2 mejor_producto=productoMasVendido(ventas,registros);
    Venta* sospe=ventasSospechosas(ventas,registros,sospechosa);
    
    f<<"---REPORTE GENERAL DE VENTAS---\n"<<"\ntotal de registros: "<<registros
     <<"\n\nMONTO TOTAL VENDIDO:\nS/. "<<montoTotal
     <<"\n\n\n--------------------------------\n"
     <<"VENDEDOR CON MAYOR RECAUDACION\nID Vendedor: "<<mejor_vendedor.idVendedor
     <<"\ntotal vendido: "<<mejor_vendedor.venta
     <<"\n\n\n--------------------------------\n"
     <<"PRODUCTO MAS VENDIDO:\nID Producto: "<<mejor_producto.idProducto
     <<"\ntotal unidades vendidas: "<<mejor_producto.cantidad
     <<"\n\n\n--------------------------------\n"
     <<"VENTAS SOSPECHOSAS (cantidad>100):\n\n";

    for (Venta* i = sospe; i < sospe+sospechosa; i++)
    {
        f<<"ID Venta: "<<i->idVenta<<" | Vendedor: "<<i->idVendedor<<" | Producto: "<<i->idProducto<<" | Cantidad: "<<i->cantidad<<endl;
    }
    
    file.close();
    f.close();

    delete[] ventas;ventas=nullptr;
    delete[] sospe;sospe=nullptr;

    return 0;
}