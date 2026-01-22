#include <iostream>
using namespace std;
class CAlumno
{
private:
	char* nombre;
	int edad;
	long telefono;

public:
	CAlumno() { ; }		//Constr. Por defecto
	CAlumno(char* buf, int ed, long tel)
	{
		nombre = new char[strlen(buf) + 1];
		strcpy_s(nombre, strlen(buf) + 1, buf);
		edad = ed;
		telefono = tel;
	}
	~CAlumno()
	{
		if (nombre == NULL) { delete nombre; }
	}
	void Print()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
		cout << "Telefono: " << telefono << endl;
	}
	void Asignar(char* buf, int ed, int tel)
	{
		nombre = new char[strlen(buf) + 1];
		strcpy_s(nombre, strlen(buf) + 1, buf);

		edad = ed;
		telefono = tel;
	}

};

