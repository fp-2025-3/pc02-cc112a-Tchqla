#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Venta
{
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

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

double montoTotal(Venta* ventas,int cant){
    double temp=0;
    for (Venta* i = ventas; i < ventas+cant; i++)
    {
        temp+=i->cantidad*i->precioUnitario;
    }
    
    return temp;
}

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

        for (int j = 0; j < c; j++)
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
    int productoRecaudacion=-1;
    for (Auxiliar1* i = resumen; i < resumen+c ; i++)
    {
        if (i->venta>cantidadMax)
        {
            cantidadMax=i->venta;
            productoRecaudacion=i->idVendedor;
        }
    }
    
    delete[] resumen;resumen=nullptr;

    vendedor.idVendedor=productoRecaudacion;vendedor.venta=cantidadMax;
    
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

        for (int j = 0; j < c; j++)
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
    int productoRecaudacion=-1;
    for (Auxiliar2* i = resumen; i < resumen+c ; i++)
    {
        if (i->cantidad>cantidadMax)
        {
            cantidadMax=i->cantidad;
            productoRecaudacion=i->idProducto;
        }
    }

    delete[] resumen;

    producto.idProducto=productoRecaudacion;producto.cantidad=cantidadMax;
    
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
    ifstream file("input/ventas.dat",ios::binary);

    if (!file)
    {
        cerr<<"error al abrir el archivo\n";
        return 1;
    }
    
    file.seekg(0,ios::end);
    int n=file.tellg()/sizeof(Venta);

    Venta* ventas=new Venta[n];file.seekg(0,ios::beg);

    file.read((char*)ventas,sizeof(Venta)*n);

    Auxiliar1 VendedorRecaudacion=mejorVendedor(ventas,n);
    Auxiliar2 productoRecaudacion=productoMasVendido(ventas,n);
    int sos=0;Venta* sopechosa=ventasSospechosas(ventas,n,sos);
    double total=montoTotal(ventas,n);

    file.close();

    ofstream f("output/reporte.txt");

    if (!f)
    {
        cerr<<"error al abrir el archivo\n";
        return 1;
    }

    f<<"---REPORTE GENERAL DE VENTAS---\n"<<"\ntotal de registros: "<<n
     <<"\n\nMONTO TOTAL VENDIDO:\nS/. "<<fixed<<setprecision(2)<<total
     <<"\n\n\n--------------------------------\n"
     <<"VENDEDOR CON MAYOR RECAUDACION\nID Vendedor: "<<VendedorRecaudacion.idVendedor
     <<"\ntotal vendido: "<<VendedorRecaudacion.venta
     <<"\n\n\n--------------------------------\n"
     <<"PRODUCTO MAS VENDIDO:\nID Producto: "<<productoRecaudacion.idProducto
     <<"\ntotal unidades vendidas: "<<productoRecaudacion.cantidad
     <<"\n\n\n--------------------------------\n"
     <<"VENTAS SOSPECHOSAS (cantidad>100):\n\n";

    for (Venta* i = sopechosa; i < sopechosa+sos; i++)
    {
        f<<"ID Venta: "<<i->idVenta<<" | Vendedor: "<<i->idVendedor<<" | Producto: "<<i->idProducto<<" | Cantidad: "<<i->cantidad<<endl;
    }

    f.close();
    
    delete[] ventas;
    delete[] sopechosa;

    return 0;
}