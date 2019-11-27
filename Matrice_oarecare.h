#include "Matrice.h"
#pragma once

class Matrice_oarecare : public Matrice
{
private:
	int lin, col;
public:
	//////////////CTR///////////////
	Matrice_oarecare();
	Matrice_oarecare(const Matrice_oarecare &x) : Matrice(x), lin(x.lin), col(x.col) {};
	Matrice_oarecare(vector<Nod *> origine, int lin, int col) : Matrice(origine), lin(lin), col(col) {};

	////////////GetsiSet////////////
	int getLin() { return lin; }
	int getCol() { return col; }
	void setLin(int x) { lin = x; }
	void setCol(int x) { col = x; }

	////////////Cerinte/////////////
	bool diag();
	void MENU();  // aici folosesc exceptii.

	///////////Operatori////////////
	friend ostream & operator << (ostream &, Matrice_oarecare &);
	friend istream & operator >> (istream &, Matrice_oarecare &);
	Matrice_oarecare operator = (Matrice_oarecare);

	/////////////DCTR///////////////
	void Delete(Nod *);
	~Matrice_oarecare();
};

