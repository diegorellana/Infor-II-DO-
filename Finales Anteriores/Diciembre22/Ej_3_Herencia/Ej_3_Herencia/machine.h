#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class machine
{
	//dependientes
private:
	double D_ext_r; //diametro exterior rotor
	double w_s0; //Anchura de la apertura de la ranura
	double h_y_s; //altura del yugo del estator

	//independientes
protected:
	double D_ext_s; //diametro exterior estator
	double w_t_s; //espesor del diente del estator
	double h_agap; //altura del entrehierro
	double h_slot; //altura de ranura
	int Q_s; //Numero de ranuras de estator

	//independientes
public:
	double D_int_s; //diametro interior estator

public:
	machine() { ; }
	machine(double d_ext_ss, double Dint_s, double wts, double hagap, double hslot, int qs)
	{
		D_ext_s = d_ext_ss; w_t_s = wts; h_agap = hagap; h_slot = hslot; Q_s = qs; D_int_s = Dint_s;
		f_dependent_vars_machine();
	}
	void f_dependent_vars_machine()
	{
		w_s0 = abs(D_int_s * sin((3.14 / Q_s) - asin(w_t_s / D_int_s)));
		h_y_s = D_ext_s / 2 - D_int_s / 2 - h_slot;
		D_ext_r = D_int_s - 2 * h_agap;
	}
	virtual void prt()
	{
		cout << "D_ext_r: " << D_ext_r << endl;
		cout << "w_s0: " << w_s0 << endl;
		cout << "h_y_s: " << h_y_s << endl;
		cout << "D_ext_s: " << D_ext_s << endl;
		cout << "w_t_s: " << w_t_s << endl;
		cout << "h_agap: " << h_agap << endl;
		cout << "h_slot: " << h_slot << endl;
		cout << "Q_s: " << Q_s << endl;
		cout << "D_int_s: " << D_int_s << endl;
	}
	void Escribir_fichero(ofstream& w)
	{
		w << "D_ext_r: " << D_ext_r << endl;
		w << "w_s0: " << w_s0 << endl;
		w << "h_y_s: " << h_y_s << endl;
		w << "D_ext_s: " << D_ext_s << endl;
		w << "w_t_s: " << w_t_s << endl;
		w << "h_agap: " << h_agap << endl;
		w << "h_slot: " << h_slot << endl;
		w << "Q_s: " << Q_s << endl;
		w << "D_int_s: " << D_int_s << endl;
	}
	void Cargar(ifstream& f)
	{
		f >>  D_ext_r;
		f >> w_s0;
		f >> h_y_s;
		f >> D_ext_s;
		f >> w_t_s;
		f >> h_agap;
		f >> h_slot;
		f >> Q_s;
		f >> D_int_s;
	}
	void setDextr(double x) { D_ext_r = x; }
	double getDextR() { return D_ext_r; }
	double getw_s0() { return w_s0; }
	double gethYs() { return h_y_s; }
};

class SPM : public machine
{
	//independientes
	double h_PM; //altura de los imanes
	double D_ext_PM; //Diametro exterior de los imanes

public:
	SPM() { ; }
	SPM(double d_ext_pm, double Dint_s, double wts, double hagap, double hslot, int qs, double hpm):machine(0,Dint_s,wts,hagap,hslot,qs)
	{
		D_ext_PM = d_ext_pm; h_PM = hpm;
		f_dependent_vars_SPM();
	}
	void f_dependent_vars_SPM()
	{
		f_dependent_vars_machine();
		D_ext_PM = D_int_s - 2 * h_agap;
		setDextr(D_ext_PM - 2 * h_PM);
	}
	void prt()
	{
		cout << "D_ext_r: " << getDextR() << endl;
		cout << "w_s0: " << getw_s0() << endl;
		cout << "h_y_s: " << gethYs() << endl;
		cout << "D_ext_s: " << D_ext_s << endl;
		cout << "w_t_s: " << w_t_s << endl;
		cout << "h_agap: " << h_agap << endl;
		cout << "h_slot: " << h_slot << endl;
		cout << "h_PM: " << h_PM << endl;
		cout << "Q_s: " << Q_s << endl;
		cout << "D_int_s: " << D_int_s << endl;
	}
};

