#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>

int main()
{
	char name[80], filename[80], address[80];
	int age;
	long number;
	cout << "Name of the file to write: "; cin >> filename;

	ofstream objeto_escritura(filename); //objeto_escritura de clase ofstream
	objeto_escritura.fill('.'); //espacios en blanco se rellenan con puntos

	while (true)
	{
		cout << "Name (exit = end program): "; cin >> name;
		if (strcmp(name, "exit") == 0) { break; }
		cout << "Age: "; cin >> age;
		cin.ignore();
		cout << "Address: "; cin.getline(address,80);
		cout << "Telephone number: "; cin >> number;

		//Escribir nombre
		objeto_escritura.width(15); //Separo 15 espacios
		objeto_escritura.setf(ios::left); //Me situo en la izq
		objeto_escritura << name; //cout << nombre

		//Escribir Edad
		objeto_escritura.width(4); //Separo 4 espacios
		objeto_escritura << age; //cout << edad

		//Escribir Direccion
		objeto_escritura.width(30); //Separo 30 espacios
		objeto_escritura << address; //cout << address

		//Escribir Telefono
		objeto_escritura.unsetf(ios::left); //me dejo de situar en la izq
		objeto_escritura.width(15); //separo 15 espacios
		objeto_escritura << number; //cout << numero

		//enter
		objeto_escritura << endl;

	}

	objeto_escritura.close(); //cierro objeto
	cout << "Data stored in: " << filename << endl;

}