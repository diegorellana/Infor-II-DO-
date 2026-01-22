#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


class Hora
{
	int hh, min;
public:
	Hora(int _hh = 0, int _m = 0) { hh = _hh; min = _m; }
	
	int getHora() { return hh; }
	int getMin() { return min; }
};

class Actividad
{
	char nombre[20]; //zumba,gap,bike,etc
	char sala[20]; //sala1, master1, etc.
	int numPersonas; //Ira decreciendo
	Hora Ini, Fin; //Hora inicio y fin
public:
	Actividad() { ; }
	Actividad(char* n, char* s, int np, Hora h_ini, Hora h_fin) : Ini(h_ini), Fin(h_fin)
	{
		strcpy_s(nombre, 20, n);
		strcpy_s(sala, 20, s);
		numPersonas = np;
	}
	
	void prt()
	{
		cout << "   " << nombre << "     " << sala << "     " << numPersonas << "    " << " de " << Ini.getHora() << ":" << Ini.getMin();
		cout << "  a  " << Fin.getHora() << ":" << Fin.getMin() << endl;
	}

	void prt2()
	{
		cout << "   " << nombre << "     " << sala << "     " << " de " << Ini.getHora() << ":" << Ini.getMin();
		cout << "  a  " << Fin.getHora() << ":" << Fin.getMin() << endl;
	}

	char* getNombre() { return nombre; }

	void addReserva() { numPersonas--; }

};

class Reserva
{
	int carnet; //carnet socio
	Actividad* lst; //puntero a la actividad
public:
	Reserva() { ; }

	Reserva(int c, Actividad* act)
	{ 
		carnet = c;
		lst = act;
	}
	//más funciones si necesita

	void prt()
	{
		cout << carnet << "\t\t"; lst->prt2(); cout << endl;
	}
};



