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
void mostrarAsientos(Vuelo vuelo){}

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

        if (num_asiento>0 && num_asiento<vuelo.capacidad)
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
    vuelo.asientos[num_asiento].pasajero=nuevo;
    vuelo.asientos[num_asiento].reservado=true;
    
    NodoReserva* new_nodo=new NodoReserva;
    new_nodo->Pasajero.dni=dni;
    strcpy(new_nodo->Pasajero.nombre,nombre);
    new_nodo->numeroAsiento=num_asiento;

    new_nodo->siguiente=vuelo.listaReservas;
    vuelo.listaReservas=new_nodo;
}

/* 4 */
void cancelarReserva(Vuelo &vuelo, int dni){
    Vuelo actual=vuelo;
    while (actual.listaReservas!=nullptr)
    {
        if (actual.listaReservas->Pasajero.dni==dni)
        {
            delete actual.asientos->pasajero;
            actual.asientos->reservado=false;
        }
        
        actual.listaReservas=actual.listaReservas->siguiente;
    }
    
    
}

int main(){

    return 0;
}