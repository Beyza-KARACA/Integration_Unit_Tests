/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Portfoy Bilgilerinin olduðu sýnýf
* </p>
*/
#include "Portfoy.h"

Portfoy::Portfoy(int portfoyler,string* i, string* s, double *m, int* a)
{
	id = new string[portfoyler];
	id = i;
	sembol= new string[portfoyler];
	sembol = s;
	maliyet = new double[portfoyler];
	maliyet = m; 
	adet = new int[portfoyler];
	adet = a;
	ps = portfoyler;

}

string* Portfoy::getId()
{
	return id;
}

string* Portfoy::getSembol()
{
	return sembol;
}

double* Portfoy::getMaliyet()
{
	return maliyet;
}

int* Portfoy::getAdet()
{
	return adet;
}

int Portfoy::getPortfoySayisi()
{
	return ps;
}

Portfoy::Portfoy()
{
}

void Portfoy::PortfoyYazdir()
{
	cout << "Güncel Portföy:" << endl;
	for (int i = 0; i < ps; i++)
	{
		cout << "Hisse: "<< sembol[i] << endl;
		cout << "Adet: " << adet[i] << endl;
		cout << "Maliyet: " << maliyet[i] << endl;
		cout << "------------------------------"<< endl;
	}
}
