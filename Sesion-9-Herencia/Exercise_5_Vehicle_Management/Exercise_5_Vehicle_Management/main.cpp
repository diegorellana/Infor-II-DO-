#include "vehicle.h"

fleet fleet_list[10];
int main()
{
	Car golf(2011, (char*)"BDA2456", 150); 
	Car astra(2010, (char*)"ABZ2367", 110);
	Lorry Pegaso(2009, (char*)"AZT2345", 15);
	Lorry Iveco(2012, (char*)"CZT8953", 17);
	golf.display();
	astra.display();
	Pegaso.display();
	Iveco.display();
	cout << "End of vehicle list.." << endl;

	//Assigning values from main to fleet
	fleet test1;
	test1.car_list[0] = golf;
	test1.car_list[1] = astra;
	test1.lorry_list[0] = Pegaso;
	test1.lorry_list[1] = Iveco;

	//Assigning values to fleet list
	//1st list = 2 cars and 2 lorrys
	fleet_list[0].car_list[0] = golf;
	fleet_list[0].car_list[1] = astra;
	fleet_list[0].lorry_list[0] = Pegaso;
	fleet_list[0].lorry_list[0] = Iveco;

	//Assigning values to fleet list dynamically
	//I suppose we know the amount of lists (1)
	fleet* fleet_list_2 = new fleet[1];
	fleet_list_2[0].car_list[0] = golf;
	fleet_list_2[0].car_list[1] = astra;
	fleet_list_2[0].lorry_list[0] = Pegaso;
	fleet_list_2[0].lorry_list[0] = Iveco;
	delete[] fleet_list_2;
	return 0;
}