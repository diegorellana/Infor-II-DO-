#include <iostream>
#include <stdlib.h>
using namespace std;

void suma();
int suma(int x, int y);
void AreaCirculo();
double areaCirculo(int x);
void PermutarPorReferencia();
void Permutar(int& x, int& y);
void PrintConArray();
void ImprimeDatos(float* datos, int num);
void PunterosComoRetorno();
float* ReservarMemoria(int num);
void LiberaMemoria(float* datos);
int Factorial(int num);
void CalcularFactorial();

int main()
{
	int opc;
	while (true)
	{
		cout << "1. Salir \n";
		cout << "2. Suma \n";
		cout << "3. Area Circulo Por Valor \n";
		cout << "4. Permutar por Referencia \n";
		cout << "5. Print con Array \n";
		cout << "6. Punteros como retorno \n";
		cout << "7. Factorial \n";
		cout << "Opcion: "; cin >> opc;

		if (opc == 1) { break; }
		if (opc == 2) { suma(); }
		if (opc == 3) { AreaCirculo(); }
		if (opc == 4) { PermutarPorReferencia(); }
		if (opc == 5) { PrintConArray(); }
		if (opc == 6) { PunterosComoRetorno(); }
		if (opc == 7) { CalcularFactorial(); }
	}

	return 0;
}

void suma()
{
	int a, b, res;
	cout << "Que numeros quieres sumar: "; cin >> a >> b;
	res = suma(a, b);
	cout << a << " + " << b << " = " << res << endl;
}

int suma(int x, int y)
{
	return x + y;
}

void AreaCirculo()
{
	int r;
	cout << "Radio: "; cin >> r;
	cout << "El area es : "; cout << areaCirculo(r) << "m2" << endl;
}

double areaCirculo(int x)
{
	return 3.14 * (x * x);
}

void PermutarPorReferencia()
{
	int a; int b;
	cout << "Dar 2 numeros a permutar: "; cin >> a >> b;
	cout << "Ingresaste " << a << " y " << b << endl;
	cout << "Permutando..." << endl;
	Permutar(a, b);
	cout << "Ahora el primer numero es " << a << " y el segundo es " << b << endl;
}

void Permutar(int& x, int& y) //declarar variables normal y luego en la funcion ponerles el &
{
	int tmp = x;
	x = y;
	y = tmp;

}

void PrintConArray()
{
	int num = 10;
	float* datos;
	datos = new float[num];

	for (int i = 0; i < num; i++)
	{
		datos[i] = rand() % (100);
	}

	ImprimeDatos(datos, num); //para un array SOLO funciona pasar el puntero
}

void ImprimeDatos(float* datos, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "datos [" << i << "]: " << datos[i] << endl;
	}
}

void PunterosComoRetorno()
{
	int Num = 10; 
	float * datos = ReservarMemoria(Num);

	//Llenar el vector
	for (int i = 0; i < Num; i++)
	{
		datos[i] = rand() % (100);
	}

	//Imprimir datos
	ImprimeDatos(datos, Num);

	//Liberar Memoria
	LiberaMemoria(datos);

}

float* ReservarMemoria(int num)
{
	float* datos;
	datos = new float[num];
	return datos;
}

void LiberaMemoria(float* datos)
{
	delete[] datos;
}

void CalcularFactorial()
{
	int num;
	cout << "Num: "; cin >> num;
	cout << "Es: " << Factorial(num) << endl;
}

int Factorial(int num)
{
	if (num > 1)
	{
		num *= Factorial(num - 1);
	}

	return num;
}