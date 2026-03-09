#include <iostream>
using namespace std;

class Libro
{
private:
    string titulo;
    string autor;
    int paginas;
    //void numeroCuenta(){}
public:
    Libro(string t,string a,int p): titulo(t),autor(a),paginas(p){
        cout<<"se ejecuto el constructor con parametros\n";
    }

    Libro(){
        cout<<"constructor por defecto\n";
    }

    ~Libro(){
        cout<<"llamando al destructor\n";
    }

    string getTitulo()const{
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

//herencia
class LibroDigital :public Libro
{
private:
    string formato;
public:
    LibroDigital(string t, string a, int p, string f):Libro(t,a,p),formato(f){}
    
    void mostrarInfoDigital(){
        mostrarInfo();
        cout<<"formato digital: "<<formato<<endl;
    }
};

int main(){

    return 0;
}