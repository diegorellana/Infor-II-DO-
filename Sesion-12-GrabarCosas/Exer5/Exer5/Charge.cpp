#include <fstream>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
void main()
{
	char name[80];
	double R, C, E, dt, Vc = 0, t = 0;
	cout << "Enter R(KOhm):"; cin >> R;
	cout << "Enter C(uF):"; cin >> C;
	cout << "Enter E(v):"; cin >> E;
	cout << "Enter dt(ms):"; cin >> dt;
	R *= 1e3; C *= 1e-6; dt *= 1e-3;
	cout << "Name of the file (without extension):";
	cin >> name;
	strcat_s(name, ".csv"); 
	fstream fout(name, ios::out);
	fout << "Values, R:" << R << "C:" << C << "E:" << E << endl;
	fout << "Time,Vc" << endl;
	while (Vc < E * 0.9) { //10% de E
		Vc = E * (1 - exp(-t / (R * C)));
		fout << t << ", " << Vc << endl;
		t += dt;
	}
	fout.close();
	cout << "File " << name << " saved well. Bye " << endl;
}