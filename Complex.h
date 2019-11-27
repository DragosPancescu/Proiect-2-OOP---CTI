#pragma once
#include <iostream>

using namespace std;

class Complex
{
private:
	float im;
	float re;
public:
	////////////CTR///////////
	Complex();
	Complex(float re, float im) : re(re), im(im) {};
	Complex(const Complex &x) : Complex(x.re, x.im) {};

	//////////GetsiSet////////
	float getRe();
	float getIm();
	void setRe(float);
	void setIm(float);
	bool isNull();

	/////////Operatori////////
	friend ostream & operator << (ostream &, Complex );
	friend istream & operator >> (istream &, Complex &);
	Complex operator = (Complex);
	Complex operator + (Complex);
	Complex operator - (Complex);
	Complex operator * (Complex);

	///////////DCTR///////////
	~Complex();
};

