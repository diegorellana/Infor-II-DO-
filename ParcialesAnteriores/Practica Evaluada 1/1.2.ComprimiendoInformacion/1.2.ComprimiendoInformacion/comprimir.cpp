#include <iostream>
using namespace std;
#include <stdlib.h>
#include <cstdlib>

int* generarData(int& num);
int* comprimeData(int* vec, int num, int& nnum);
void printData(int* vec, int num);

int main()
{
	int size{};
	cout << "Dar Num: "; cin >> size;
	int* vector = generarData(size);
	cout << "Datos: " << endl;
	printData(vector, size);
	cout << endl << "Datos comprimidos: " << endl;

	int size_new;
	if (size % 2 == 0)
	{
		size_new = size / 2;
	}
	else
	{
		size_new = size / 2 + 1;
	}
	int* vector_comprimido = comprimeData(vector, size, size_new);

	printData(vector_comprimido, size_new);

	return 0;
}


int* generarData(int& num)
{
	int* vec = new int[num];

	for (int i = 0; i < num; i++)
	{
		vec[i] = rand() % 100 + 1;
	}

	return vec;
}

int* comprimeData(int* vec, int num, int& nnum)
{
	int size_new;
	if (num % 2 == 0)
	{
		size_new = num / 2;
	}
	else
	{
		size_new = num / 2 + 1;
	}

	int* vec_new = new int[nnum];

	int a=0;
	for (int i = 0; i < num; i=i+2)
	{
		int media = (vec[i] + vec[i+1]) / 2;
		vec_new[a] = media;
		a++;
		if (i+1 == num) //cuando este en el penultimo
		{
			vec_new[nnum-1] = vec[num-1];
		}
		
	}

	return vec_new;
}


void printData(int* vec, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << vec[i] << " ";
	}
}