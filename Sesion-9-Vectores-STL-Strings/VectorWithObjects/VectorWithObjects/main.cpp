#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>

class veh
{
	string brand;
	int hp;

public:
	veh(string b = "BYD", int h=100)
	{
		brand = b;
		hp=h;
	}

	void prt()
	{
		cout << setw(5) << "Brand: " << brand << setw(5) << "HP: " << hp << endl;
	}
};

int main()
{
	vector <veh> lst; //vector de objetos de clase veh. Cada posicion tiene un brand y un hp
	veh v1("Toyota", 150);
	lst.push_back(v1);
	lst.push_back(veh("vw", 115)); //IMPORTANTE: poner EL TIPO DE DATO en el push back
	lst.push_back(veh("mazda", 200));
	lst.push_back(veh()); //default
	lst.push_back(veh("fiat", 150));

	int size = lst.size();

	for (int i = 0; i < size; i++)
	{
		lst[i].prt();
	}

	int pos = 0;
	cout << "Erase? "; cin >> pos;

	lst.erase(lst.begin() + pos); //SIEMPRE ES ESTE FORMATO: lst.erase(lst.begin() + pos)

	cout << "New list\n";
	size = lst.size(); //IMPORTANTE: Actualizar el size

	for (int i = 0; i < size; i++)
	{
		if (i != pos) { lst[i].prt(); }
	}
	return 0;
}