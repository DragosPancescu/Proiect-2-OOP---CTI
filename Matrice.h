#pragma once
#include <vector>
#include "Nod.h"

class Matrice
{
protected:
	vector<Nod *> origine;
public:
	/////////////CTR/////////////
	Matrice();
	Matrice(vector<Nod*> origine) : origine(origine) {};
	Matrice(const Matrice &x) : origine(x.origine) {};

	///////////GetsiSet//////////
	vector<Nod *> getOrig() { return origine; }
	void setOrig(vector<Nod *> x) { origine = x; }
	void setOrig() { origine.assign(NULL, NULL); }

	////////////Cerinte//////////
	virtual void MENU() {};

	//////////Operatori//////////
	friend ostream & operator << (ostream &, Matrice &);
	//friend istream & operator >> (istream &, Matrice &);
	//Matrice operator = (Matrice);

	/////////////DCTR////////////
	virtual void Delete(Nod *) {};
	~Matrice();
};

