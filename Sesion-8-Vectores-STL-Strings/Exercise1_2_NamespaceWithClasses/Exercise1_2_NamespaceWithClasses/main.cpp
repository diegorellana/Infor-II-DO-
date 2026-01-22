#include "product.h"

int main()
{
	foodSpace::product p1("Milk", 1.5);
	elecSpace::product p2("LG 50", 750.99, 3);
	p1.prt();
	p2.prt();
	return 0;
}