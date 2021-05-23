#include "Hisse.h"

Hisse::Hisse(int hisseler, string* i, string* a, string* s, double* f)
{
	id = new string[hisseler];
	id = i;
	sembol = new string[hisseler];
	sembol = s;
	fiyat = new double[hisseler];
	fiyat = f;
	ad = new string[hisseler];
	ad = a;
	hs = hisseler;
}

string* Hisse::getID()
{
	return id;
}

string* Hisse::getAd()
{
	return ad;
}

string* Hisse::getSembol()
{
	return sembol;
}

double* Hisse::getFiyat()
{
	return fiyat;
}

int Hisse::getHisseSayisi()
{
	return hs;
}

bool Hisse::Deneme()
{
	return true;
}


Hisse::Hisse()
{

}


Hisse::~Hisse()
{
}
