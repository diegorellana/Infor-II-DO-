#include "Point.h"

int main()
{
	Point p1, p2;		//Two point objects
	
	cout << "P1: " << endl;
	p1.AskData();

	cout << "P2: " << endl;
	p2.AskData();

	double dist = p1.Distance(p2);

	cout << "The distance between P1 and P2 is: " << dist << endl;
	cout << "End." << endl;
}