#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class cuenta
{
private:
	static double interes_base;
	char titular[20];
protected:
	double* saldo;
	int cont;
	// añada el código necesario

public:
	cuenta(char* t = 0, double s_ini = 0)
	{
		strcpy_s(titular, strlen(t) + 1, t);
		saldo = new double[100];
		cont = 0;

		saldo[cont] = s_ini;


	}

	bool Gasto(double x)
	{

		if (x > 0)
		{
			if (saldo[cont] > x)
			{
				cont++;
				saldo[cont] = saldo[cont - 1] - x;
				return 1;
			}

			else if (saldo[cont] < 0)
			{
				return 0;
			}
		}

		else
		{
			return 0;
		}
	}

	void prt()
	{
		cout << "Titular: " << titular << "   " << "Saldo: " << saldo[cont] << endl;
	}

	void historial(int num)
	{
		if (num > cont)
		{
			num = cont;
		}

		cout << "Titular: " << titular << endl;
		for (int i = abs(num-cont); i <= cont; i++)
		{
			cout << i << ":" << "     " << saldo[i] << endl;
		}
		cout << endl << endl;
	}

	bool transferencia(cuenta& c, double valor)
	{
		if (saldo[cont] > valor)
		{
			//actualizo
			cont++;
			saldo[cont] = saldo[cont - 1] - valor;

			c.cont++;
			c.saldo[c.cont] = c.saldo[c.cont - 1] + valor;

			return 1;
		}

		else
		{
			return 0;
		}
	}

	double get_int_base() { return interes_base; }

	double* simular(int time)
	{
		int pos = 0;
		double* sim = new double[time];

		double cantidad = saldo[cont];

		sim[pos] = cantidad;
		pos++;

		for (int i = 1; i < time; i++)
		{
			sim[i] = sim[i - 1]* (1+get_intereses());
		}

		return sim;
	}

	void grabar(ofstream& w)
	{
		w << "Num. movimientos: " << cont << endl;
		w << "Movimientos: " << endl;

		for (int i = 0; i < cont; i++)
		{
			w << saldo[i] << endl;
		}
	}

private:
	virtual double get_intereses() { return interes_base; }
};

class renta_mixta : public cuenta// derivada de cuenta
{
	double interes_fijo;
	double prop_variable;
	// añada el código necesario

public:
	renta_mixta(char* t = 0, double s_ini = 0, double i_f = 0, double p_v = 0) : cuenta(t, s_ini)
	{
		interes_fijo = i_f;
		prop_variable = p_v;
	}

	bool Gasto(double x) { return 0; }
	double get_int_fijo() { return interes_fijo; }

private:
	double get_intereses() { return (1 - prop_variable) * (interes_fijo + get_int_base()) + prop_variable * (rand() % (0 + 2) - 0.5); }

};

class renta_fija : public renta_mixta
{
public:
	renta_fija(char* t = 0, double s_ini = 0, double i_f = 0) : renta_mixta(t, s_ini, i_f, 0) {}
	bool Gasto(double x) { return 0; }

private:
	double get_intereses() { return (1 - 0) * (get_int_fijo() + get_int_base()) + 0 * (rand() % (0 + 2) - 0.5); }


};

