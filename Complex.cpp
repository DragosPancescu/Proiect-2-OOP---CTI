#include "pch.h"
#include "Complex.h"


Complex::Complex()
{
	setRe(NULL);
	setIm(NULL);
}

float Complex::getRe()
{
	return re;
}

float Complex::getIm()
{
	return im;
}

void Complex::setRe(float x)
{
	re = x;
}

void Complex::setIm(float x)
{
	im = x;
}

ostream & operator << (ostream &out, Complex A)
{
	out << A.getRe() << ' ' << A.getIm() << "*i";
	return out;
}

istream & operator >> (istream &in, Complex &A)
{
	float x, y;

	cout << "Introduceti partea reala si imaginara: ";
	in >> x >> y;
	A.setRe(x);
	A.setIm(y);

	return in;
}

Complex Complex::operator = (Complex A)
{
	setRe(A.getRe());
	setIm(A.getIm());
	return *this;
}

Complex Complex::operator + (Complex A)
{
	Complex R;
	R.setRe(getRe() + A.getRe());
	R.setIm(getIm() + A.getIm());

	return R;
}

Complex Complex::operator - (Complex A)
{
	Complex R;
	R.setRe(getRe() - A.getRe());
	R.setIm(getIm() - A.getIm());

	return R;
}

Complex Complex::operator * (Complex A)
{
	Complex R;
	R.setRe(getRe() * A.getRe() - getIm() * A.getIm());
	R.setIm(getRe() * A.getIm() + A.getRe() * getIm());

	return R;
}

bool Complex::isNull()
{
	if (im == NULL && re == NULL)
		return true;
	return false;
}

Complex::~Complex()
{
	setRe(NULL);
	setIm(NULL);
}
