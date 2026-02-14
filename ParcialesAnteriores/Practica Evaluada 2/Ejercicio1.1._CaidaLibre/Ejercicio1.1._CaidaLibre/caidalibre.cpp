#include <iostream>
using namespace std;

double Calcula(double alt, double dt);

int main()
{
	double h, dt, t_exacto;
	cout << "Altura y dt(ms): "; cin >> h >> dt;
	t_exacto = Calcula(h, dt);

	cout << "-------- Resultado --------" << endl;
	cout << "Ha llegado al suelo en " << t_exacto << " (ms)" << endl;
}

double Calcula(double alt, double dt)
{
	cout << "------ Simulacion ------" << endl;
	double altura_nueva = alt;
	double g = 9.81, dt_s;
	double last_dt, dt_in{ dt };
	double y = alt;
	do
	{
		last_dt = dt;
		dt_s = dt / 1000;
		y = alt - g*dt_s*dt_s/ 2.0; //SE RECALCULA LA ALTURA EN CADA PASO, NO SE ACUMUA!!!
		cout << "T: " << dt << "(ms)" << "				";
		cout << "Altura: " << y << endl;
		dt = dt + dt_in;
	} while (y >= 0);

	return last_dt;
}