#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Alumnos
{
    int codigo;
    string nombre;
    double notas[3];
    double promedio;
    string condicion;
};

Alumnos* conteo_estudiantes(int &i){
    ifstream file("input/notas.txt");

    if (!file)
    {
        cerr<<"no se pudo abrir el archivo\n";
        return nullptr;
    }

    Alumnos* aux=new Alumnos[100];
    string linea;

    while (getline(file,linea,' '))
    {
        aux[i].codigo=stoi(linea);

        getline(file,aux[i].nombre,' ');
        
        getline(file,linea,' ');
        aux[i].notas[0]=stod(linea);

        getline(file,linea,' ');
        aux[i].notas[1]=stod(linea);

        getline(file,linea);
        aux[i].notas[2]=stod(linea);

        double temp=0;bool desa=false;
        for (int j = 0; j < 3; j++)
        {
            if (aux[i].notas[j]<5)
            {
                aux[i].condicion="DESAPROBADO POR REGLA ACADEMICA";
                desa=true;
            }
            temp+=aux[i].notas[j];
        }

        aux[i].promedio=temp/3.0;

        if (aux[i].promedio>=10)
        {
            aux[i].condicion="APROBADO";
        }else if (!desa){
            aux[i].condicion="DESAPROBADO";
        }
        
        i++;
    }

    file.close();

    Alumnos* alumnos=new Alumnos[i];

    for (int j = 0; j < i; j++)
    {
        alumnos[j]=aux[j];
    }
    
    delete[] aux;aux=nullptr;

    return alumnos;
}

int estudianteMejorPromedio(Alumnos* alumnos,int i){
    double mejorProm=-1;int posi=0;
    for (int j = 0; j < i; j++)
    {
        if (alumnos[j].promedio>mejorProm)
        {
            mejorProm=alumnos[j].promedio;
            posi=j;
        }
        
    }
    
    return posi;
}

int estudianteMenorPromedio(Alumnos* alumnos,int i){
    double menorProm=21;int posi=0;
    for (int j = 0; j < i; j++)
    {
        if (alumnos[j].promedio<menorProm)
        {
            menorProm=alumnos[j].promedio;
            posi=j;
        }
        
    }
    
    return posi;
}

int main(){
    int i=0;double promGene=0;
    Alumnos* alumnos=conteo_estudiantes(i);

    if (alumnos==nullptr)
    {
        return 1;
    }
    
    ofstream file("output/reporteAlumnos.txt");

    if (!file)
    {
        cerr<<"no se pudo abrir el archivo\n";
        return 1;
    }
    
    file<<"---REPORTE DE ALUMNOS---\n\n"
        <<"Total de estudiantes: "<<i<<"\n\n";
    for (int j = 0; j < i; j++)
    {
        file<<"Codigo: "<<alumnos[j].codigo<<" | Promedio: "<<alumnos[j].promedio
            <<" | condicion: "<<alumnos[j].condicion<<endl;
        promGene+=alumnos[j].promedio;
    }
    promGene=promGene/i;

    int posicionMejor=estudianteMejorPromedio(alumnos,i);
    int posicionMenor=estudianteMenorPromedio(alumnos,i);

    file<<"\n\nPromedio general del curso: "<<promGene
        <<"\n\nEl estudiante con mayor promedio:\nCodigo: "<<alumnos[posicionMejor].codigo
        <<" | Nombre: "<<alumnos[posicionMejor].nombre<<" | Promedio: "<<alumnos[posicionMejor].promedio
        <<"\n\nEl estudiante con menor promedio:\nCodigo: "<<alumnos[posicionMenor].codigo
        <<" | Nombre: "<<alumnos[posicionMenor].nombre<<" | Promedio: "<<alumnos[posicionMenor].promedio;
    
    delete[] alumnos;alumnos=nullptr;

    file.close();

    return 0;
}