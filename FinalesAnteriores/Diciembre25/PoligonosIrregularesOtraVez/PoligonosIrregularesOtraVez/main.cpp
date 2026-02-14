#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;

class Punto
{
	double x, y;
public:
	Punto(double _x = 0, double _y = 0)
	{
		x = _x; y = _y;
	}
	void Prt()
	{
		cout << "[" << x << "," << y << "]" << endl;
	}
	void setX(double _x) { x = _x; }
	void setY(double _y) { y = _y; }
	double getX() { return x; }
	double getY() { return y; }
};

class Poligono
{
	int n; //Num de puntos total
	Punto* pv; //Array de objetos Punto
	int cont;
public:
	Poligono(int _n=0) //Const.
	{
		n = _n;
		pv = new Punto[_n];
		cont = 0;
	}
	void Add(Punto& p) //agrega punto
	{
		pv[cont++] = p;
	}
	double Area() //calculo area
	{
		double area = 0;
		for (int i = 0; i < n-1; i++)
		{
			area += (pv[i].getX() * pv[i + 1].getY() - pv[i].getY() * pv[i + 1].getX());
		}
		area += pv[n - 1].getX() * pv[0].getY() - pv[n - 1].getY() * pv[0].getX();
		area = 0.5 * abs(area);

		return area;
	}
	double Perimetro() //calculo Perimetro
	{
		double perimetro = 0;
		for (int i = 0; i < n; i++)
		{
			perimetro += sqrt(pow(pv[i].getX() - pv[i + 1].getX(), 2) + pow(pv[i].getY() - pv[i + 1].getY(), 2));
		}

		perimetro += sqrt(pow(pv[0].getX() - pv[n].getX(), 2) + pow(pv[0].getY() - pv[n].getY(), 2));

		return perimetro;
	}
	void Prt() //Imprime Puntos
	{
		for (int i = 0; i < n; i++)
		{
			pv[i].Prt();
		}
	}
	
	void deletePv()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] pv;
		}
	}

	void Grabar(ofstream& w)
	{
		w << "Perimetro: " << Perimetro() << endl;
		w << "Area: " << Area();
	}
};

int main()
{
	while (true)
	{
		cout << "** Area y Perimetro **\n";
		int nvert;
		cout << "Num vertices: "; cin >> nvert;

		Poligono Pol = Poligono(nvert);
		for (int i = 0; i < nvert; i++)
		{
			double x, y;
			cout << "x,y: "; cin >> x >> y;
			Punto pt = Punto(x, y);
			Pol.Add(pt);
		}

		cout << endl << "Puntos del poligono: \n";
		Pol.Prt();

		cout << endl << "\tPerimetro: " << Pol.Perimetro() << "m\n";
		cout << "\tArea: " << Pol.Area() << "m2" << endl;

		string opc;
		cout << "Desea continuar (c) o salir (s): "; cin >> opc;

		if (opc == "s")
		{
			break;
		}

		string name;
		cout << "Nombre para grabar: "; cin >> name;

		string filename = name + ".txt";

		ofstream objeto_escritura(filename);

		Pol.Grabar(objeto_escritura);
		cout << "Registrado en " << filename << endl;
	}

	cout << "End\n";

	return 0;
}