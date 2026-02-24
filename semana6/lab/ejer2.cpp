#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream archivo("input/notas.txt");
    ofstream archivoSalida("output/reporte.txt");

    if (!archivo)
    {
        cerr<<"error al abrir notas\n";
        return 1;
    }

    if (!archivoSalida)
    {
        cerr<<"error al abrir reporte\n";
        return 1;
    }
    
    int notas=0,desaprobados=0,aprobados=0;
    double nota,prom=0,myNota,meNota;
    while (archivo>>nota)
    {
        notas++;prom+=nota;

        if (nota<10)
        {
            desaprobados++;
        }else{
            aprobados++;
        }

        if (notas==1)
        {
            myNota=nota;meNota=nota;
        }else if (nota>myNota)
        {
            myNota=nota;
        }else if (meNota>nota){
            meNota=nota;
        }
    }
    
    prom=prom/notas;

    archivoSalida<<"REPORTE GENERAL\n------------------------\n";
    archivoSalida<<"Total estudiantes: "<<notas<<"\nPromedio: "<<prom<<"\nMayor nota: "<<myNota<<"\nMenor nota: "<<meNota;
    archivoSalida<<"\nAprobados: "<<aprobados<<"\nDesaprobados: "<<desaprobados;;
    
    archivo.close();
    archivoSalida.close();

    return 0;
}