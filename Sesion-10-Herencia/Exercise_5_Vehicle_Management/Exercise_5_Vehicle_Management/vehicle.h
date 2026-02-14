#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
Vehicle (year, plate as char 20)
- Car (has hp)
- Lorry (has lmax)
*/

class Employee
{
protected:
	char name[40];
public:
	Employee(char* n = (char*)"joe")
	{
		strcpy_s(name, 40, n);
	}

	char* getName() { return name; }
};

class vehicle
{
	int year;
	char plate[20];
	Employee e;

public:
	vehicle(int y = 2000, char* p = (char*)"AAA1234", char* n = (char*) "joe") : e(n)
	{
		year = y;
		strcpy_s(plate, 20, p);
	}

	void display()
	{
		cout << "Year: " << year << "   Plate: " << plate << "   Name: " << e.getName() << endl;
	}

	char* getPlate() { return plate; }
	int getYear() { return year; }
	char* getName() { return e.getName(); }
};

class Car : public vehicle
{
	int hp;

public:
	Car(int y = 2000, char* p = (char*)"AAA1234", int h=65, char* n = (char*)"joe") : vehicle(y,p,n)
	{
		hp = h;
	}

	void display()
	{
		cout << "Year: " << getYear() << "   Plate: " << getPlate() << "   Name: " << getName() << endl;
	}
};

class Lorry : public vehicle
{
	int lmax;

public:
	Lorry(int y = 2000 , char* p = (char*)"AAA1234", int lm = 10, char* n = (char*)"joe") : vehicle(y,p,n)
	{
		lmax = lm;
	}

	void display()
	{
		cout << "Year: " << getYear() << "   Plate: " << getPlate() << "  LMax: " << lmax << "   Name: " << getName() << endl;
	}
};

struct fleet
{
	Car car_list[10];
	Lorry lorry_list[10];

};


