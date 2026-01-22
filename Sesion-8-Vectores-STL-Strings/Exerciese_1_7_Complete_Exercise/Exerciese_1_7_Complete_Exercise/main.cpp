#include "date.h"

int main()
{
	int opc; vector<vehicle> cars;
	while (true)
	{
		cout << "1. Add Car\n";
		cout << "2. Print Cars\n";
		cout << "3. Erase Car\n";
		cout << "4. Find Car Between Dates\n";
		cout << "5. Exit\n";
		cout << "Option: "; cin >> opc;

		if (opc == 5) { break; }
		if (opc == 1)
		{
			string name; int dd, mm, yy, hp;
			cout << "Brand? "; cin >> name;
			cout << "Year? "; cin >> yy;
			cout << "Month? "; cin >> mm;
			cout << "Day? "; cin >> dd;
			cout << "HP? "; cin >> hp;

			vehicle car(name, dd, mm, yy, hp);
			cars.push_back(car);
		}

		if (opc == 2)
		{
			for (int i = 0; i < cars.size(); i++)
			{
				cout << "Car Number " << i + 1 << ":\n";
				cars[i].prt();
			}
		}

		if (opc == 3)
		{
			int erase;
			cout << "************* ALL CARS *************" << endl;
			for (int i = 0; i < cars.size(); i++)
			{
				cout << "Car Number " << i + 1 << ":\n";
				cars[i].prt();
			}
			cout << "Erase? "; cin >> erase;

			cars.erase(cars.begin() + erase - 1);

			cout << "Car erased." << endl;
		}

		if (opc == 4)
		{
			int d1, m1, y1, d2, m2, y2, yflag = 0, mflag = 0, dflag = 0;
			cout << "DATE 1\n";
			cout << "Year? "; cin >> y1;
			cout << "Month? "; cin >> m1;
			cout << "Day? "; cin >> d1;
			cout << "DATE 2\n";
			cout << "Year? "; cin >> y2;
			cout << "Month? "; cin >> m2;
			cout << "Day? "; cin >> d2;

			cout << "Cars Found: \n";
			for (int i = 0; i < cars.size(); i++)
			{
				date reg = cars[i].getReg();
				yflag = 0; mflag = 0; dflag = 0;
				for (int j = y1; j <= y2; j++)
				{
					if (reg.getyear() == j) { cars[i].prt(); yflag = 1; }
				}

				if (yflag == 0)
				{
					for (int k = m1; k <= m2; k++)
					{
						if (reg.getmonth() == k) { cars[i].prt(); mflag = 1; }
					}

				}

				if (mflag == 0 && yflag ==0)
				{
					for (int l = d1; l <= d2; l++)
					{
						if (reg.getday() == l) { cars[i].prt(); dflag = 1; }
					}
				}

			}
		}
	}

			
	return 0;
}