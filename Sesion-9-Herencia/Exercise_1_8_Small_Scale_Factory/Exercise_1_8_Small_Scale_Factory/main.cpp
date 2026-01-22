#include "Employee.h"

//GLOBAL FUNCTIONS
void assignEmployeeToProduct(Employee* e, Product* p)
{
	e->assignProduct(p);
	p->assignEmployee(e);
}

void showProductionNetwork(vector <Product*> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "Product: " << vec[i]->getName() << endl;
		cout << "Assigned Employees: "; vec[i]->showEmployees(); cout << endl << endl;
	}
}

void showWorkload(Employee** employees, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[Employee]" << " " << employees[i]->getName() << "(ID: " << employees[i]->getId() << ", Products: " << employees[i]->getsizeProduct() << ")\n";
	}
}

void filterEmployeesByProductCount(Employee** assignedE, int count, int minCount, int& resultCount)
{
	Employee* e;
	cout << "Employees with at least " << minCount << " products\n";
	for (int i = 0; i < count; i++)
	{
		Employee* emp = assignedE[i]; //saco el empleado
		if (emp->getsizeProduct() >= minCount)
		{
			cout << "[Employee] " << emp->getName() << " (ID: " << emp->getId() << ", Products: " << emp->getsizeProduct() << endl;
			resultCount++;
		}
	}
}


int main()
{
	int maxEmployees = 10;
	int numEmployees = 0;
	Employee** employees = new Employee * [maxEmployees]; // Dynamic array of pointers to Employee
	vector<Product*> products; // Vector of pointers to Product
	// === Initial Employees ===
	employees[numEmployees++] = new Engineer(1001, "Alice", "Electronics");
	employees[numEmployees++] = new Worker(2001, "Bob", 1);
	employees[numEmployees++] = new Worker(2002, "Clara", 2);
	// === Initial Products ===
	Product* p1 = new Device(1, "Tablet Pro", 5.0);
	Product* p2 = new Component(2, "Motherboard", "PCB");
	products.push_back(p1);
	products.push_back(p2);
	assignEmployeeToProduct(employees[0], products[0]);

	int opc;
	while (true)
	{
		cout << "1. Create Engineer " << endl;
		cout << "2. Create Worker " << endl;
		cout << "3. Create Product " << endl;
		cout << "4. Assign Employee to Product " << endl;
		cout << "5. Show Production Network\n";
		cout << "6. Show employee workload\n";
		cout << "7. Filter Employees by Product Count\n";
		cout << "8. Exit\n";
		cout << "Option: "; cin >> opc;

		if (opc == 8) { break; }
		if (opc == 1)
		{
			int id; string n, esp;
			cout << "Name: "; cin >> n;
			cout << "Speciality: "; cin >> esp;
			cout << "ID: "; cin >> id;

			employees[numEmployees++] = new Engineer(id, n, esp);
		}

		if (opc == 2)
		{
			int id; string n, s;
			cout << "Name: "; cin >> n;
			cout << "Shift: "; cin >> s;
			cout << "ID: "; cin >> id;

			employees[numEmployees++] = new Engineer(id, n, s);
		}

		if (opc == 3)
		{
			int id; string n, type;
			cout << "Name: "; cin >> n;
			cout << "ID: "; cin >> id;
			cout << "Type (Device/Component): "; cin >> type;

			if (type == "Device")
			{
				int volt;
				cout << "Voltage: "; cin >> volt;
				Product* p = new Device(id, n, volt);
				products.push_back(p);
			}

			if (type == "Component")
			{
				string matType;
				cout << "Material Type: "; cin >> matType;
				Product* p = new Component(id, n, matType);
				products.push_back(p);
			}

		}

		if (opc == 4)
		{
			int IDEmp, IDProd;
			cout << "Employee ID: "; cin >> IDEmp;
			cout << "Product ID: "; cin >> IDProd;

			for (int i = 0; i < numEmployees; i++)
			{
				if (employees[i]->getId() == IDEmp)
				{
					for (int j = 0; j < products.size(); j++)
					{
						if (products[j]->getID() == IDProd)
						{
							employees[i]->assignProduct(products[j]);
						}
					}
				}
			}
			
		}

		if (opc == 5)
		{
			showProductionNetwork(products);
		}

		if (opc == 6)
		{
			showWorkload(employees, numEmployees);
		}

		if (opc == 7)
		{
			int minCount; int resultCount = 0;
			cout << "Choose a minimum number of products: "; cin >> minCount;
			filterEmployeesByProductCount(employees, numEmployees, minCount, resultCount);
		}
	}
	return 0;
}