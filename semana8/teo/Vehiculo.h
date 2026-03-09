#ifndef VEHICULO_H
#define VEHIVULO_H

class Vehiculo
{
private:
    std:: string placa;
    std:: string marca;
    int año;
    double precio;
public:
    Vehiculo();
    Vehiculo(std:: string p,std::string m,int a,double pr);
    ~Vehiculo();
};

class Automovil: public Vehiculo
{
private:
    int numPuertas;
public:
    Automovil();
    Automovil(std:: string p,std:: string m,int a,double pr,int n);
    ~Automovil();
};

class Camion: public Vehiculo
{
private:
    double capacidad;
public:
    Camion();
    Camion(std:: string p,std:: string m,int a,double pr,double cp);
    ~Camion();
};

class Motocicleta: public Vehiculo
{
private:
    double potencia;
public:
    Motocicleta();
    Motocicleta(std:: string p,std:: string m,int a,double pr,double po);
    ~Motocicleta();
};

#endif