#include "Student.h"

int main()
{
	Student s1;
	Student s2 ((char*)"Ana", 6.5);
	Student s3;

	s3.get();

	cout << "Student's list: " << endl;
	s1.prt();
	s2.prt();
	s3.prt();
}