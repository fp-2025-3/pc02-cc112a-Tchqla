#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Pasajero
{
    int dni;
    char nombre[50];
};

struct Asiento
{
    int numero;
    bool reservado;
    Pasajero* pasajero;
};

struct NodoReserva
{
    Pasajero Pasajero;
    int numeroAsiento;
    NodoReserva* siguiente;
};

struct Vuelo
{
    char codigo[10];
    char destino[50];
    int capacidad;
    Asiento* asientos;
    NodoReserva* listaReservas;
};

/* 1 */
Vuelo crearVuelo(){
    Vuelo vuelo;

    cout<<"ingrese el codigo del vuelo: ";cin.getline(vuelo.codigo,10);
    cout<<"ingrese el destino del vuelo: ";cin.getline(vuelo.destino,50);
    cout<<"ingrese la capacidad del vuelo: ";cin>>vuelo.capacidad;
    cin.ignore();

    vuelo.asientos=new Asiento[vuelo.capacidad]; vuelo.listaReservas=nullptr;
    
    for (Asiento* i = vuelo.asientos; i < vuelo.asientos+vuelo.capacidad; i++)
    {
        int c=i-vuelo.asientos;
        i->numero=c+1;
        i->reservado=false;
        i->pasajero=nullptr;
    }
    
    return vuelo;
}

/* 2 */
void mostrarAsientos(Vuelo vuelo){
    cout<<"vuelo: "<<vuelo.codigo<<" - "<<vuelo.destino<<"\n\nasientos:\n";

    for (Asiento* i = vuelo.asientos; i < vuelo.asientos+vuelo.capacidad; i++)
    {
        cout<<vuelo.asientos->numero;
        if (i->reservado)
        {
            cout<<" [x]\n";
        }else{
            cout<<" [ ]\n";
        }
    }
}

/* 3 */
void reservarAsiento(Vuelo &vuelo){
    int dni, num_asiento;char nombre[50];

    cout<<"ingrese su dni: "; cin>>dni;
    cin.ignore();
    cout<<"ingrese su nombre: ";cin.getline(nombre,50);
    NodoReserva* actual=vuelo.listaReservas;

    while (actual!=nullptr)
    {
        if (actual->Pasajero.dni==dni)
        {
            cout<<"ya reservo en este vuelo\n";
            return;
        }
        actual=actual->siguiente;
    }
    
    bool asientoValido=false;
    while (!asientoValido)
    {
        cout<<"ingrese un numero de asiento valido (capacidad max = "<<vuelo.capacidad<<" ): ";
        cin>>num_asiento;

        if (num_asiento>0 && num_asiento<=vuelo.capacidad)
        {
            if (!vuelo.asientos[num_asiento-1].reservado)
            {
                cout<<"el asiento esta libre\n";
                asientoValido=true;
            }else{
                cout<<" el asiento esta ocupado\n";
            }
        }
    }
    
    Pasajero* nuevo=new Pasajero;
    nuevo->dni=dni;strcpy(nuevo->nombre,nombre);
    vuelo.asientos[num_asiento-1].pasajero=nuevo;
    vuelo.asientos[num_asiento-1].reservado=true;
    
    NodoReserva* new_nodo=new NodoReserva;
    new_nodo->Pasajero.dni=dni;
    strcpy(new_nodo->Pasajero.nombre,nombre);
    new_nodo->numeroAsiento=num_asiento;

    new_nodo->siguiente=vuelo.listaReservas;
    vuelo.listaReservas=new_nodo;
}

/* 4 */
void cancelarReserva(Vuelo &vuelo, int dni){
    NodoReserva* actual=vuelo.listaReservas;
    NodoReserva* anterior=nullptr;

    while (actual!=nullptr && actual->Pasajero.dni!=dni)
    {    
        anterior=actual;
        actual=actual->siguiente;
    }
    
    if (actual==nullptr)
    {
        cout<<"el dni no existe en la lista\n";
        return;
    }
    
    int i=actual->numeroAsiento-1;
    vuelo.asientos[i].reservado=false;
    delete vuelo.asientos[i].pasajero;
    vuelo.asientos[i].pasajero=nullptr;

    if (anterior==nullptr)
    {
        vuelo.listaReservas=actual->siguiente;
    }else{
        anterior->siguiente=actual->siguiente;
    }
    
    delete actual;
}

/* 5 */
void recorrerMostrar(Vuelo vuelo){
    cout<<"\tDNI\t-\tNombre\t-\tAsiento\n";
    while (vuelo.listaReservas!=nullptr)
    {
        cout<<vuelo.listaReservas->Pasajero.dni<<" - "<<vuelo.listaReservas->Pasajero.nombre<<" - "<<vuelo.listaReservas->numeroAsiento<<endl;
        vuelo.listaReservas=vuelo.listaReservas->siguiente;
    }
    
}

/* 6 */
void mostrarEstadisticas(Vuelo vuelo){
    int asientos=vuelo.capacidad,ocupados=0,libres=0;
    double ocupacion;

    for (Asiento* i = vuelo.asientos; i < vuelo.asientos+vuelo.capacidad; i++)
    {
        if (i->reservado)
        {
            ocupados++;
        }else{
            libres++;
        }
    }

    ocupacion=(ocupados*100.0)/asientos;
    
    cout<<"total de asientos: "<<asientos<<"\nasientos ocupados: "<<ocupados<<"\nasientos libres: "<<libres<<"\nprocentaje de ocupacion"<<ocupacion;
}

/* 7 */
void liberar(Vuelo &vuelo){
    for (Asiento* i = vuelo.asientos; i < vuelo.asientos+vuelo.capacidad; i++)
    {
        if (i->reservado)
        {
            delete i->pasajero;
        }
    }
    
    
    while (vuelo.listaReservas!=nullptr)
    {
        NodoReserva* actual=vuelo.listaReservas;
        vuelo.listaReservas=vuelo.listaReservas->siguiente;

        delete actual;
    }
    
    delete vuelo.listaReservas;delete[] vuelo.asientos;
    vuelo.asientos=nullptr;vuelo.listaReservas=nullptr;
}

int main(){
    Vuelo vuelo=crearVuelo();

    int opcion=0;
    
    do {
        cout<<"\n--- MENU PRINCIPAL ---\n";
        cout<<"1. Mostrar todos los asientos (Ocupados/Libres)\n";
        cout<<"2. Reservar un asiento\n";
        cout<<"3. Cancelar una reserva\n";
        cout<<"4. Mostrar lista de pasajeros\n";
        cout<<"5. Mostrar estadisticas\n";
        cout<<"6. Salir\n";
        cout<<"Elige una opcion: ";
        cin>>opcion;
        
        switch (opcion) {
            case 1:
                mostrarAsientos(vuelo);
                break;
            case 2:
                reservarAsiento(vuelo);
                break;
            case 3:
                int dniCancelar;
                cout<<"Ingrese el DNI para cancelar: ";
                cin>>dniCancelar;
                cancelarReserva(vuelo,dniCancelar);
                break;
            case 4:
                recorrerMostrar(vuelo);
                break;
            case 5:
                mostrarEstadisticas(vuelo);
                break;
            case 6:
                cout<<"Liberando memoria y saliendo...\n";
                liberar(vuelo);
                break;
            default:
                cout<<"Opcion invalida.\n";
        }
    } while (opcion!=6);

    return 0;
}