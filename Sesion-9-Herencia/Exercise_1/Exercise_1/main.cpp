#include "Employee.h"

int main()
{
	Employee Rafa((char*)"Rafa", 850);
	Manager Mario((char*)"Mario", 2500); 
	Worker Anton((char*)"Anton", 1250); 
	Officer Luis((char*)"Luis", 1500); 
	Technician Pablo((char*)"Pablo", 1750);
	// The type of object determines the function that is called 
	cout << "With object names:\n" << endl;
	cout << Rafa.GetName();
	Rafa.print_position();
	cout << Mario.GetName(); 
	Mario.print_position();
	cout << Anton.GetName();
	Anton.print_position(); 
	cout << Luis.GetName();
	Luis.print_position(); 
	cout << Pablo.GetName(); 
	Pablo.print_position();

	cout << "\n\n Now names and positions: \n";
	Rafa.prt();
	Mario.prt();
	Anton.prt();
	Luis.prt();
	Pablo.prt();

	cout << "Tasks:\n";
	Rafa.list[0].task_name = (char*)"Reparaciones";
	Rafa.list[0].score = 10;
	Rafa.prt_task();
	return 0;
}