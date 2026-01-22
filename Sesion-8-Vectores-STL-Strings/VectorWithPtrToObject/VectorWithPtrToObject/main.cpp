#include "Vehiculo.h"

int main()
{
	vector <Vehiculo*> lst; //vector de punteros a vehiculo
	int opc;
	while (true)
	{
		cout << "Menu" << endl;
		cout << "1. Add" << endl;
		cout << "2. Ver" << endl;
		cout << "3. Borrar" << endl;
		cout << "4. Salir" << endl;
		cout << "Opc? "; cin >> opc;

		if (opc == 4) 
		{ 
			lst.clear();
			break;
		}

		if (opc == 1)
		{
			string cs;
			cout << "Matricula? "; cin >> cs;
			Vehiculo* v = new Vehiculo(cs);
			lst.push_back(v);
		}

		if (opc == 2)
		{
			for (int i = 0; i < lst.size(); i++)
			{
				lst[i]->prt();
			}
		}

		if (opc == 3)
		{
			int pos;
			cout << "Pos? (Max " << lst.size()-1 << "): "; cin >> pos;
			lst.erase(lst.begin() + pos);
			cout << "Erased. ";
		}

	}
}