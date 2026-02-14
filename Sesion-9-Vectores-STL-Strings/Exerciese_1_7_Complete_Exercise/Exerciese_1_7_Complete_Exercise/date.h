#include <iostream>
using namespace std;
#include <vector>
#include <string.h>

class date
{
	int d, m, y;
public:
	date(int dd = 1, int mm = 1, int yy = 2025)
	{
		d = dd; m = mm; y = yy;
	}

	~date()
	{

	}

	int getday() { return d; }
	int getmonth() { return m; }
	int getyear() { return y; }
};

class vehicle
{
	string brand;
	date reg;
	int hp;

public:
	vehicle(string b = "bmw", int dd = 1, int mm = 1, int yy = 2025, int h = 30)
	{
		reg = date(dd, mm, yy);
		brand = b;
		hp = h;
	}

	void prt()
	{
		cout << "Brand: " << brand << endl;
		cout << "Registration date: " << reg.getday() << "/" << reg.getmonth() << "/" << reg.getyear() << endl;
		cout << "HP: " << hp << endl;
	}

	date getReg()
	{
		return reg;
	}
};

