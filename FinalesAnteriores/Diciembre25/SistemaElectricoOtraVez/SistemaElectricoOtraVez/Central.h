#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;

namespace EUR
{
	class Fecha
	{
		int dia, mes, anno;
	public:
		Fecha(int d, int m, int a) { dia = d; mes = m; anno = a; }
		void prt()
		{
			cout.fill('0');
			cout << setw(2) << dia << "/" << setw(2) << mes << "/" << setw(4) << anno;
			cout.fill(' ');
		}
	};
}

namespace INT
{
	class Fecha
	{
		int dia, mes, anno;
	public:
		Fecha(int d, int m, int a) { dia = d; mes = m; anno = a; }
		void prt()
		{
			cout.fill('0');
			cout << setw(4) << anno << "/" << setw(2) << mes << "/" << setw(2) << dia;
			cout.fill(' ');
		}
	};
}


struct mantenimiento
{
	EUR::Fecha fecha;
	string tarea;
};

class Central 
{
	string nombre_ID;
	double coste_base; // Costes fijos de generación por MWh
protected:
	vector <double> potencia; // En esta variable se almacena la potencia unitario de cada elemento de la Central
		vector <double> carga; // En esta variable se almacena la carga de cada elemento de la Central(0 = descativado, 1 = maxima potencia)
public:
	vector<mantenimiento> historialMantenimiento;
public:
	Central(string _nombre_ID = "", double _coste_base = 0) {}
	void show_info();
	double CalcularPotenciaTotal();
	double CalcularPotenciaMaxima();
	bool AjustarCargaPotenciaObjetivo(double p);
	// GrabarEnFichero
	// Añada otras funciones si es necesario
	string getID() { return nombre_ID; }
};

class Eolica : public Central
{
public:
	Eolica(string _nombre_ID = "", double _coste_base = 0) : Central(_nombre_ID, _coste_base) {}
	void AddTurbina(double p)
	{
		potencia.push_back(p);
		carga.push_back(0);
	}
	// Añada otras funciones si es necesario
};

class EolicaOffshore : public Eolica 
{
public:
	EolicaOffshore(string _nombre_ID = "", double _coste_base = 0) : Eolica(_nombre_ID, _coste_base) {}
	// Añada otras funciones si es necesario
};

class Gas : public Central 
{
	double precio_gas; // En € por tonelada
	double consumo_gas; // En toneladas por MWh
public:
	Gas(string _nombre_ID = "", double _coste_base = 0, double _precio_gas = 0, double _consumo_gas = 0) : Central(_nombre_ID, _coste_base)
	{
		precio_gas = _precio_gas;
		consumo_gas = _consumo_gas;
	}

	void AddTurbinaGas(double p)
	{
		potencia.push_back(p);
		carga.push_back(0);
	}
	// Añada otras funciones si es necesario
};