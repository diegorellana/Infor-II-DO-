#include <iostream>
#include <string>
#include <vector>
using namespace std;

void vector_example_1();
void vector_example_2();
void vector_example_3();
void prt(vector<string>& vec);

int main()
{
	int opc;
	while (true)
	{
		cout << "1. Example 1 (short)\n";
		cout << "2. Example 2 (long)\n";
		cout << "3. Example 3 (strings)\n";
		cout << "4. Exit \n";
		cout << "Option: "; cin >> opc;

		if (opc == 4) { break; }

		if (opc == 1) { vector_example_1(); }

		if (opc == 2) { vector_example_2(); }

		if (opc == 3) { vector_example_3(); }
	}
}

void vector_example_1()
{
	int num = 0, max = 0, val;
	vector<int> v1; //vector<tipo_de_dato> v;
	while (true)
	{
		cout << "Give value (-1 = exit): "; cin >> val;

		if (val == -1) { break; }

		else
		{
			v1.push_back(val); //.push_back(tipo_de_dato) para colocar el dato en la posicion mas grande
		}
	}

	cout << "Ahora veremos el maximo \n";
	num = v1.size(); //.size() gives the size of the vector

	for (int i = 0; i < num; i++)
	{
		if (v1[i] > max)
		{
			max = v1[i];
		}
	}

	cout << "El maximo numero es: " << max;
}

void vector_example_2() //create, add, display, modify, size and capacity
{
	vector<int> v; //create vector;

	//Add stuff to vector;
	v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40); v.push_back(50);

	//Modify stuff
	int size = v.size();
	v[size-1] = 60;

	//Display
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << " ";
	}

	//Size
	cout << "Size: " << size << endl;

	//Capacity
	cout << "Capacity: " << v.capacity() << endl;

	//Remove last element
	v.pop_back();

	//Clear all elements
	v.clear();

	//Size after clearing
	cout << "Size after clearing: " << v.size() << endl;
}

void vector_example_3()
{
	string new_car;
	vector<string> cars = { "volvo", "bmw", "ford", "mazda" };
	prt(cars);
	cout << "Add new car: "; cin >> new_car;
	cars.push_back(new_car);

	cout << "Now the new list: " << endl;
	prt(cars);

	int pos;
	cout << "Select a position to erase: "; cin >> pos;
	cars[pos].erase();

	cout << "Final list: " << endl;
	prt(cars);

	cout << "Clearing cars: "; 
	cars.clear();

	cout << "\nEnd.\n";
}

void prt(vector<string>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl; //cada elemento es el string COMPLETO
	}
}