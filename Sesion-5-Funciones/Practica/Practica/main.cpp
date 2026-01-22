#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

double Distance(double x1, double y1, double x2, double y2);
void CalcularDistancia();
void CalcularNumerosPrimos();
bool Prime(int x);
void CalcularRaices();
double fx(double x);
double Midpoint(double a, double b, int max, int &num);
void CalcularSerie();
double Exp(double x, int Num);
double Exp(double x, double Error, int& num);
int Factorial(int x);

int main()
{
	int opc;
	while (true)
	{
		cout << "1. Salir\n";
		cout << "2. Calcular Distancia\n";
		cout << "3. Numeros Primos \n";
		cout << "4. Calcular Raices \n";
		cout << "5. Series de e^x \n";
		cout << "Opcion: "; cin >> opc;

		if (opc == 1) { break; }
		if (opc == 2) { CalcularDistancia(); }
		if (opc == 3) { CalcularNumerosPrimos(); }
		if (opc == 4) { CalcularRaices(); }
		if (opc == 5) { CalcularSerie(); }
	}
}

double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}
void CalcularDistancia()
{
	double x1, x2, y1, y2;
	cout << "x1 y1: "; cin >> x1 >> y1;
	cout << "x2 y2: "; cin >> x2 >> y2;

	cout << "La distancia es " << Distance(x1, y1, x2, y2) << endl;
}

void CalcularNumerosPrimos()
{
	int n1, n2, tmp;
	cout << "Dar numero 1: "; cin >> n1;
	cout << "Dar numero 2: "; cin >> n2;

	if (n1 > n2)
	{
		tmp = n1;
		n1 = n2;
		n2 = tmp;
	}

	for (int i = n1; i < n2 + 1; i++)
	{
		if (Prime(i))
		{
			cout << i << " es primo" << endl;
		}
	}
}

bool Prime(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}

	return true;
}

void CalcularRaices()
{
	double a, b;
	int max = 300; int num;
	cout << "Intervalo (a,b): "; cin >> a >> b;

	//Comprobar si intervalo es correcto
	if (fx(a) * fx(b) > 0)
	{
		cout << "ERROR. Compruebe intervalo." << endl;
	}

	else if (fx(a) * fx(b) < 0)
	{
		double root = Midpoint(a, b, max, num);
		cout << "La raiz es " << root << endl;
	}

}

double fx(double x)
{
	double f = x - cos(x);
	return f;
}

double Midpoint(double a, double b, int max, int &num)
{
	double m, ym, ZERO = 1e-9;
	num=0; //important


	//Algorithm
	while (abs(b - a) > ZERO && num < max)
	{
		m = (a + b) / 2; //midpoint
		if (fx(a) * fx(m) < 0)
		{
			b = m;
			num++;
		}

		else if (fx(m) * fx(b) < 0)
		{
			a = m;
			num++;
		}

		else if (fx(m) == 0)
		{
			return m;
		}
	}


	return m;
}

void CalcularSerie()
{
	int opc2;
	cout << "1. Segun numero de iteraciones\n";
	cout << "2. Segun cantidad de error \n";
	cout << "Opcion: "; cin >> opc2;

	if (opc2 == 1)
	{
		int num; double x;
		cout << "Numero de iteraciones: "; cin >> num;
		cout << "x: "; cin >> x;
		cout << "e^" << x << " = " << Exp(x, num) << endl;
	}

	if (opc2 == 2)
	{
		double error; double x; int num;
		cout << "Cantidad de error: "; cin >> error;
		cout << "x: "; cin >> x;
		cout << "e^" << x << " = " << Exp(x, error, num) << endl;
	}

}

double Exp(double x, int Num)
{
	double sum = 0;
	for (int i = 1; i < Num + 1; i++)
	{
		sum += (pow(x, i - 1)) / Factorial(i-1);
	}

	return sum;
}

int Factorial(int x)
{
	int fact = 1;
	if (x == 0 || x == 1) { return fact; }

	for (int i = 2; i <= x; i++)
	{
		fact *= i;
	}

	return fact;
}

double Exp(double x, double Error, int& num)
{
	double sum = 0, sum2 = 0; int i = 1;
	while (true)
	{
		sum += (pow(x, i - 1)) / Factorial(i-1);
		sum2 += (pow(x, i)) / Factorial(i);

		if (abs(sum2 - sum) < Error)
		{
			break;
		}
		i++;
		num++;
	}

	return sum;
}