#include <iostream>
#include <string>
using namespace std;

struct Estudiante
{
    string nombre;
    float nota;
};

void llenado(Estudiante*  lista, int n){
    for (Estudiante* i = lista; i < lista+n; i++)
    {
        int a=i-lista;
        cin.ignore();
        cout<<"ingrese el nombre del estudiante "<<a<<": ";getline(cin,i->nombre);
        cout<<"ingrese la nota del estudiante "<<a<<": ";cin>>i->nota;
    }
    
}

void mayorNota(Estudiante* lista,int n){
    float max=lista->nota;
    int m=0;
    for (Estudiante* i = lista; i < lista+n; i++)
    {
        if (max<(i->nota))
        {
            max=i->nota;
            m=i-lista;
        }
    }
    
    cout<<"el estudiante con la mayor nota es: "<<(lista+m)->nombre<<"\nnota: "<<max<<endl;
}

int main(){
    int n;
    cout<<"ingrese el numero de estudiantes: ";cin>>n;

    Estudiante* clase=new Estudiante[n];

    llenado(clase,n);
    mayorNota(clase,n);

    delete[] clase;

    return 0;
}