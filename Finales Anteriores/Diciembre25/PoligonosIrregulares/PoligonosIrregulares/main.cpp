#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

class Punto
{
	double x, y;
public:
	Punto(double _x = 0, double _y = 0) { x = _x; y = _y; }
	void Prt()
	{
		cout << "[" << x << "," << y << "]\n";
	}

	//agregar + funciones
	double getX() { return x; }
	double getY() { return y; }
};

class Poligono
{
	int n; //Num de puntos total
	Punto* pv; //Array de objetos Punto
	int cont = 0;
public:
	Poligono(int _n) //Const.
	{
		n = _n;
		pv = new Punto[n];
		//cont = 0;
	}
	void Add(Punto& p) //agrega punto
	{
		pv[cont] = p;
		cont++;
	}
	double Area() //calculo area
	{
		double area = 0;
		for (int i = 0; i < n - 1; i++)
		{
			area += abs(pv[i].getX() * pv[i + 1].getY() - pv[i].getY() * pv[i + 1].getX());
		}

		//ultimo con primero
		area += abs(pv[n - 1].getX() * pv[0].getY() - pv[n - 1].getY() * pv[0].getX());

		//0.5
		area = 0.5 * abs(area);

		return area;
	}
	double Perimetro() //calculo Perimetro
	{
		double perimetro = 0;

		//RECORRED BIEN!!!
		for (int i = 1; i < n; i++)
		{
			double x_i = pv[i].getX();
			double x_0 = pv[i - 1].getX();
			double y_i = pv[i].getY();
			double y_0 = pv[i - 1].getY();

			perimetro += sqrt(pow(pv[i].getX() - pv[i - 1].getX(), 2) + pow(pv[i].getY() - pv[i - 1].getY(), 2));
		}

		//sumo el ultimo y el primero
		perimetro += sqrt(pow(pv[0].getX() - pv[n-1].getX(), 2) + pow(pv[0].getY() - pv[n-1].getY(), 2));

		return perimetro;
	}
	void Prt() //Imprime Puntos
	{
		for (int i = 0; i < n; i++)
		{
			pv[i].Prt();
		}
	}
	//agregar + funciones, si necesita
};

void Grabar(Poligono& pol)
{
	string file;
	cout << "Nombre de archivo para grabar (sin extension): "; cin >> file;
	string filename = file + ".txt";

	ofstream objeto_escritura(filename);

	if (objeto_escritura.is_open())
	{
		objeto_escritura << "Perimetro: " << pol.Perimetro() << endl;
		objeto_escritura << "Area: " << pol.Area();
	}

	cout << endl << "Archivo guardado correctamente. ";
	objeto_escritura.close();
	cout << endl << endl;
}

int main()
{
	int opc, vert;
	while (true)
	{
		cout << "** Pol: Area y Perimetro ** \n";
		cout << "Numero de vertices: "; cin >> vert;

		Punto* pv = new Punto[vert]; //creo un array de n puntos usando new 
		Poligono pol = Poligono(vert); //uso el constructor de poligono sabiendo que tiene n vertices
		for (int i = 0; i < vert; i++)
		{
			double x, y; //pido puntos
			cout << "x, y: "; cin >> x >> y;

			Punto point; //creo punto
			point = Punto(x, y); //le pongo los valores que acabo de ingresar
			pv[i] = point; //lo pongo en el array de puntos que cree al principio

			pol.Add(pv[i]); //pongo el punto en el poligono usando la funcion Add
		}


		cout << "**Puntos del Poligono**\n";
		pol.Prt();

		char op;
		cout << "\n Perimetro: " << pol.Perimetro() << endl;
		cout << "Area: " << pol.Area() << " m2" << endl;
		cout << "Desea continuar <c> o salir <s>: "; cin >> op;

		if (op == 's') { break; }

		Grabar(pol);
	}
}