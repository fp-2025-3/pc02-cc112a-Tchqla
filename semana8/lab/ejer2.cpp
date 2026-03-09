#include <iostream>
#include <fstream>
using namespace std;

struct CuentaBancaria {
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};

void crearArchivo(int n){
    fstream file("output/cuentas.dat",ios::in | ios::out | ios::binary);

    if (!file)
    {
        file.open("output/cuentas.dat",ios::out | ios::binary);
        file.close();
        
        file.open("output/cuentas.dat",ios::in | ios::out | ios::binary);
    }
    
    CuentaBancaria cuenta;

    for (int i = 0; i < n; i++)
    {
        cout<<"numero de cuenta "<<i+1<<": ";cin>>cuenta.numeroCuenta;

        file.seekg(sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1));

        CuentaBancaria temp;
        file.read((char*)&temp,sizeof(CuentaBancaria));

        if (temp.activa)
        {
            cout<<"ya existe una cuenta con ese numero\n"; i--;
        }else{
            file.clear();

            file.seekp(sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1));

            cin.ignore();
            cout<<"titular: ";cin.getline(cuenta.titular,40);
            cout<<"saldo: ";cin>>cuenta.saldo;
            while (cuenta.saldo<0)
            {
                cout<<"SOLO SALDO POSITIVO\nsaldo: ";cin>>cuenta.saldo;
            }
            cuenta.activa=true;

            file.write((char*)&cuenta,sizeof(CuentaBancaria));
        }
        
    }
    
    file.close();
}

CuentaBancaria funcionBusqueda(int n){
    fstream file("output/cuentas.dat",ios::in | ios::out | ios::binary);

    if (!file)
    {
        file.open("output/cuentas.dat",ios::out | ios::binary);
        file.close();
        
        file.open("output/cuentas.dat",ios::in | ios::out | ios::binary);
    }

    CuentaBancaria temp;

    file.seekg(sizeof(CuentaBancaria)*(n-1));

    file.read((char*)&temp,sizeof(CuentaBancaria));

    if (!temp.activa)
    {
        cout<<"no existe una cuenta con ese numero\n";
    }

    file.close();

    return temp;
}

void DepositoRetiro(CuentaBancaria &cuenta,char depo_reti, double saldo){
    if (cuenta.activa!=true)
    {
        cout<<"la cuenta no esta activa\n";
        return;
    }
    
    fstream file("output/cuentas.dat",ios::in|ios::out|ios::binary);
    if (!file)
    {
        cerr<<"no se pudo abrir el archivo\n";
        return;
    }

    if (saldo<0)
    {
        cout<<"\nsolo valores enteros\n";
        return;
    }

    if (depo_reti=='D')
    {
        file.seekp(sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1));

        cuenta.saldo+=saldo;
        cout<<"\nOperacion procesada.\n";
    }else if (depo_reti=='R')
    {
        file.seekp(sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1));

        cuenta.saldo-=saldo;
        cout<<"\nOperacion procesada.\n";
    }else{
        cout<<"no hubo cambios\n";
        file.close();return;
    }
    
    file.write((char*)&cuenta,sizeof(CuentaBancaria));

    file.close();
}

void DesactivarCuenta(CuentaBancaria &cuenta){
    fstream file("output/cuentas.dat",ios::in|ios::out|ios::binary);
    if (!file)
    {
        cerr<<"no se pudo abrir el archivo\n";
        return;
    }

    if (cuenta.activa==true)
    {
        file.seekp(sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1));
        cuenta.activa=false;

        file.write((char*)&cuenta,sizeof(CuentaBancaria));

        cout<<"se desactivo al cuenta\n";
    }else{
        cerr<<"la cuenta no esta activa\n";
    }
    
    file.close();
}

void activas(){
    fstream file("output/cuentas.dat",ios::in|ios::out|ios::binary);

    file.seekg(0,ios::end);

    int n=file.tellg()/sizeof(CuentaBancaria);

    file.seekg(ios::beg);
    
    cout<<"cuentas activas:";
    for (int i = 0; i < n; i++)
    {
        file.seekg(sizeof(CuentaBancaria)*(i));
        CuentaBancaria cuenta;
        file.read((char*)&cuenta,sizeof(CuentaBancaria));

        if (file && cuenta.activa)
        {
            cout<<"\nnumero de cuenta: "<<cuenta.numeroCuenta
                <<"\ntitular: "<<cuenta.titular
                <<"\nsaldo: "<<cuenta.saldo<<endl;
        }
    }
    
}

int main(){
    int opcion = 0;
    
    do {
        cout<<"\n=== SISTEMA BANCARIO ===\n"
            <<"1. Crear / Agregar Cuentas\n"
            <<"2. Buscar Cuenta\n"
            <<"3. Realizar Deposito\n"
            <<"4. Realizar Retiro\n"
            <<"5. Desactivar Cuenta\n"
            <<"6. Mostrar Cuentas Activas\n"
            <<"7. Salir\n"
            <<"Ingrese una opcion: ";
        cin>>opcion;
        
        switch (opcion) {
            case 1:
                int n;
                cout<<"\nCuantas cuentas desea crear? ";cin>>n;
                
                crearArchivo(n);
                break;

            case 2:
                int numCuenta;
                cout<<"\nIngrese el numero de cuenta a buscar: ";cin>>numCuenta;
                
                CuentaBancaria cuenta=funcionBusqueda(numCuenta);
                
                if (cuenta.activa)
                {
                    cout<<"\n---DATOS DE LA CUENTA---\n";
                    cout<<"Titular: "<<cuenta.titular<<"\n";
                    cout<<"Saldo: S/. "<<cuenta.saldo<<"\n";
                }
                break;

            case 3:
                int numCuenta;
                cout<<"\nIngrese el numero de cuenta: ";
                cin>>numCuenta;
                CuentaBancaria cuenta=funcionBusqueda(numCuenta);

                double monto;
                cout << "Ingrese el monto: ";
                cin >> monto;

                DepositoRetiro(cuenta,'D',monto);
                break;

            case 4:
                int numCuenta;
                cout<<"\nIngrese el numero de cuenta: ";
                cin>>numCuenta;
                CuentaBancaria cuenta=funcionBusqueda(numCuenta);

                double monto;
                cout << "Ingrese el monto: ";
                cin >> monto;

                DepositoRetiro(cuenta,'R',monto);
                break;

            case 5:
                int numCuenta;
                cout<<"\nIngrese el numero de cuenta a desactivar: ";cin>>numCuenta;
                
                CuentaBancaria cuenta=funcionBusqueda(numCuenta);
                
                if (cuenta.activa)
                {
                    DesactivarCuenta(cuenta);
                }
                break;

            case 6:
                cout << "\n--- LISTA DE CUENTAS ACTIVAS ---\n";
                activas();
                break;

            case 7:
                cout << "\nSaliendo del sistema...\n";
                break;
                
            default:
                cout << "\nOpcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 7);

    return 0;
}