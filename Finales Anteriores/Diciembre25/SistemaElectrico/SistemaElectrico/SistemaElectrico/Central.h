#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <string>

using namespace std;

class Fecha
{
	int dia, mes, anno;
public:
	Fecha(int d = 0, int m = 0, int a = 0) { dia = d; mes = m; anno = a; }
	void prt()
	{
		cout.fill('0');
		cout << setw(4) << anno << "/" << setw(2) << mes << "/" << setw(2) << dia;
		cout.fill(' ');
	}

};

namespace EUR
{
	class Fecha
	{
		int dia, mes, anno;
	public:
		Fecha(int d=0, int m=0, int a=0) { dia = d; mes = m; anno = a; }
		void prt()
		{
			cout.fill('0');
			cout << setw(2) << dia << "/" << setw(2) << mes << "/" << setw(4) << anno;
			cout.fill(' ');
		}

		void prt2(ofstream& w)
	{
		w.fill('0');
		w << setw(4) << anno << "/" << setw(2) << mes << "/" << setw(2) << dia;
		w.fill(' ');
	}
	};
}

namespace INT
{
	class Fecha
	{
		int dia, mes, anno;
	public:
		Fecha(int d=0, int m=0, int a=0) { dia = d; mes = m; anno = a; }
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
	Central(string _nombre_ID = "", double _coste_base = 0) 
	{
		nombre_ID = _nombre_ID;
		coste_base = _coste_base;
	}
	void show_info()
	{
		cout << getTipo() << " " << nombre_ID << endl;
		cout << "   " << "Potencia maxima: " << CalcularPotenciaMaxima() << endl;
		cout << "   " << "Precio: " << coste_base << "euros/MWh" << endl;
		cout << "   " << "Carga de turbinas: " << endl;

		for (int i = 0; i < potencia.size(); i++)
		{

			cout << "|   " << potencia[i] << "   |   ";
		}

		cout << endl;

		for (int i = 0; i < carga.size(); i++)
		{
			cout << "|   " << carga[i] << "%  |   ";
		}

		cout << endl;

		cout << "   " << "Mantenimiento: " << endl;
		for (int i = 0; i < historialMantenimiento.size(); i++)
		{
			historialMantenimiento[i].fecha.prt(); cout << "   " << historialMantenimiento[i].tarea << endl;
		}

		cout << endl << endl;

	}
	double CalcularPotenciaTotal()
	{
		double suma = 0;
		for (int i = 0; i < potencia.size(); i++)
		{
			suma += potencia[i] * carga[i];
		}

		return suma;
	}
	double CalcularPotenciaMaxima()
	{
		double suma = 0;
		for (int i = 0; i < potencia.size(); i++)
		{
			suma += potencia[i];
		}

		return suma;
	}
	bool AjustarCargaPotenciaObjetivo(double p)
	{
		double potencia_ext = 0;
		double potencia_int = 0;
		double carga_usada = 0;
		for (int i = 0; i < potencia.size(); i++)
		{
			for (int j = 0; j <= 100; j++)
			{
				carga_usada = j;
				potencia_int = potencia[i] * carga_usada / 100;

				if (potencia_ext + potencia_int >= p)
				{
					carga[i] = j;
					return 1;
				}
			}
			carga[i] = 100;
			potencia_ext = potencia[i];
		}

		return 0;
	}
	string getID() { return nombre_ID; }
	virtual string getTipo() { return "Central"; }
	void grabarEnFichero(ofstream& w)
	{
		w << getTipo() << " " << nombre_ID << endl;
		w << "   " << "Potencia maxima: " << CalcularPotenciaMaxima() << endl;
		w << "   " << "Precio: " << coste_base << "euros/MWh" << endl;
		w << "   " << "Carga de turbinas: " << endl;

		for (int i = 0; i < potencia.size(); i++)
		{

			w << "|   " << potencia[i] << "   |   ";
		}

		w << endl;

		for (int i = 0; i < carga.size(); i++)
		{
			w << "|   " << carga[i] << "%  |   ";
		}

		w << endl;

		w << "   " << "Mantenimiento: " << endl;
		for (int i = 0; i < historialMantenimiento.size(); i++)
		{
			historialMantenimiento[i].fecha.prt2(w); w << "   " << historialMantenimiento[i].tarea << endl;
		}

		w << endl << endl;
	}
	void setCargaACero()
	{
		for (int i = 0; i < carga.size(); i++)
		{
			carga[i] = 0;
		}
	}
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
	string getTipo() { return "EOLICA"; }
};

class EolicaOffshore : public Eolica
{
public:
	EolicaOffshore(string _nombre_ID = "", double _coste_base = 0) : Eolica(_nombre_ID, _coste_base) {}
	string getTipo() { return "EOLICA OFFSHORE"; }
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
	
	string getTipo() { return "GAS"; }
};

