#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

struct Vertice 
{
	double x, y;
};

double CalcularArea(Vertice v[], int size)
{
	double area = 0;
	int pos = 0;


	for (int i = 0; i < size; i++)
	{
		area += abs((v[i].x + v[i + 1].y) * (v[i + 1].x - v[i].x));
	}

	area += abs((v[size].x + v[0].y) * (v[0].x - v[size].x));
	area = 0.5 * area;

	return area;
	
}

double CalcularPerimetro(Vertice v[], int size)
{
	double per = 0;

	for (int i = 0; i < size; i++)
	{
		per += sqrt(pow(v[i + 1].y - v[i].y, 2) + pow(v[i + 1].x - v[i].x, 2));
	}

	per += sqrt(pow(v[0].y - v[size].y, 2) + pow(v[0].x - v[size].x, 2));

	return per;
}

int main()
{
	int opc; Vertice* vec;
	while (true)
	{
		cout << "**** Empresa de Topografia ****\n";
		cout << "1. Dar valores\n";
		cout << "2. Salir\n";
		cout << "\t Opc: "; cin >> opc;

		if (opc == 2) 
		{ 
			break; 
		}

		if (opc == 1)
		{
			int nvert;
			cout << "Dar vertices: "; cin >> nvert;

			vec = new Vertice[nvert];

			for (int i = 0; i < nvert; i++)
			{
				cout << "Dar el punto (x,y): "; cin >> vec[i].x >> vec[i].y;
			}

			cout << "El area es: " << CalcularArea(vec, nvert) << " m2\n";
			cout << "El perimetro es: " << CalcularPerimetro(vec, nvert) << "m\n";

			delete[] vec;
		}
	}
}