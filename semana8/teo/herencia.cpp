#include <iostream>
using namespace std;

class Vehiculo{
protected:
    int ruedas;
    string color;
public:
    Vehiculo(int r, string c):ruedas(r),color(c){}

    void mostrarInfo(){
        cout<<"Numero de ruedas del vehiculo: "<<ruedas<<endl;
        cout<<"Color del vehiculo: "<<color<<endl;
    }

    ~Vehiculo(){
        cout<<"Desturctor vehivulo\n";
    }
};

class Coche: public Vehiculo{
private:
    int numPuertas;
public:
    Coche(int r, string c, int np): Vehiculo(r,c),numPuertas(np){}

    void mostrarCoche(){
        cout<<"Numero de puertas del coche: "<<numPuertas<<endl;
        cout<<"Color del coche: "<<color<<endl;
        cout<<"Numero de ruedas del coche: "<<ruedas<<endl;
    }

    ~Coche(){
        cout<<"destructor Coche\n";
    }
};

class Moto: public Vehiculo{
private:
    bool conCasco;
public:
    Moto(int r, string c, bool cc): Vehiculo(r,c),conCasco(cc){}

    void mostrarMoto(){
        cout<<"Numero de ruedas de la moto: "<<ruedas<<endl;
        cout<<"color de la moto: "<<color<<endl;
        cout<<"Tiene casco: ";
        if (conCasco)
        {
            cout<<"SI";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }
};

int main(){
    Vehiculo v1(4,"Azul");
    v1.mostrarInfo();

    Coche c1(4,"Rojo",4);
    c1.mostrarInfo();

    Moto m1(2,"Negro",true);
    m1.mostrarInfo();

    return 0;
}