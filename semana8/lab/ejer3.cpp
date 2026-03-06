#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

class Figura
{
private:
    string nombre;
    double* colorRGB;
public:
    Figura(string n, double r,double g,double b): nombre(n){
        colorRGB=new double[3];
        colorRGB[0]=r;
        colorRGB[1]=g;
        colorRGB[2]=b;
    }

    Figura(Figura &otro):nombre(otro.nombre){
        colorRGB=new double[3];
        for (int i = 0; i < 3; i++)
        {
            colorRGB[i]=otro.colorRGB[i];
        }
        
    }

    Figura& operator=(Figura &otro){
        if (this!=&otro)
        {
            nombre=otro.nombre;
            delete[] colorRGB;

            colorRGB=new double[3];

            for (int i = 0; i < 3; i++)
            {
                colorRGB[i]=otro.colorRGB[i];
            }
            
        }
        
        return *this;
    }

    string getNombre() const{
        return nombre;
    }

    virtual ~Figura(){
        delete[] colorRGB;
    }
    
    virtual double area() const=0;
    virtual double perimetro() const=0;
    virtual void imprimir() const=0;
};

class Circulo: public Figura
{
private:
    double radio;
public:
    Circulo(string n,double r,double g,double b,double ra): Figura(n,r,g,b),radio(ra){}

    virtual double area() const override{
        double S=M_PI*pow(radio,2);
        return S;
    }

    virtual double perimetro() const override{
        double P=2*M_PI*radio;
        return P;
    }

    virtual void imprimir() const override {
        cout<<"\ncirculo: "<<getNombre()<<"\nradio: "<<radio<<endl;
    }

    virtual ~Circulo(){}
};

class Rectangulo: public Figura
{
private:
    double base, altura;
public:
    Rectangulo(string n,double r,double g,double b,double ba,double a): Figura(n,r,g,b),base(ba),altura(a){}
    
    virtual double area() const override{
        double S=base*altura;
        return S;
    }

    virtual double perimetro() const override{
        double P=2*(base+altura);
        return P;
    }

    virtual void imprimir() const override {
        cout<<"\nrectangulo: "<<getNombre()<<"\nbase: "<<base<<"\naltura: "<<altura<<endl;
    }

    virtual ~Rectangulo(){}
};

class GestorFigura
{
private:
    Figura** figuras;
    int cantidad;
    int capacidad;
public:
    GestorFigura(){
        capacidad=2;
        cantidad=0;

        figuras=new Figura*[capacidad];
    }

    void agregarFigura(Figura* newFIgura){
        if (cantidad==capacidad)
        {
            capacidad*=2;
            Figura** temp=new Figura*[capacidad];

            for (int i = 0; i < capacidad; i++)
            {
                temp[i]=figuras[i];
            }
            
            delete[] figuras;

            figuras=temp;
        }
        
        figuras[cantidad]=newFIgura;
        cantidad++;
    }

    void mostrarFiguras() const{
        if (cantidad==0)
        {
            cout<<"no hay figuras registradas\n";
            return;
        }

        cout<<"\n=== LISTA DE FIGURAS ===\n";
        for (int i = 0; i < cantidad; i++)
        {
            figuras[i]->imprimir();
        }
        
    }

    double areaTotal() const{
        double ST=0;
        for (int i = 0; i < cantidad; i++)
        {
            ST+=figuras[i]->area();
        }
        
        return ST;
    }

    void guardarArchivo() const{
        ofstream file("output/figutas.txt");

        if (!file)
        {
            cerr<<"no se pudo abrir el archivo\n";
            return;
        }
        
        file<<"=== REPORTE DE FIGURAS ===\n"
            <<"cantidad de figuras: "<<cantidad
            <<"\narea total de todas las figuras: "<<areaTotal()
            <<"\n\n";

        for (int i = 0; i < cantidad; i++)
        {
            file<<"figura "<<i+1
                <<"\narea: "<<figuras[i]->area()
                <<"\nperimetro: "<<figuras[i]->perimetro()
                <<"\n\n";
        }
        
        file.close();
    }

    ~GestorFigura(){
        for (int i = 0; i < cantidad; i++)
        {
            delete figuras[i];
        }
        
        delete[] figuras;
    }
};

int main(){
    GestorFigura gestor;

    gestor.agregarFigura(new Circulo("Rueda",255,0,0,5.0));
    gestor.agregarFigura(new Rectangulo("Mesa",255,0,0,10.0,4.0));

    gestor.mostrarFiguras();

    cout<<"\nel area total de todas las figuras es: "<<gestor.areaTotal()<<endl;

    gestor.guardarArchivo();

    return 0;
}