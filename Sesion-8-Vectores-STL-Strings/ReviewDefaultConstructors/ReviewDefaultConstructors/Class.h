#include <iostream>
using namespace std;


class Class
{
	int var1;
	int* var2;

	char* var3;
	char var4[30];

public:
	//Default constructor 2 en 1
	Class(int v1 = 0, int* v2 = (int*)0, char* v3 = (char*)"", char* v4 = (char*)"")
	{
		var1 = v1;
		var2 = v2;
		var3 = v3;
		strcpy_s(var4, v4);
	}

};

