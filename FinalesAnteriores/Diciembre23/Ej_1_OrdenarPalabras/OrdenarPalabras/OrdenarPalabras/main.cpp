#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string n1, n2; char opc;
	while (true)
	{
		cout << "**** Ordenando Nombres ****\n";
		cout << "Dar primer nombre: "; cin >> n1;
		cout << "Dar segundo nombre: "; cin >> n2;
		cout << "Ascendente o Descendente (A/D): "; cin >> opc;

		if (opc == 'A')
		{
			if (n1 < n2)
			{
				cout << "Nombres ordenados alfabeticamente: \n";
				cout << n1 << endl << n2;
				cout << endl;
			}

			else if (n2 > n1)
			{
				cout << "Nombres ordenados alfabeticamente: \n";
				cout << n2 << endl << n1;
				cout << endl;
			}

		}

		else if (opc == 'D')
		{
			if (n1 > n2)
			{
				cout << "Nombres ordenados alfabeticamente: \n";
				cout << n1 << endl << n2;
				cout << endl;
			}

			else if (n2 > n1)
			{
				cout << "Nombres ordenados alfabeticamente: \n";
				cout << n2 << endl << n1;
				cout << endl;
			}
		}

		char opc2;
		cout << "Desea continucar (c) o salir (s): "; cin >> opc2;

		if (opc2 == 's') { break; }
		
	}
}