#include <iostream>
#include <vector>
using namespace std;
#include <fstream>

class servicio
{
	char descripcion[30];
	double precio;

public:
	servicio() { ; }
	servicio(char* desc, double p)
	{
		strcpy_s(descripcion, 30, desc);
		precio = p;
	}

	void prt()
	{
		cout << "\t" << descripcion << "   " << precio << endl;
	}

	double getPrecio() { return precio; }
};

class Time
{
public:
	int hr, min;

public:
	Time(int h = 0, int m = 0)
	{
		hr = h; min = m;
	}

	void prt()
	{
		cout << hr << ":" << min;
	}

	void setHora(int h) { hr = h; }
	void setMin(int m) { min = m; }
};

class mantenimiento
{
	static double costo_hora;
	char matricula[20];
	servicio lstServ[10];
	int numServ = 0;

	Time tini, tfin;

public:
	mantenimiento(char* mat, Time t_in, int ns) : tini(t_in)
	{
		strcpy_s(matricula, 20, mat);
		numServ = ns;
		
		for (int i = 0; i < numServ; i++)
		{
			char desc[30]; double p;
			cout << "\tDescripcion: "; cin >> desc;
			cout << "\tPrecio: "; cin >> p;
			lstServ[i] = servicio(desc, p);
		}
	}

	char* getMatricula() { return matricula; }

	void prt()
	{
		cout << "-----------------------------\n";
		cout << "Matricula: " << matricula << endl;
		cout << "Hora entrada: ";  tini.prt(); cout << endl;
		cout << "Num. servicios: " << numServ << endl;
		for (int i = 0; i < numServ; i++)
		{
			lstServ[i].prt();
		}

	}

	void setHoraFin(int h_f, int m_f)
	{
		tfin.setHora(h_f);
		tfin.setMin(m_f);
	}

	void pagar()
	{
		int horas; double cost_mat = 0;
		cout << "Horas o fraccion: "; cin >> horas;
		cout << "Costo por hora: " << costo_hora << endl;

		for (int i = 0; i < numServ; i++)
		{
			cost_mat += lstServ[i].getPrecio();
		}

		cout << "Costo materiales: " << cost_mat << endl;
		cout << "Costo mano de obra: " << horas * costo_hora << endl;
		cout << "Costo total: " << cost_mat + (horas * costo_hora) << endl;
	}
};
