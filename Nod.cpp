#include "pch.h"
#include "Nod.h"


Nod::Nod()
{
	val.setRe(NULL);
	val.setIm(NULL);
	setNext(nullptr);
}

Nod::Nod(Nod &x)
{
	val.setRe(x.getVal().getRe());
	val.setIm(x.getVal().getIm());
	setNext(x.getNext());
}

void Nod::setVal(Complex A)
{
	val = A;
}

void Nod::setNext(Nod *A)
{
	next = A;
}

Complex Nod::getVal()
{
	return val;
}

Nod* Nod::getNext()
{
	return next;
}

ostream & operator << (ostream &out, Nod x)
{
	out << "Valoarea din nod este: " << x.getVal() << '\n';
	return out;
}

istream & operator >> (istream &in, Nod &x)
{
	float a, b;

	cout << "Introduceti valoarea din nod (partea reala/imaginara): ";
	in >> a >> b;
	Complex aux(a, b);

	x.setVal(aux);
	x.setNext(nullptr);
	return in;
}

Nod Nod::operator = (Nod x)
{
	delete this;
	val.setRe(x.getVal().getRe());
	val.setIm(x.getVal().getIm());
	setNext(x.getNext());

	return *this;
}

void Nod::showList()
{
	Nod *o = this;

	while (o != nullptr)
	{
		cout << o->getVal() << ' ';
		o = o->getNext();
	}
}

void Nod::deleteList()
{
	Nod *o = this;
	while (o != nullptr)
	{
		Nod *p = o->getNext();
		delete o;
		o = p;
	}
}

Nod::~Nod()
{
	val.setRe(NULL);
	val.setIm(NULL);
	delete next;
}
