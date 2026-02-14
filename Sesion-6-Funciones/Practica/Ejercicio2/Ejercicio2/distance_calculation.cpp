#include <iostream>
#include <cmath>
using namespace std;

double* distance(double* x, double* y, int num);

int main()
{
	int num{ 3 };
	double min;
	int i_win;

	double *x = new double[num];
	double *y = new double[num];

	for (int i = 0; i < num; i++)
	{
		cout << "Enter x [" << i << "]: "; cin >> x[i];
		cout << "Enter y [" << i << "]: "; cin >> y[i];
	}

	double *distances = distance(x, y, num);

	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			min = distances[i];
			i_win = i;
		}

		if (distances[i] < min)
		{
			min = distances[i];
			i_win = i;
		}

		cout << "distances [" << i << "]: " << distances[i] << endl;
	}
	
	cout << "The shortest distance is in [" << i_win << "]: " << min << endl;
	cout << "The pairs are: " << endl;
	cout << "x [" << i_win << "]: " << x[i_win] << "; y [" << i_win << "]: " << y[i_win] << endl;
	cout << "x [" << i_win+1 << "]: " << x[i_win+1] << "; y [" << i_win+1 << "]: " << y[i_win+1] << endl;

	delete[] x;
	delete[] y;
	delete[] distances;


}

double* distance(double* x, double* y, int num)
{
	double *distances = new double[num-1];

	for (int i = 0; i < num-1; i++)
	{
		distances[i] = sqrt(pow(x[i] - x[i + 1], 2) + pow(y[i] - y[i + 1], 2));
	}

	return distances;
}