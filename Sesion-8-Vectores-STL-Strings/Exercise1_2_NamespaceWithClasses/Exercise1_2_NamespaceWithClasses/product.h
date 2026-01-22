#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>

namespace foodSpace
{
	class product
	{
		double cost;
		char name[20];

	public:
		product(const char* n = "", double c = 0)
		{
			cost = c;
			strcpy_s(name, 20, n);
		}

		void prt()
		{
			cout << setw(20) << name << setw(5) << cost << endl;
		}
	};
}


namespace elecSpace
{
	class product
	{
		double cost;
		char name[20];
		int warranty;

	public:
		product(const char* n = "", double c = 0, int w=0)
		{
			cost = c;
			strcpy_s(name, 20, n);

		}

		void prt()
		{
			cout << setw(20) << name << " " << setw(5) << cost << endl;
		}
	};
}
