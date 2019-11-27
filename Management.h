#pragma once
#include "Matrice.h"
#include "Matrice_oarecare.h"
#include "Matrice_patratica.h"

class Management
{
private:
	vector<Matrice> MAN;
	int n;
public:

	//////////////////CTR//////////////////
	Management();
	Management(vector<Matrice> MAN, int n) : MAN(MAN), n(n) {};
	Management(const Management &x) : MAN(x.MAN), n(x.n) {};

	void setN(int x) { n = x; }
	void setMan(vector<Matrice> x) { MAN = x; }
	int getN() { return n; }
	vector<Matrice> getMan() { return MAN; }

	///////////////Operatori///////////////
	friend ostream & operator << (ostream &, Management );
	friend istream & operator >> (istream &, Management &);
	Management operator = (Management);

	/////////////////DCTR/////////////////
	~Management();

};

