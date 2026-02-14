#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char* DecToHex(int numDec)
{
	//Saco size del char
	int cont = 0;
	int num = numDec;

	while (numDec > 0)
	{
		numDec = numDec / 16;
		cont++;
	}

	/*
	679	0
	42	1
	2	2
	0	
	*/

	//Ahora que se el size
	char* Hex = new char[cont+1];

	// ['2','A','7','\0']
	// [0 , 1, 2 , 3]
	// size = 4 y Hex[4] = '\0'

	Hex[cont] = '\0';
	cont--;


	//IMP!!
	//char vec[] = {'0','1','2','3','4','5', '6', '7', '8' '9', '10',}

	while (num > 0)
	{
		int res = num % 16;

		num = num / 16;
		if (res < 10)
		{
			//Hex[cont] = vec[res]; //asi se escribe el numero tal cual
			cont--;
		}

		if (res >= 10)
		{
			char aux = 'A';

			for (int i = 10; i < 16; i++)
			{
				if (i == res)
				{
					Hex[cont] = (char) aux+(i-10);
					cont--;
					break;
				}
			}
		}
	}

	//Cuando Salga...


	return Hex;
}

int HexToDec(char* numHex)
{
	//['2','A','7','\0']

	int size = 0;
	int suma = 0;

	//Saco size
	while (numHex[size] != '\0')
	{
		size++;
	}

	int* vec = new int[strlen(numHex)];

	//para asignar
	//['2','A','7']
	//[... , ..., ...]

	char vector_aux[] = { '0','1','2','3','4','5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };


	for (int i = 0; i < strlen(numHex); i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (numHex[i] == vector_aux[j])
			{
				vec[i] = j;
			}
		}

	}

	int suma = 0;
	for (int i = 0; i < strlen(numHex); i++)
	{
		suma += vec[i] * pow(16, i);
	}
	

	return suma;

	for (int i = 0; i <= size+1; i++)
	{
		char numAux = '0';
		char charAux = 'A';

		//Busco si es numero
		for (int j = 0; j < 10; j++)
		{
			if (numHex[i] == numAux + j)
			{
				suma += (j) * pow(16, size-1);
				size--;
				break;
			}
		}

		//Busco si es letra
		for (int j = 0; j < 6; j++)
		{
			if (numHex[i] == charAux + j)
			{
				suma += (10 + j) * pow(16, size-1);
				size--;
				break;
			}
		}
	}

	return suma;

	
}

int main()
{
	int opc;
	while (true)
	{
		cout << "Conversor Hexadecimal a Decimal\n";
		cout << "1. Dec -> Hex\n";
		cout << "2. Hex -> Dec\n";
		cout << "3. Salir\n";
		cout << "Opcion: "; cin >> opc;

		if (opc == 3) { break; }

		if (opc == 1)
		{
			int numDec;
			cout << "Ingresar numero: "; cin >> numDec;
			cout << numDec << " en hex es " << DecToHex(numDec) << endl;
		}

		if (opc == 2)
		{
			char hex_buff[50];
			cout << "Dar numero en hex (mayusculas): "; cin >> hex_buff;
			int size = strlen(hex_buff);

			char* hex = new char[size + 1];
			strcpy_s(hex, size + 1, hex_buff);

			cout << hex << " en decimal es " << HexToDec(hex) << endl;
		}
	}

	cout << "Adios.\n";
	return 0;
}