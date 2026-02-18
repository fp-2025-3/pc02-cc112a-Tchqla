#include <iostream>
#include <string>
using namespace std;

struct Procesos
{
    int ID;
    string nombre;
    float memoria;
    Procesos* siguiente;
};

struct ListaProcesos
{
    Procesos* cabeza;
};

void mostrarProcesos(ListaProcesos lista){
    Procesos* actual=lista.cabeza;
    while (actual!=nullptr)
    {
        cout<<"\nID: "<<actual->ID<<endl<<"memoria: "<<actual->memoria<<endl<<"nombre: "<<actual->nombre<<endl;
        actual=actual->siguiente;
    }
    
}

void buscar(ListaProcesos lista, int id){
    Procesos* actual=lista.cabeza;

    while (actual!=nullptr)
    {
        if (id==actual->ID)
        {
            cout<<"ID: "<<actual->ID<<"\tencontrado: "<<actual->nombre<<endl;
            return;
        }
        actual=actual->siguiente;
    }
    
    cout<<"el proceso no existe\n";
}

void eliminar(ListaProcesos& lista,int id){
    if (id==lista.cabeza->ID)
    {
        Procesos* temp=lista.cabeza;
        lista.cabeza=lista.cabeza->siguiente;
        delete temp;temp=nullptr;
        return;
    }
    
    Procesos* actual=lista.cabeza;
    while (actual->siguiente!=nullptr && actual->siguiente->ID!=id)
    {
        actual=actual->siguiente;
    }

    if (actual->siguiente!=nullptr)
    {
        Procesos* temp=actual->siguiente;
        actual->siguiente=temp->siguiente;
        delete temp;temp=nullptr;
    }else{
        cout<<"no existe el id\n";
    }
}

void contar(ListaProcesos lista){
    int i=0;Procesos* actual=lista.cabeza;

    while (actual!=nullptr)
    {
        i++;
        actual=actual->siguiente;
    }
    
    cout<<"hay "<<i<<"procesos en el sistema.\n";
}

int main(){
    ListaProcesos lista;
    lista.cabeza=nullptr;
    int id;

    for (int i = 0; i < 5; i++)
    {
        Procesos* nuevo=new Procesos;
        cout<<"ID: ";cin>>nuevo->ID;
        cin.ignore();
        cout<<"proceso: ";getline(cin,nuevo->nombre);
        cout<<"memoria: ";cin>>nuevo->memoria;
        nuevo->siguiente=lista.cabeza;
        lista.cabeza=nuevo;
    }
    
    while (lista.cabeza!=nullptr)
    {
        Procesos* temp=lista.cabeza;
        lista.cabeza=lista.cabeza->siguiente;
        delete temp;
        temp=nullptr;
    }
    

    return 0;
}