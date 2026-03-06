#include <iostream>
#include <fstream>
using namespace std;

struct Proyecto
{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};

Proyecto* llenarProyectos(int n){
    Proyecto* p=new Proyecto[n];
    for (Proyecto* i = p; i < p+n; i++)
    {
        cout<<"ID: ";cin>>i->id;
        cin.ignore();
        cout<<"Titulo: ";cin.getline(i->titulo,40);
        cout<<"Presupuesto: ";cin>>i->presupuesto;
        cout<<"Tiempo (meses): ";cin>>i->duracionMeses;
    }
    
    return p;
}

void ordenarProyectos(Proyecto* &p,int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < i-n-1; j++)
        {
            if (p[i].presupuesto<p[i+1].presupuesto)
            {
                swap(p[i],p[i+1]);
            }
            
        }
        
    }
    
}

Proyecto* insertarArchivo(Proyecto* p,int n,int &r){
    Proyecto* temp=new Proyecto[n]();
    temp[0]=p[0];
    
    int nuevoID=1;
    for (int i = 0; i < n; i++)
    {
        int id_actual=p[i].id;
        bool nuevo=false;
        
        for (int j = 0; j < nuevoID; j++)
        {
            if (p[j].id==id_actual)
            {
                nuevo=true;
                break;
            }
            
        }
        
        if (!nuevo)
        {
            temp[nuevoID]=p[i];
            nuevoID++;
        }
        
    }

    if (nuevoID<n)
    {
        cout<<"\nEXISTEN PROYECTOS CON EL MISMO ID\n";
    }
    
    Proyecto* sinRepetir=new Proyecto[nuevoID];
    for (int i = 0; i < nuevoID; i++)
    {
        sinRepetir[i]=temp[i];
    }
    
    delete[] temp;
    ///////////
    fstream file("output/proyectos.dat",ios::in|ios::out|ios::binary);
    
    if (!file)
    {
        file.open("output/proyectos.dat",ios::out|ios::binary);
        file.close();

        file.open("output/proyectos.dat",ios::in|ios::out|ios::binary);
    }
    ///////////
    file.write((char*)sinRepetir,sizeof(Proyecto)*nuevoID);

    file.close();r=nuevoID;

    return sinRepetir;
}

/*ofstream file("output/proyectos.dat",ios::binary);
    
    if (!file)
    {
        cerr<<"error al abrir el archivo\n";
        return nullptr;
    }*/

int main(){
    int n;
    cout<<"ingrese el numero de proyectos: ";cin>>n;

    Proyecto* proyectos=llenarProyectos(n);

    ordenarProyectos(proyectos,n);

    int noRepetidos;
    Proyecto* proyectosNoRepetidos=insertarArchivo(proyectos,n,noRepetidos);

    if (proyectosNoRepetidos==nullptr)
    {
        return 1;
    }
    

    cout<<"fueron registrados "<<noRepetidos<<" proyectos:\n";

    for (Proyecto* i = proyectosNoRepetidos; i < proyectosNoRepetidos+noRepetidos; i++)
    {
        cout<<"ID: "<<i->id
            <<"\nTitulo: "<<i->titulo
            <<"\nPresupuesto: "<<i->presupuesto
            <<"\nTiempo (meses): "<<i->duracionMeses<<endl;
    }
    
    delete[] proyectos;
    delete[] proyectosNoRepetidos;

    return 0;
}