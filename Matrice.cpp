#include "pch.h"
#include "Matrice.h"


Matrice::Matrice()
{
	origine.reserve(NULL);
}

ostream & operator << (ostream &out, Matrice &x)
{
	if (x.origine.empty())
		throw "Matricea este nula!\n";

	for (auto i : x.origine)
	{
		i->showList();
		out << '\n';
	}
	return out;
}

Matrice::~Matrice()
{
	origine.clear();
}
