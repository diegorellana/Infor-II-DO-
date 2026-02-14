#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

class coche
{
protected:
	int year; // Año de fabricación
	int km; // miles de kilómetros
public:
	char plate[20]; // Matrícula
	// Constructor por defecto
	coche() { ; }
	// Constructor o función de asignación
	coche(int y, int k, char* p)
	{
		year = y;
		km = k;
		strcpy_s(plate, 20, p);
	}
	// Destructor por defecto
	~coche() { ; }

	void prt()
	{
		if (year > 1975)
		{
			cout << getTipo() << endl;
			cout << "Anno de fabricacion: " << year << endl;
			cout << "Matricula: " << plate << endl;
			cout << "Miles de kilometros: " << km << endl;
			cout << endl;
		}

		else if (year <= 1975)
		{
			cout << "Anno de fabricacion: " << year << endl;
			cout << "Matricula: " << plate << endl;
			cout << "Miles de kilometros: " << km << endl;
			cout << endl;
		}
	}

	virtual string getTipo() { return "Coche Normal"; }

};

class gasolina : public coche
{
public:
	gasolina(int y, int k, char* p) : coche(y, k, p) {}
	gasolina() { ; }
	~gasolina() { ; }

	string getTipo() 
	{ 
		string tipo = "Coche de gasolina"; 
		return tipo;
	}
};

class clasico : public gasolina
{
public:
	clasico(int y, int k, char* p) : gasolina(y, k, p) {}
	clasico() { ; }
	~clasico() { ; }

	string getTipo()
	{
		string tipo = "Coche clasico";
		return tipo;
	}

	void prt2()
	{
		cout << getTipo() << endl;
		prt();
	}

	void grabar(ofstream& w)
	{
		w << year << endl;
		w << plate << endl;
		w << km << endl;
		w << endl;
	}

	void leer(ifstream& r)
	{
		int anno, k,size;
		char p[20];

		r >> anno;
		r >> p;
		r >> k;

		year = anno;
		strcpy_s(plate, 20, p);
		km = k;
	}
};

class electrico : public coche
{
public:
	electrico(int y, int k, char* p) : coche(y, k, p) {}
	electrico() { ; }
	~electrico() { ; }

	string getTipo()
	{
		string tipo = "Coche electrico";
		return tipo;
	}
};
