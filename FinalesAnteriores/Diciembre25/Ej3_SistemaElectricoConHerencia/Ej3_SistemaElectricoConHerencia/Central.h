#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

namespace EUR
{
	class Fecha
	{
		int d, m, y;
	public:
		Fecha(int dd=0, int mm=0, int yy=0)
		{
			d = dd; m = mm; y = yy;
		}

		void prt()
		{
			cout << d << "/" << m << "/" << y;
		}

		int getDay() { return d; }
		int getMonth() { return m; }
		int getYear() { return y; }
	};
}

namespace INT
{
	class Fecha
	{
		int d, m, y;
	public:
		Fecha(int dd, int mm, int yy)
		{
			d = dd; m = mm; y = yy;
		}

		void prt()
		{
			cout << m << "/" << d << "/" << y;
		}
	};
}


class mantenimiento
{
public:
	EUR::Fecha fecha;
	string tarea;
	mantenimiento(EUR::Fecha f, string t) { fecha = f; tarea = t; }
};

class Central
{
	string nombre_ID;
	double coste_base; // Costes fijos de generación por MWh
protected:
	vector <double> potencia; // En esta variable se almacena la potencia unitaria //de cada elemento de la Central
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
		cout << getTipo() << endl;
		cout << nombre_ID << endl;
		cout << "Potencia Maxima: " << CalcularPotenciaMaxima() << endl;
		cout << "Precio: " << coste_base << endl;
		cout << "Carga de turbinas: " << endl;

		for (int i = 0; i < potencia.size(); i++)
		{
			cout << potencia[i] << " MW     ";
		}

		cout << endl;

		for (int i = 0; i < carga.size(); i++)
		{
			cout << carga[i] << " %     ";
		}

		cout << endl;
		cout << "Mantenimiento:\n";
		for (int i = 0; i < historialMantenimiento.size(); i++)
		{
			historialMantenimiento[i].fecha.prt();
			cout << "    " << historialMantenimiento[i].tarea;
			cout << endl;
		}

		cout << endl << endl;

	}
	double CalcularPotenciaTotal()
	{
		double pot_tot = 0;
		for (int i = 0; i < potencia.size(); i++)
		{
			pot_tot += potencia[i] * carga[i];
		}
		return pot_tot;
	}
	double CalcularPotenciaMaxima()
	{
		double pot = 0;
		for (int i = 0; i < potencia.size(); i++)
		{
			pot += potencia[i];
		}
		return pot;
	}
	bool AjustarCargaPotenciaObjetivo(double p)
	{
		double suma_pot = 0;
		double suma_int;
		double suma_aux;

		//todas las cargas a 0
		for (int i = 0; i < carga.size(); i++)
		{
			carga[i] = 0;
		}

		//se ajusta progresivamente
		for (int i = 0; i < potencia.size(); i++)
		{
			for (int j = 0; j <= 100; j++)
			{
				carga[i] = j;
				suma_int = potencia[i] * j / 100;
				suma_aux = suma_pot + suma_int;

				if (suma_aux >= p)
				{
					suma_pot = suma_aux;
					return 1;
				}
			}
			suma_pot += potencia[i];
		}

		//si no soporta el ajuste
		return 0;
	}
	void GrabarEnFichero(ofstream& write)
	{
		write << getTipo() << endl;
		write << nombre_ID << endl;
		write << "Potencia Maxima: " << CalcularPotenciaMaxima() << endl;
		write << "Precio: " << coste_base << endl;
		write << "Carga de turbinas: " << endl;

		for (int i = 0; i < potencia.size(); i++)
		{
			write << potencia[i] << " MW     ";
		}

		write << endl;

		for (int i = 0; i < carga.size(); i++)
		{
			write << carga[i] << " %     ";
		}

		write << endl;
		write << "Mantenimiento:\n";
		for (int i = 0; i < historialMantenimiento.size(); i++)
		{
			write << historialMantenimiento[i].fecha.getDay() << "/" << historialMantenimiento[i].fecha.getMonth() << "/" << historialMantenimiento[i].fecha.getYear();
			write << "    " << historialMantenimiento[i].tarea;
			write << endl;
		}

		write << endl << endl;
	}
	// Añada otras funciones si es necesario
	//void add fecha(EUR::Fecha f) {historialMantenimiento.push_back() }
	virtual string getTipo() { return "Central"; }
	virtual double CalcularPrecioMWh() { return 0; }
	double getCosteBase() { return coste_base; }
	string getNombre() { return nombre_ID; }
	int getPotenciaSize() { return potencia.size(); }
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

	double CalcularPrecioMWh()
	{
		return getCosteBase();
	}
	string getTipo() { return "EOLICA"; }
};
class EolicaOffshore : public Eolica 
{
public:
	EolicaOffshore(string _nombre_ID = "", double _coste_base = 0) : Eolica(_nombre_ID, _coste_base) {}
	// Añada otras funciones si es necesario

	string getTipo() { return "EOLICA OFFSHORE"; }
	double CalcularPrecioMWh()
	{
		return 1.5 * getCosteBase();
	}
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
	
	double CalcularPrecioMWh()
	{
		return getCosteBase() + (precio_gas * consumo_gas);
	}
	string getTipo() { return "CENTRAL GAS"; }
};

