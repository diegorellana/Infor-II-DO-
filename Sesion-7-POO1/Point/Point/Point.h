#include <iostream>
using namespace std;
class Point
{
	double x;
	double y;

public:
	void AskData() { cout << "x: "; cin >> x; cout << "y: "; cin >> y; }
	double Distance(Point &p)
	{
		return (sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)));
	}
};

