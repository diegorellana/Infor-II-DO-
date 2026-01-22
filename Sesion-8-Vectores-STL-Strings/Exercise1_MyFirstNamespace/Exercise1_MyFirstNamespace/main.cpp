#include <iostream>
#include <vector>
using namespace std;

namespace first_space
{
	void func()
	{
		cout << "Inside first space. " << endl;
	}
}

using namespace first_space;
int main()
{
	func();
	return 0;
}