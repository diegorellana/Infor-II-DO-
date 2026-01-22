#include <iostream>
#include <cstring>
#include <cmath>
#include <math.h>
#define NUMM 10
using namespace std;

void ej1_calcular_distancias();
void ej2_suma_de_matrices();
void ej3_fracciones();
void ej4_dist_con_structs();
void ej5_desviaciones_estandar();
void ej6_taylor_series();
int factorial(int x);

int main()
{
	int opc;
	while (true)
	{
		cout << "1. Calcular Distancias" << endl;
		cout << "2. Suma de Matrices" << endl;
		cout << "3. Uso de Fracciones" << endl;
		cout << "4. Distancias usando estructuras" << endl;
		cout << "5. Desviaciones estándar" << endl;
		cout << "6. Taylor Series" << endl;
		cout << "7. Salir" << endl;
		cout << "Opcion: "; cin >> opc;

		if (opc == 7) { break; }

		if (opc == 1)
		{
			ej1_calcular_distancias();
		}

		if (opc == 2)
		{
			ej2_suma_de_matrices();
		}

		if (opc == 3)
		{
			ej3_fracciones();
		}

		if (opc == 4)
		{
			ej4_dist_con_structs();
		}

		if (opc == 5)
		{
			ej5_desviaciones_estandar();
		}

		if (opc == 6)
		{
			ej6_taylor_series();
		}
	}


	return 0;
}

void ej1_calcular_distancias()
{
	const int NUM = 10; //max value
	double x[NUM], y[NUM];
	int n; double distance = 0; double distance2; double min_dist=0;
	int x1_min=0, x2_min=0, y1_min=0, y2_min=0;

	cout << "Cuantos puntos vas a ingresar (MAX 10): "; cin >> n;

	if (n > NUM) { cout << "Error."; }

	else
	{
		for (int i = 0; i < n; i++)
		{
			cout << "x[" << i + 1 << "], " << "y [" << i + 1 << "]: "; cin >> x[i] >> y[i];
		}

		cout << "Los puntos ingresados son: " << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "(" << "x" << i + 1 << "," << "y" << i + 1 << "): " << "(" << x[i] << "," << y[i] << ")" << endl;
		}

		for (int i = 0; i < n-1; i++)
		{
			//La primera distancia es la referencia
			if (i == 0) 
			{ 
				min_dist = sqrt(pow(x[i + 1] - x[i], 2) + pow(y[i + 1] - y[i], 2)); 
				x1_min = x[i];
				x2_min = x[i + 1];
				y1_min = y[i];
				y2_min = y[i + 1];
			}

			if (i > 0)
			{
				distance2 = sqrt(pow(x[i + 1] - x[i], 2) + pow(y[i + 1] - y[i], 2));

				if (distance2 < min_dist)
				{
					min_dist = distance2;
					x1_min = x[i];
					x2_min = x[i + 1];
					y1_min = y[i];
					y2_min = y[i + 1];
				}
			}
		}

		cout << "La minima distancia entre puntos es: " << min_dist << ", dada entre los puntos (" << x1_min << "," << y1_min << ") y (" << x2_min << "," << y2_min << ")" << endl;
	}
}

void ej2_suma_de_matrices()
{
	double matA[NUMM][NUMM], matB[NUMM][NUMM], matC[NUMM][NUMM]; int n;

	cout << "Cuantas filas y columnas quieres asignar? "; cin >> n;

	//Para matriz A
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "matA [" << i + 1 << "][" << j + 1 << "]: "; cin >> matA[i][j];
		}
	}

	//Para matriz B
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "matB [" << i + 1 << "][" << j + 1 << "]: "; cin >> matB[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matC[i][j] = matA[i][j] + matB[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "matC [" << i + 1 << "][" << j + 1 << "]: " << matC[i][j] << endl;
		}
	}
}

