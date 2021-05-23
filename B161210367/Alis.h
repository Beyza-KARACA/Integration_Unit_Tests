#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>

#include "Hisse.h"
#include "Portfoy.h"

using namespace std;

class Alis
{
public:

	string *sembol;

	int alisSayisi = 0;
	int* adet;
	int adt;

	double alisTutar,maliyet;

	bool idVarMi;

	Portfoy* ap;

	string* getSembol();
	int getAlisSayisi();
	int* getAdet();
	double getAlisTutar(); 
	Portfoy* getPortfoy();

	Alis(int,string*,int*);
	void alisiGerceklestir(Hisse*  h, Portfoy *p);};

