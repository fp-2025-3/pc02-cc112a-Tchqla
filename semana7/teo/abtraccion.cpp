#include <iostream>
using namespace std;

class Libro
{
private:
    string titulo;
    string autor;
    int paginas;

public:
    Libro(string t, string a, int p) : titulo(t), autor(a), paginas(p) {
        cout<<"se esta ejecutando el constructor con parametros\n";
    }

    Libro(){
        cout<<"constructor por defecto\n";
    }

    ~Libro(){
        cout<<"llamando al destructor\n";
    }
    
    string getTitulo() const{
        return titulo;
    }

    void setTitulo(string t){
        titulo=t;
    }

    void mostrarInfo()
    {
        cout << "titulo: " << titulo << ", autor: " << autor << ", paginas: " << paginas << endl;
    }
};

int main(){

    return 0;
}