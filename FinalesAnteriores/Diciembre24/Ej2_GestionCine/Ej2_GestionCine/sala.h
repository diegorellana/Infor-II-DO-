#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class hora
{
private:
	int hh; //hora
	int min; //minutos
public:
	hora(int _hh = 0, int _mm = 0)
	{
		hh = _hh; min = _mm;
	}

	int getHora() { return hh; }
	int getMin() { return min; }
};

class sala
{
private:
	char asiento[20][30]; //max 20 filas y 30 asientos/fila: ‘0’ ocupado
	int fils, cols; //numero real de filas y columnas
	char pelicula[40]; //nombre de la pelicula
	double precio; //precio
	hora h; //hora de la sesion
public:
	int cont = 0;
	sala(int fil = 0, int col = 0, const char* p = "", double pr = 0, int _hh = 0, int _mm = 0) : h(_hh, _mm)
	{
		fils = fil; cols = col; strcpy_s(pelicula, 40, p); precio = pr;

		for (int i = 0; i < fils; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				asiento[i][j] = '0';
			}
		}
	}
	void prt() //imprimir la ocupación de la sala
	{
		//imprimo numeros
		cout << "   ";
		for (int i = 0; i < cols; i++)
		{
			cout << i + 1 << "   ";
		}
		cout << endl;

		for (int i = 0; i < fils; i++)
		{
			cout << i + 1 << "  ";
			for (int j = 0; j < cols; j++)
			{
				cout << asiento[i][j] << "   ";
			}
			cout << endl;
		}
	}
	void comprar() //comprar entradas a la sala
	{
		int f, c;
		cout << "Dar fila y columna: "; cin >> f >> c;

		if (asiento[f-1][c-1] == '0')
		{
			asiento[f-1][c-1] = '1';
		}

		else if (asiento[f-1][c-1] == '1')
		{
			cout << "Asiento ocupado.\n";
		}
	}
	void devolver() //devolver entradas (una a una)
	{
		int f, c;
		cout << "Dar fila y columna: "; cin >> f >> c;

		if (asiento[f-1][c-1] == '1')
		{
			asiento[f-1][c-1] = '0';
		}

		else if (asiento[f-1][c-1] == '0')
		{
			cout << "Asiento sin entrada.\n";
		}
	}
	double recaudado() //mostrar la ocupación y lo recaudado
	{
		prt();
		cout << endl;
		cout << "Recaudado: ";

		double recaudado = 0;
		for (int i = 0; i < fils; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (asiento[i][j] == '1')
				{
					recaudado += precio;
				}
			}
		}

		cout << recaudado <<  " euros " << endl << endl;

		return recaudado;
	}

	char* getPeli() { return pelicula; }
	int getHora() { return h.getHora(); }
	int getMin() { return h.getMin(); }
	double getPrecio() { return precio; }
};

