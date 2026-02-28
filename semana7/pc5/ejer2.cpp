#include <iostream>
#include <fstream>
using namespace std;

struct Empleado{
    int id;
    char nombre[30];
    double salario;
};

int main(){
    Empleado empleado;
    fstream file("input/empleados.dat",ios::binary);

    if (file.is_open())
    {
        cerr<<"error al abrir el archivo\n";
        return 1;
    }

    int id=1;
    cout<<"ingrese el ID del empleado: ";cin>>id;

    file.seekg(sizeof(Empleado)*(id-1),ios::beg);

    file.read((char*)&empleado,sizeof(Empleado));

    if (!file)
    {
        cerr<<"no existe un empleado con ese ID\n";
        return 1;
    }
    
    cout<<"\n--- DATOS DEL EMPLEADO ---\nID: "<<id
        <<"\nNombre: "<<empleado.nombre
        <<"\nSalario: "<<empleado.salario
        <<"\n\nIngrese nuevo salario:";cin>>empleado.salario;
        

    file.seekg((id-1)*sizeof(Empleado),ios::beg);

    file.write((char*)&empleado,sizeof(Empleado));

    if (!file)
    {
        cerr<<"\nno se pudo actualizar el salario\n";
        return 1;
    }else{
        cout<<"\nsalario actualizado correctamente\n";
    }

    file.close();
    return 0;
}