#include <iostream>
#include <vector>
using namespace std;
class Vehiculo
{
	string mat; // matricula
public:
	Vehiculo(string m = "")
	{
		mat = m;
	}

	string getMat() { return mat; }
	void prt()
	{
		cout << "Matricula: " << mat << endl;
	}
};

