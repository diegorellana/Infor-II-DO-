#include <iostream>
using namespace std;
#include <stdlib.h>

float* ReservaMemoria(int num);
void AsignarDatos(float* array, int num);
void ImprimeDatos(float* array, int num);
void BorraMemoria(float* array);

int main()
{
	int num{ 10 };
	float* dato;

	dato = ReservaMemoria(num);
	AsignarDatos(dato, num);
	ImprimeDatos(dato, num);
	BorraMemoria(dato);


}

float* ReservaMemoria(int num)
{
	float* vec;
	vec = new float[num];
	return vec;
}

void AsignarDatos(float* array, int num)
{
	for (int i = 0; i < num; i++)
	{
		array[i] = (float)rand() / RAND_MAX * 1000;
	}
}

void ImprimeDatos(float* array, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "dato [" << i << "]: " << array[i] <<  endl;
	}
}

void BorraMemoria(float* array)
{
	delete[] array;
}