#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string>lst;
	string name;
	while (true)
	{
		cout << "Name? (exit == salir) "; cin >> name;

		if (name == "exit") { break; }

		else
		{
			lst.push_back(name);
		}
	}

	int opc;
	cout << "Orden: " << endl;
	cout << "1. Ascendente" << endl;
	cout << "2. Descendente" << endl;
	cin >> opc;
	
	if (opc == 1)
	{
		string tmp;
		for (int i = 0; i < lst.size(); i++)
		{
			for (int j = 0; j < lst.size(); j++)
			{
				if (lst[i] < lst[j])
				{
					tmp = lst[i];
					lst[i] = lst[j];
					lst[j] = tmp;
				}
			}
		}
	}

	if (opc == 2)
	{
		string tmp;
		for (int i = 0; i < lst.size(); i++)
		{
			for (int j = 0; j < lst.size(); j++)
			{
				if (lst[i] > lst[j])
				{
					tmp = lst[i];
					lst[i] = lst[j];
					lst[j] = tmp;
				}
			}
		}
	}

	cout << "Ordenado: " << endl;

	for (int i = 0; i < lst.size(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}