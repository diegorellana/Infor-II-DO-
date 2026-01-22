#include "student.h"
#define NUMS 5

void DynamicObjects();
void StaticAndDynamicArrays();

int main()
{
	int op;
	while (true)
	{
		cout << "1. Salir" << endl;
		cout << "2. Dynamic Objects " << endl;
		cout << "3. Static and Dynamic Arrays" << endl;
		cout << "Opcion: "; cin >> op;

		if (op == 1) { break; }

		if (op == 2) { DynamicObjects(); }

		if (op == 3) { StaticAndDynamicArrays(); }
	}
}

void DynamicObjects()
{
	int n = 0;
	cout << "Dynamic objects" << endl;

	Student* pl[100]; //Array of dynamic objects
	pl[n] = new Student((char*)"Ana", 6.0); //ex of creating new student
	pl[n]->prt();	//ex of prt()
	n++;

	int opc;
	while (true)
	{
		cout << "Menu \n1.Add\n2.Prt\n3.Exit\nOpcion: ";
		cin >> opc;

		if (opc == 1)
		{
			char name_buff[20]; double avg;
			cout << "Name: "; cin >> name_buff;
			cout << "Avg: "; cin >> avg;

			pl[n] = new Student((char*)name_buff, avg);
			n++;
		}

		if (opc == 2)
		{
			for (int i = 0; i < n; i++)
			{
				pl[i]->prt();
			}
		}

		if (opc == 3)
		{
			break;
		}
	}
}

void  StaticAndDynamicArrays()
{
	int num;
	cout << "Static" << endl;
	Student vec[NUMS];

	for (int i = 0; i < NUMS; i++)
	{
		vec[i].get();
	}

	cout << "Data" << endl;
	for (int i = 0; i < NUMS; i++)
	{
		vec[i].prt();
	}

	cout << "Dynamic" << endl;
	cout << "Enter number of students: "; cin >> num;
	Student* pv = new Student[num];

	for (int i = 0; i < num; i++)
	{
		pv[i].get();
	}

	cout << "Data:" << endl;
	for (int i = 0; i < num; i++)
	{
		pv[i].prt();
	}

	delete[] pv;
}