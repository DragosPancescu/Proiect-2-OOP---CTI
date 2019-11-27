#include "Matrice.h"
#pragma once

class Matrice_patratica : public Matrice
{
private:
	int dim;
public:
	//////////////CTR///////////////
	Matrice_patratica();
	Matrice_patratica(const Matrice_patratica &x) : Matrice(x), dim(x.dim) {};
	Matrice_patratica(vector<Nod *> origine, int dim) : Matrice(origine), dim(dim) {};

	////////////GetsiSet////////////
	int getDim() { return dim; }
	void setDim(int x) { dim = x; }

	////////////Cerinte/////////////
	Complex det1();
	Complex det2();
	Complex det3();
	bool diag();
	void MENU();

	///////////Operatori////////////
	friend ostream & operator << (ostream &, Matrice_patratica &);
	friend istream & operator >> (istream &, Matrice_patratica &);
	Matrice_patratica operator = (Matrice_patratica);

	/////////////DCTR///////////////
	void Delete(Nod *);
	~Matrice_patratica();
};

