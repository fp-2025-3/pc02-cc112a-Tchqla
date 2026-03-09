#include <iostream>
#include <fstream>
using namespace std;
const int MAX_LIBROS=100;

struct Libro
{
    int codigo;
    char titulo[50];
    bool prestado;
};

struct Usuario
{
    int codigo;
    string nombres;
    int prestamos;
};

void registrarUsuario(){

}

void registrarLibro(Libro libros[],int &n){
    if (n>=MAX_LIBROS)
    {
        cout<<"capacidad maxima alcanzada\n";
        return;
    }
    
    cout<<"codigo: ";cin>>libros[n].codigo;
    cin.ignore();

    cout<<"titulo: ";
    cin.getline(libros[n].titulo,50);

    libros[n].prestado=false;

    n++;
}

int buscarLibro(Libro libros[], int n, int codigo){

}

void prestarLibro(Libro libros[], int n){

}

void devolverLibro(Libro libros[], int n){

}

void cargarDesdeArchivo(Libro libros[], int n){

}

void mostrarLibros(Libro libros[], int n){
    
}

int main(){

    return 0;
}