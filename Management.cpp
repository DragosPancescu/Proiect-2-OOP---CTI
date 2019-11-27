#include "pch.h"
#include "Management.h"

Management::Management()
{
	n = NULL;
	MAN.reserve(NULL);
}

ostream & operator << (ostream &out, Management A)
{
	int index = 1;
	for (auto i : A.MAN)
	{
		out << "Matricea cu numarul " << index << " este: \n";
		out << i;
		index++;
	}
	return out;
}

istream & operator >> (istream &in, Management &A)
{
	int auxn;
	cout << "Introduceti numarul de matrici: ";
	in >> auxn;
	A.setN(auxn);

	cout << "Matrice oarecare - 1 / Matrice patratica - 2\n";
	for (int i = 0; i < auxn; i++)
	{
		int com;
		cout << "Tipul de matrice: ";
		in >> com;

		switch (com)
		{
		case 1: {
			Matrice_oarecare Moa;
			in >> Moa;
			A.MAN.push_back(Moa);
			break;
		}
		case 2: {
			Matrice_patratica Mpa;
			in >> Mpa;
			A.MAN.push_back(Mpa);
			break;
		}
		}
	}
	return in;
}

Management Management::operator = (Management A)
{
	setN(A.getN());
	MAN.clear();
	for (auto i : A.getMan())
		MAN.push_back(i);

	return *this;
}

Management::~Management()
{
	setN(NULL);

	for (auto i : MAN)
	{
		for (auto j : i.getOrig())
			j->deleteList();
		i.getOrig().clear();
	}
	MAN.clear();
}