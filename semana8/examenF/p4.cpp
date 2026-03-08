#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Sensor
{
private:
    string id;
    double* posicion;
public:
    Sensor(string i,double* p):id(i){
        posicion=new double[2];
    }

    Sensor(const Sensor &p){
        id=p.id;
        
        posicion=new double[2];
        
        posicion[0]=p.posicion[0];
        posicion[1]=p.posicion[1];
    }

    Sensor& operator=(Sensor &otro){
        if (this!=&otro)
        {
            id=otro.id;
            delete[] posicion;

            posicion=new double[2];
            
            posicion[0]=otro.posicion[0];
            posicion[1]=otro.posicion[1];
        }
        
    }

    double getPosi(int i) const{
        return posicion[i];
    }

    string getId() const{
        return id;
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

    virtual bool detecta(double x,double y) const{
        double superficie=M_PI*(pow(x-getPosi(0),2)+pow(y-getPosi(1),2));

        if (areaCobertura()<superficie)
        {
            return false;
        }
        
        return true;
    }

    virtual void imprimir() const{
        cout<<"\nID Sendor circular:\n"<<getId()
            <<"\nposicion x: "<<getPosi(0)
            <<"\nposicion y: "<<getPosi(1)
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

    virtual bool detecta(double x,double y) const{

        bool enx=(x>=getPosi(0)-ancho)&&(x<=getPosi(0)+ancho);

        bool eny=(y>=getPosi(1)-alto)&&(y<=getPosi(1)+alto);
        
        return (eny&&enx);
    }

    virtual void imprimir() const{
        cout<<"\nID Sendor Rectangular:\n"<<getId()
            <<"\nposicion x: "<<getPosi(0)
            <<"\nposicion y: "<<getPosi(1)
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
	    cout<<"Sensores activos: "<<cantidad;

	    for (int i = 0;i<cantidad;i++)
	    {
	    	cout<<"\nID: "<<sensores[i]->getId()
	    	    <<"\nX: "<<sensores[i]->getPosi(0)
	    	    <<"\nY: "<<sensores[i]->getPosi(1)<<endl;
	    }
    }

    double areaTotalCbertura() const{
    	double Superficie=0;

	    for(int i=0;i<cantidad;i++){
	    	Superficie+=sensores[i]->areaCobertura();
	    }

	    return Superficie;
    }

    int sensoresQueDetectan(double x,double y) const{
        int cont=0;

        for (int i = 0; i < cantidad; i++)
        {
            if (sensores[i]->detecta(x,y))
            {
                cont++;
            }
            
        }
        
        return cont;
    }

    Sensor* sensorMayorCobertura() const{
        if (cantidad==0)
        {
            return nullptr;
        }
        
        Sensor* mayor=sensores[0];double max=mayor->areaCobertura();
        for (int i = 0; i < cantidad; i++)
        {
            if (max<sensores[i]->areaCobertura())
            {
                max=sensores[i]->areaCobertura();
                mayor=sensores[i];
            }
            
        }
        
        return mayor;
    }

    ~SistemaSensores(){
        for (int i = 0; i < cantidad; i++)
        {
            delete[] sensores[i];
        }
        
        delete[] sensores;
    }
};


int main(){
    SistemaSensores miSistema;
    int opcion;

    do {
        cout<<"\n========================================="
            <<"\n       SISTEMA GESTOR DE SENSORES"
            <<"\n========================================="
            <<"\n1. Agregar un sensor circular"
            <<"\n2. Agregar un sensor rectangular"
            <<"\n3. Mostrar todos los sensores"
            <<"\n4. Calcular el area total de cobertura"
            <<"\n5. Consultar deteccion en un punto (X, Y)"
            <<"\n6. Mostrar el sensor con mayor cobertura"
            <<"\n7. Salir del programa"
            <<"\nElige una opcion (1-7): ";
        cin>>opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:{
                string id;
                double x,y,radio;
                
                cout<<"\n--- NUEVO SENSOR CIRCULAR ---";
                cout<<"\nIngrese ID (sin espacios): ";cin>>id;
                cout<<"Ingrese posicion X: ";cin >>x;
                cout<<"Ingrese posicion Y: ";cin >>y;
                cout<<"Ingrese el radio: ";cin>>radio;
                
                double pos[2]={x,y};
                miSistema.agregarSensor(new SensorCircular(id,pos,radio));
                cout<<"Sensor circular agregado con exito\n";
                break;
            }
            case 2:{
                string id;
                double x,y,ancho,alto;
                
                cout<<"\n--- NUEVO SENSOR RECTANGULAR ---";
                cout<<"\nIngrese ID (sin espacios): ";cin>>id;
                cout<<"Ingrese posicion X: ";cin>>x;
                cout<<"Ingrese posicion Y: ";cin>>y;
                cout<<"Ingrese el ancho (hacia los lados): ";cin>>ancho;
                cout<<"Ingrese el alto (hacia arriba/abajo): ";cin>>alto;
                
                double pos[2]={x,y};
                miSistema.agregarSensor(new SensorRectangular(id,pos,ancho,alto));
                cout<<"Sensor rectangular agregado con exito\n";
                break;
            }
            case 3:
                cout<<"\n--- LISTA DE SENSORES ---\n";
                miSistema.mostrarSensores();
                break;

            case 4:
                cout<<"\nEl area total de cobertura de la red es: "<<miSistema.areaTotalCbertura()<<" unidades cuadradas.\n";
                break;

            case 5: {
                double testX,testY;
                cout<<"\n--- PRUEBA DE DETECCION ---";
                cout<<"\nIngrese coordenada X a evaluar: ";cin>>testX;
                cout<<"\nIngrese coordenada Y a evaluar: ";cin>>testY;
                
                int detectan = miSistema.sensoresQueDetectan(testX,testY);
                cout<<"\nEl punto ("<<testX<<", "<<testY<<") es detectado por "<<detectan<<" sensor(es).\n";
                break;
            }
            case 6:{
                Sensor* elMayor=miSistema.sensorMayorCobertura();
                if (elMayor!=nullptr) {
                    cout<<"\n--- SENSOR CON MAYOR COBERTURA ---";
                    elMayor->imprimir();
                } else {
                    cout<<"\nNo hay sensores registrados en el sistema.\n";
                }
                break;
            }
            case 7:
                cout<<"\nSaliendo del sistema... ¡Hasta pronto!\n";
                break;

            default:
                cout<<"\nOpcion invalida. Por favor, ingrese un numero del 1 al 7.\n";
                break;
        }

    } while (opcion!=7);

    return 0;
}