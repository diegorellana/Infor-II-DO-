#include <iostream>
using namespace std;
/*
STRUCTURE:

EMPLOYEE
- MANAGER
- WORKER
	+ OFFICER
	+ TECNICIAN
*/

struct task
{
	char* task_name;
	double score;
};


class Employee
{
	char name[40];
	int salary;
public:

	task list[20];

	Employee(char* n = (char*)"", int s=0)
	{
		strcpy_s(name, 40, n);
		salary = s;
	}

	void print_position()
	{
		cout << " Position not defined" << endl;
	}

	char* GetName() { return name; }

	~Employee()
	{
		cout << "Employee destructor" << endl;
	}

	void prt()
	{
		cout << "Name: " << name;
		cout << "   Salary: " << salary << endl;
	}

	void prt_task()
	{
		for (int i = 0; i <= 20; i++)
		{
			if (isalpha(list[i].task_name[0]))
			{
				cout << "Task number " << i + 1 << endl;
				cout << "Name: " << list[i].task_name << "   Score: " << list[i].score << endl;
			}
		}
	}
};

class Manager : public Employee
{
public:
	Manager(char* n = (char*)"", int s=0) : Employee(n,s)
	{
		//strcpy_s(name, 40, n);
	}

	void print_position()
	{
		cout << " is a manager " << endl;
	}

	~Manager()
	{
		cout << "Manager destructor..." << endl;
	}
};

class Worker : public Employee
{
public: 
	Worker(char* n = (char*)"", int s=0) : Employee(n,s)
	{
		//strcpy_s(name, 40, n);
	}

	void print_position()
	{
		cout << " is a worker" << endl;
	}

	~Worker()
	{
		cout << "Worker destructor" << endl;
	}
};

class Officer : public Worker
{
public: 
	Officer(char* n = (char*)"", int s=0) : Worker(n,s)
	{
		//strcpy_s(name, 40, n);
	}

	void print_position()
	{
		cout << " is an officer" << endl;
	}

	~Officer()
	{
		cout << "Officer destructor" << endl;
	}
};

class Technician : public Worker
{
public:
	Technician(char* n = (char*)"", int s=0) : Worker (n,s)
	{
		//strcpy_s(name, 40, n);
	}

	void print_position()
	{
		cout << " is a technician" << endl;
	}

	~Technician()
	{
		cout << "Technician destructor" << endl;
	}
};


