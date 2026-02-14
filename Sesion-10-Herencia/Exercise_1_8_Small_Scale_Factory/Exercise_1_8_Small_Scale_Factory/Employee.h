#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*
STRCUTURE

Employee
- Engineer
- Worker

Product
- Device
- Component
*/

//Forward declaration
class Employee;
class Product;

//EMPLOYEE HIERARCHY
class Employee
{
protected:
	int ID;
	string name;
	vector <Product*> assignedProducts; //vector de punteros a objetos de Product
public:
	Employee(int id, const string& n) : ID(id), name(n) {}

	//Assign product
	void assignProduct(Product* p)
	{
		assignedProducts.push_back(p);
	}

	//GetSizeOfassignedProducts
	int getsizeProduct() { return assignedProducts.size(); }

	string getName() { return name; }
	int getId() { return ID; }
	
};

class Engineer : public Employee {
	string specialty;
public:
	Engineer(int id, const string& n, const string& esp)
		: Employee(id, n), specialty(esp) {
	}
};

class Worker : public Employee {
	int shift;
public:
	Worker(int id, const string& n, int s)
		: Employee(id, n), shift(s) {
	}
};

//PRODUCT HIERARCHY
class Product {
protected:
	int productId;
	string name;
	Employee** assignedEmployees; //puntero a punteros 
	int employeeCount;
	int employeeCapacity;
public:
	Product(int id, const string& n) : productId(id), name(n), employeeCount(0), employeeCapacity(5) {
		assignedEmployees = new Employee * [employeeCapacity];
	}
	~Product() {
		delete[] assignedEmployees;
	}

	//Assign employee
	void assignEmployee(Employee* e)
	{
		assignedEmployees[employeeCount] = e;
		employeeCount++;
	}

	//Show employee
	void showEmployees()
	{
		for (int i = 0; i < employeeCount; i++)
		{
			cout << assignedEmployees[i]->getName() << "  ";
		}
	}

	//get count
	int getCount()
	{
		return employeeCount;
	}

	//get ID
	int getID() { return productId; }

	//get name
	string getName() { return name; }

};


class Device : public Product {
	double voltage;
public:
	Device(int id, const string& n, double v)
		: Product(id, n), voltage(v) {
	}
};
class Component : public Product {
	string materialType;
public:
	Component(int id, const string& n, const string& type) : Product(id, n), materialType(type) {}
};

