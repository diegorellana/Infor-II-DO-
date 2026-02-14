#include <iostream>
using namespace std;

int* insercion(int* vec, int n, bool orden);
void print(int* vec, int n);
int* pidedatos(int& n);

int main()
{
	int n, option;
	int* my_vector;
	bool orden;
	cout << "n_datos? "; cin >> n;
	my_vector = pidedatos(n);
	print(my_vector, n);

	cout << "Orden " << endl << "1. Ascendente " << endl << "2. Descendente" << endl << "Opcion: "; cin >> option;
	(option == 1) ? orden = 1 : orden = 0;

	my_vector = insercion(my_vector, n, orden);
	cout << "Vector ordenado: " << endl;
	print(my_vector, n);

	return 0;
}

int* pidedatos(int& n)
{
	int* vector = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "v[" << i << "]: "; cin >> vector[i];
	}
	return vector;
}

void print(int* vec, int n)
{
	cout << "[";
	for (int i = 0; i < n; i++)
	{
		cout << vec[i];
		if (i != n - 1)
		{
			cout << " ";
		}
	}
	cout << "]" << endl;
}

int* insercion(int* vec, int n, bool orden)
{
	int tmp;
	int n_iteraciones = 0;
	if (orden == 1) //ascendente
	{
		for (int i = 1; i < n; i++)
		{
			int j = i;
			while(j>0 && vec[j] < vec[j-1])
			{
				tmp = vec[j-1];
				vec[j-1] = vec[j];
				vec[j] = tmp;
				++n_iteraciones;
				--j;
			}
		}
		cout << endl << "numero de iteraciones: " << n_iteraciones << endl;
	}

	if (orden == 0) //descendente
	{
		for (int i = 0; i < n; i++)
		{
			int j = i;
			while (j > 0 && vec[j] > vec[j - 1]) //si el de la derecha es mayor al de izq
			{
				tmp = vec[j-1];
				vec[j-1] = vec[j];
				vec[j] = tmp;
				++n_iteraciones;
				--j;
			}
		}
		cout << endl << "numero de iteraciones: " << n_iteraciones << endl;
	}

	return vec;
}