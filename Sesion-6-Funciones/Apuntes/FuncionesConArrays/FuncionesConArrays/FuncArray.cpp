#include <iostream>
#include <stdlib.h>
using namespace std;

void imprimeDatos(float* dato, int num);
double func(double a, double &b);

int main()
{
	int num{ 10 }; //este será el tamaño del array
	float* dato; //los arrays funcionan con constante. Usamos punteros para saltar este problema
	dato = new float[num]; //asignación dinámica

	for (int i = 0; i < num; i++)
	{
		dato[i] = (float)rand() / RAND_MAX* 100; 
	}

	imprimeDatos(dato, num);

	//PARA PASAR POR REFERENCIA
	double a{ 5 }, b{ 3 };
	cout << "b is " << b << endl;
	cout << a << "/" << b << " = " << func(a, b) << endl; //b se cambia porque se modifica b antes de hacer cout
	cout << "b now is " << b;


}

void imprimeDatos(float* dato, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "dato [" << i << "]: " << dato[i] << endl;
	}
}

double func(double a, double &b)
{
	double temp = a / b;
	b = b / a;
	return temp; 
}