void ej3_fracciones()
{
	struct fraction
	{
		int num;
		int den;
	};

	fraction f1, f2, f3;

	cout << "Numerador y denominador para f1: "; cin >> f1.num >> f1.den;
	cout << "Numerador y denominador para f2: "; cin >> f2.num >> f2.den;

	//Multiplicar fracciones
	f3.num = f1.num * f2.num;
	f3.den = f1.den * f2.den;

	cout << "f3 = f1 * f2 = " << f3.num << "/" << f3.den << endl;

	//Sumar fracciones
	f3.den = f1.den * f2.den;
	f3.num = f2.den * f1.num + f2.num * f1.den;

	cout << "f3 = f1 + f2 = " << f3.num << "/" << f3.den << endl;
}

void ej4_dist_con_structs()
{
	struct Point
	{
		int x;
		int y;
	};

	const int NUM = 10;
	Point Pts[NUM];
	int n;
	double distance = 0; double distance2; double min_dist = 0;
	int x1_min = 0, x2_min = 0, y1_min = 0, y2_min = 0;

	cout << "Cuantos puntos vas a asignar? "; cin >> n;

	if (n > NUM) { cout << "Error."; }

	else
	{
		for (int i = 0; i < n; i++)
		{
			cout << "x[" << i + 1 << "], " << "y [" << i + 1 << "]: "; cin >> Pts[i].x >> Pts[i].y;
		}

		cout << "Los puntos ingresados son: " << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "(" << "x" << i + 1 << "," << "y" << i + 1 << "): " << "(" << Pts[i].x << "," << Pts[i].y << ")" << endl;
		}

		for (int i = 0; i < n - 1; i++)
		{
			//La primera distancia es la referencia
			if (i == 0) 
			{ 
				min_dist = sqrt(pow(Pts[i + 1].x - Pts[i].x, 2) + pow(Pts[i + 1].y - Pts[i].y, 2)); 
				x1_min = Pts[i].x;
				x2_min = Pts[i + 1].x;
				y1_min = Pts[i].y;
				y2_min = Pts[i + 1].y;
			}

			if (i > 0)
			{
				distance2 = sqrt(pow(Pts[i + 1].x - Pts[i].x, 2) + pow(Pts[i + 1].y - Pts[i].y, 2));

				if (distance2 < min_dist)
				{
					min_dist = distance2;
					x1_min = Pts[i].x;
					x2_min = Pts[i + 1].x;
					y1_min = Pts[i].y;
					y2_min = Pts[i + 1].y;
				}
			}
		}

		cout << "La minima distancia entre puntos es: " << min_dist << ", dada entre los puntos (" << x1_min << "," << y1_min << ") y (" << x2_min << "," << y2_min << ")" << endl;
	}
	
}

void ej5_desviaciones_estandar()
{
	int num = 0;
	double data[100];
	double avg = 0, dev = 0, sum = 0;

	cout << "Num? "; cin >> num;

	if (num > 100) { cout << "Error"; }

	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << "data [" << i + 1 << "]: "; cin >> data[i];
		}

		for (int i = 0; i < num-1; i++)
		{
			avg += data[i];
		}
		avg = avg / num;

		for (int i = 0; i < num-1; i++)
		{
			sum += (pow(data[i] - avg, 2));
		}
		dev = sqrt(sum/num - 1);

		cout << "Average value: " << avg << endl;
		cout << "Standard deviation: " << dev << endl;
	}
}

void ej6_taylor_series()
{
	int opc2;
	cout << "1. Por iteraciones" << endl;
	cout << "2. Por error" << endl;
	cout << "Opcion: "; cin >> opc2;
	double sinx = 0;

	if (opc2 == 1)
	{
		int angle; int it;
		cout << "Angulo: "; cin >> angle;
		cout << "Num. de iteraciones: "; cin >> it;
		angle = angle * 3, 14 / 180;

		for (int i = 0; i < it; i++)
		{
			sinx += pow(-1, (i + 1) + 1) * pow(angle, 2 * (i + 1) - 1) / factorial(2 * (i + 1 - 1));
		}

		cout << "sinx = " << sinx << endl;
	}

	if (opc2 == 2)
	{

	}
}

int factorial(int x)
{
	int fact = 1;
	for (int i = 1; i < x + 1; i++)
	{
		fact = fact * i;
	}

	return fact;
}