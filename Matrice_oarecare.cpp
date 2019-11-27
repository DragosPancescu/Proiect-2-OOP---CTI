#include "pch.h"
#include "Matrice_oarecare.h"


Matrice_oarecare::Matrice_oarecare()
{
	setLin(NULL);
	setCol(NULL);
	setOrig();
}

ostream & operator << (ostream &out, Matrice_oarecare &x)
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

istream & operator >> (istream &in, Matrice_oarecare &x)
{
	// setam dimensiunea matricei.
	int laux, caux;
	cout << "Introduceti dimensiunile matricei: ";
	in >> laux >> caux;
	x.setLin(laux);
	x.setCol(caux);

	// setam valorile din matrice.
	for (int i = 0; i < laux; i++)
	{
		Complex aux;
		in >> aux;

		// setam prima valoarea de pe linie care are rol ca nod de start al listei.
		Nod *newNod = new Nod(aux, nullptr);
		x.origine.push_back(newNod);
		Nod *o = x.origine.back();

		for (int j = 1; j < caux; j++)
		{
			Complex aux;
			in >> aux;
			Nod *newNod2 = new Nod(aux, nullptr);

			o->setNext(newNod2);
			o = o->getNext();
		}
	}
	return in;
}

Matrice_oarecare Matrice_oarecare::operator = (Matrice_oarecare x)
{
	origine.clear();
	setOrig(x.origine);

	return *this;
}

void Matrice_oarecare::Delete(Nod *x)
{
	Nod *o = x->getNext();

	for (int i = 0; i < getCol(); i++)
	{
		delete x;
		x = o;
		o = o->getNext();
	}
}

bool Matrice_oarecare::diag()
{
	if (getLin() != getCol()) {
		throw "Matricea nu este patratica deci nu poate sa fie diagonala!\n";
	}

	for (int i = 0; i < getLin(); i++)
	{
		int index = 0;
		Nod *o = origine[i];

		while (o != nullptr)
		{
			if ((index != i && !o->getVal().isNull()) || (index == i && o->getVal().isNull())) // daca nu suntem pe diagonala si elementul nu este null.
				return false;																   // sau daca suntem pe diagonala si elementul este null.
			o = o->getNext();
			index++;
		}
	}
	return true;
}

void Matrice_oarecare::MENU()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Matrice-Oarecare~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Apasati tasta 1 pentru a citi o matrice oarecare\n";
	cout << "Apasati tasta 2 pentru a afisa o matrice oarecare\n";
	cout << "Apasati tasta 3 pentru a vedea daca matricea oarecare este diagonala\n";

	int com;
	cout << "Introduceti o comanda: ";
	cin >> com;

	while (com > 0 && com < 4)
	{
		switch (com)
		{
		case 1:
			cin >> *this;
			break;

		case 2:
			try {
				cout << *this;
			}
			catch (const char *msg) {
				cerr << msg;
			}
			break;

		case 3:
			try {
				bool aux = diag();
				if (aux)
					cout << "Matricea este diagonala.";
				else
					cout << "Matricea nu este diagonala.";
			}
			catch (const char *msg) {
				cerr << msg;
			}
			break;
		}
		cout << "Introduceti o comanda: ";
		cin >> com;
	}
}

Matrice_oarecare::~Matrice_oarecare()
{
	setLin(NULL);
	setCol(NULL);

	for (auto i : origine)
		Delete(i);

	origine.clear();
}
