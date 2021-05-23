#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include "Portfoy.h"

using namespace std;
class Portfoy
{
public:

	string* id, * sembol;
	double* maliyet;
	int* adet;
	int ps;

	Portfoy(int,string*, string*, double*, int* );
	Portfoy();
	string* getId();
	string* getSembol();
	double* getMaliyet();
	int* getAdet();
	int getPortfoySayisi();
	void PortfoyYazdir();
};

