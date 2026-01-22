#include <iostream>
using namespace std;
#include <fstream>

struct task_struct
{
	char name[20];
	double level;	
};

void write_to_file(task_struct& ts, ofstream& write_object)
{
	write_object << ts.name << endl << ts.level << endl;
}

int main()
{
	task_struct ts[10];
	strcpy_s(ts[0].name, "Welding");
	ts[0].level = 8.3;
	strcpy_s(ts[1].name, "Fitting");
	ts[1].level = 4.3;
	strcpy_s(ts[2].name, "Screwing");
	ts[2].level = 10.0;
	strcpy_s(ts[3].name, "Painting");
	ts[3].level = 9.2;
	strcpy_s(ts[4].name, "Polishing");
	ts[4].level = 5.7;
	int count = 5;
	ofstream write_object("MyFile.txt");

	for (int i = 0; i < count; i++)
	{
		write_to_file(ts[i], write_object);
	}

	write_object.close();

}