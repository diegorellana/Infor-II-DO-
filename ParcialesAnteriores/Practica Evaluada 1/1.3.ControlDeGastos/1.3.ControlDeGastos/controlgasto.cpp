#include <iostream>
using namespace std;

struct Gasto
{
	char nombre[40];
	double valor;
	int dia;
};

void CargarGasto(Gasto* ptr, int n);
void VerGastos(Gasto* ptr, int n);

int main()
{
	int opcion, ngastos{ 0 };
	Gasto* gastos = new Gasto[ngastos];
	while (true)
	{
		cout << "*** Menu ***" << endl;
		cout << "1. Cargar Gasto" << endl;
		cout << "2. Ver Gastos" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: "; cin >> opcion;

		if (opcion == 3)
		{
			cout << "Adios.";
			break;
		}

		else if (opcion == 1)
		{
			CargarGasto(gastos, ngastos);
			ngastos++;
		}

		else
		{
			VerGastos(gastos, ngastos);
		}

	}
	return 0;
}

void CargarGasto(Gasto* ptr, int n)
{
	cout << "Nombre: "; cin >> ptr[n].nombre;
	cout << "Valor: "; cin >> ptr[n].valor;
	cout << "Dia: "; cin >> ptr[n].dia;
}

void VerGastos(Gasto* ptr, int n)
{
	double sumagasto = 0;
	cout << "**** Lista de Gastos ****" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ptr[i].nombre << "	" << ptr[i].valor << "	" << ptr[i].dia << endl;
		sumagasto = sumagasto + ptr[i].valor;
	}
	cout << "Gasto total: " << sumagasto << endl;
}