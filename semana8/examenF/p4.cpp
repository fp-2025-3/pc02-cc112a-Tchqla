#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Sensor
{
protected:
    string id;
    double* posicion;
public:
    Sensor(string i,double* p):id(i){
        posicion=new double[2];
    }

    Sensor(const Sensor &p){
        id=p.id;
        
        posicion=new double[2];
        //posicion=p.posicion;??
        posicion[0]=p.posicion[0];
        posicion[1]=p.posicion[1];
    }

    Sensor& operator=(Sensor &otro){
        if (this!=&otro)
        {
            id=otro.id;
            delete[] posicion;

            posicion=new double[2];
            //posicion=otro.posicion;??
            posicion[0]=otro.posicion[0];
            posicion[1]=otro.posicion[1];
        }
        
    }

    virtual ~Sensor(){
        delete[] posicion;
    }

    virtual double areaCobertura() const=0;
    virtual bool detecta(double x,double y) const=0;
    virtual void imprimir() const=0;
};

class SensorCircular: public Sensor
{
private:
    double radio;
public:
    SensorCircular(string i,double* p,double r):Sensor(i,p),radio(r){}

    virtual double areaCobertura() const{
        double cobertura=M_PI*pow(radio,2);

        return cobertura;
    }

    virtual bool detectar(double x,double y) const{
        double superficie=M_PI*(pow(x-posicion[0],2)+pow(y-posicion[1],2));

        if (areaCobertura()<superficie)
        {
            return false;
        }
        
        return true;
    }

    virtual void imprimir() const{
        cout<<"\nID Sendor circular:\n"<<id
            <<"\nposicion x: "<<posicion[0]
            <<"\nposicion y: "<<posicion[1]
            <<"\nradio: "<<radio<<endl;
    }

    virtual ~SensorCircular(){}
};

class SensorRectangular: public Sensor
{
private:
    double ancho;
    double alto;
public:
    SensorRectangular(string i,double* p,double a,double al):Sensor(i,p),ancho(a),alto(al){}

    virtual double areaCobertura() const{
        //ancho a la derecha y a la izquierda: 2*ancho
        //alto hacia arriba y abajo: 2*alto
        double cobertura=4*ancho*alto;

        return cobertura;
    }

    virtual bool detectar(double x,double y) const{

        bool enx=(x>=posicion[0]-ancho)&&(x<=posicion[0]+ancho);

        bool eny=(y>=posicion[1]-alto)&&(y<=posicion[1]+alto);
        
        return (eny&&enx);
    }

    virtual void imprimir() const{
        cout<<"\nID Sendor Rectangular:\n"<<id
            <<"\nposicion x: "<<posicion[0]
            <<"\nposicion y: "<<posicion[1]
            <<"\nancho: "<<ancho
            <<"\nalto: "<<alto<<endl;
    }

    virtual ~SensorRectangular(){}
};

class SistemaSensores
{
private:
    Sensor** sensores;
    int cantidad;
    int capacidad;
public:
    SistemaSensores(){
        cantidad=0;
        capacidad=2;

        sensores=new Sensor*[capacidad];
    }

    void agregarSensor(Sensor* s){
        if (cantidad==capacidad)
        {
            capacidad*=2;

            Sensor** temp=new Sensor*[capacidad];
            for (int i = 0; i < cantidad; i++)
            {
                temp[i]=sensores[i];
            }
            
            delete[] sensores;

            sensores=temp;
        }
        
        sensores[cantidad]=s;
        cantidad++;
    }

    void mostrarSensores() const{

    }

    double areaTotalCbertura() const{}

    int sensoresQueDetectan(double x,double y) const{}

    Sensor* sensorMayorCobertura() const{}

    ~SistemaSensores();
};


int main(){

    return 0;
}