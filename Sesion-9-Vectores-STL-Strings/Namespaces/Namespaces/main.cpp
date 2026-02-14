#include <iostream>
#include <iomanip>
using namespace std;

namespace food_spc //Declaro namespace y todo lo que esta dentro del namespace 
{
	class product
	{
		double cost;
		char name[20];

	public:
		product(const char* n, double p) : cost(p)
		{
			strcpy_s(name, strlen(name), n);
		}

		void prt()
		{
			cout << setw(20) << name << setw(5) << cost << endl;
		}
	};
}

int main()
{
	food_spc::product p1((char*)"Milk", 1.5);
	p1.prt();

	return 0;
}