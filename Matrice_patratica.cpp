#include "pch.h"
#include "Matrice_patratica.h"


Matrice_patratica::Matrice_patratica()
{
	setDim(NULL);
	setOrig();
}

ostream & operator << (ostream &out, Matrice_patratica &x)
{
	if (x.origine.empty())
		throw "Matricea este vida!\n";

	for (auto i : x.origine)
	{
		i->showList();
		out << '\n';
	}

	switch (x.origine.size())
	{
	case 1:
		out << "Determinantul matricei este: " << x.det1() << '\n';
		break;
	case 2:
		out << "Determinantul matricei este: " << x.det2() << '\n';
		break;
	case 3:
		out << "Determinantul matricei este: " << x.det3() << '\n';
		break;
	default:
		break;
	}
	return out;
}

istream & operator >> (istream &in, Matrice_patratica &x)
{
	// setam dimensiunea matricei.
	int daux;
	cout << "Introduceti dimensiunea matricei: ";
	in >> daux;

	x.setDim(daux);

	// setam valorile din matrice.
	for (int i = 0; i < daux; i++)
	{
		Complex aux;
		in >> aux;

		// setam prima valoarea de pe linie care are rol ca nod de start al listei.
		Nod *newNod = new Nod(aux, nullptr); 
		x.origine.push_back(newNod);
		Nod *o = x.origine.back();

		for (int j = 1; j < daux; j++)
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

Matrice_patratica Matrice_patratica::operator = (Matrice_patratica x)
{
	origine.clear();
	setOrig(x.origine);

	return *this;
}

Complex Matrice_patratica::det1()
{
	return origine[0]->getVal();
}

Complex Matrice_patratica::det2()
{
	Complex aux1, aux2;  //aux1 - elementele de pe diagonala principala.
						 //aux2 - elementele de pe diagonala secundara.
	aux1 = origine[0]->getVal();
	aux2 = origine[0]->getNext()->getVal();

	aux2 = aux2 * origine[1]->getVal();
	aux1 = aux1 * origine[1]->getNext()->getVal();

	return aux2 - aux1;
}

Complex Matrice_patratica::det3()
{
	Complex a11, a12, a13, a21, a22, a23, a31, a32, a33;
	a11 = origine[0]->getVal();
	a12 = origine[0]->getNext()->getVal();
	a13 = origine[0]->getNext()->getNext()->getVal();

	a21 = origine[1]->getVal();
	a22 = origine[1]->getNext()->getVal();
	a23 = origine[1]->getNext()->getNext()->getVal();

	a31 = origine[2]->getVal();
	a32 = origine[2]->getNext()->getVal();
	a33 = origine[2]->getNext()->getNext()->getVal();

	return (a11*a22*a33 + a13 * a21*a32 + a12 * a23*a31) - (a13*a22*a31 - a12 * a21*a33 - a11 * a23*a32);
}

bool Matrice_patratica::diag()
{
	for (int i = 0; i < getDim(); i++)
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

void Matrice_patratica::MENU()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Matrice-Patratica~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Apasati tasta 1 pentru a citi o matrice patratica\n";
	cout << "Apasati tasta 2 pentru a afisa o matrice patratica\n";
	cout << "Apasati tasta 3 pentru a vedea daca matricea patratica este diagonala\n";

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
			bool aux = diag();
			if (aux)
				cout << "Matricea este diagonala.\n";
			else
				cout << "Matricea nu este diagonala.\n";
			break;
		}
		cout << "Introduceti o comanda: ";
		cin >> com;
	}
}

void Matrice_patratica::Delete(Nod *x)
{
	Nod *o = x->getNext();

	for (int i = 0; i < getDim(); i++)
	{
		delete x;
		x = o;
		o = o->getNext();
	}
}

Matrice_patratica::~Matrice_patratica()
{
	setDim(NULL);

	for (auto i : origine)
		Delete(i);
	origine.clear();
}
