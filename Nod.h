#pragma once
#include "Complex.h"

class Nod
{
private:
	Complex val;
	Nod *next;
public:
	/////////////CTR/////////////
	Nod();
	Nod(Complex val, Nod *next) : val(val), next(next) {};
	Nod(Nod &);  

	///////////GetsiSet//////////
	void setVal(Complex);
	void setNext(Nod *);
	Complex getVal();
	Nod* getNext();

	void showList();
	void deleteList();
	//////////Operatori//////////
	friend ostream & operator << (ostream &, Nod);
	friend istream & operator >> (istream &, Nod &);
	Nod operator = (Nod);

	/////////////DCTR////////////
	~Nod();
};

