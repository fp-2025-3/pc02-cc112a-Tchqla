#include <iostream>
#include <fstream>
using namespace std;








int main(){
	ofstream archivoEscritura;
	archivoEscritura.open("notas.txt");

	if (!archivoEscritura)
	{
		cerr<< "error al abrir el archivo de escritura"<<endl;
		return 1;
	}
	
	archivoEscritura<<"juan 15\n";
	archivoEscritura<<"pedro 15\n";
	archivoEscritura<<"maria 15\n";

	archivoEscritura.close();

	ifstream archivoLectura;
	archivoLectura.open("notas.txt");

	if (!archivoLectura)
	{
		cerr<< "error al abrir el archivo de escritura"<<endl;
		return 1;
	}
	
	string nombre;
	int nota;
	while (archivoLectura >>nombre>>nota)
	{
		cout<<nombre<<" --- "<<nota<<endl;
	}
	
	archivoLectura.close();

	ofstream fout("notas.txt",ios::app | ios::binary);

	while (!fout)
	{
		cerr<<"error al abrir el archivo para escritura";
		return 1;
	}
	
	fout<<"melisa 14\n";
	fout<<"arturo 15\n";
	fout<<"andres 17\n";

	cout<<"datos agregados correctamente"<<endl;
	
	return 0;
}