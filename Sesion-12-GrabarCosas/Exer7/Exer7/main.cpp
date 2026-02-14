#include <iostream>
#include <fstream>
using namespace std;

struct task_struct
{
	char name[20];
	double level;
};

void read_task_from_file(ifstream& read_object, task_struct& tt)
{
	read_object >> tt.name;
	read_object >> tt.level;

	cout << "Name: " << tt.name << endl;
	cout << "Level: " << tt.level << endl;
}

int main()
{
	task_struct tt;
	ifstream read_object("MyFile.txt");
	int cont;
	//read_object >> cont;
	//read_object >> tt.name >> tt.level;

	while (!read_object.eof())
	{
		read_task_from_file(read_object, tt);
	}
}