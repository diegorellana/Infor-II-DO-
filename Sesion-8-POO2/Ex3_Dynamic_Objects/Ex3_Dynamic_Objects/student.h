#include <iostream>
using namespace std;

class Student
{
	char name[20];
	double average;

public:
	Student(char* n = (char*)"joe", double a = 0) //2 en 1
	{
		strcpy_s(name, strlen(n) + 1, n);
		average = a;
	}

	void prt()
	{
		cout << name << ", " << average << endl;
	}

	void get()
	{
		cout << "Name? Average? "; cin >> name >> average;
	}
};
