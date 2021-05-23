#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>

#include "Alis.h"
#include "Satis.h"
#include "Hisse.h"
#include "Portfoy.h"

using namespace std;

class Emir
{
public:

	string *id, *islem, *sembol, *alislar_sembol, *satislar_sembol;

	int *adet, *alislar_adet, *satislar_adet;

	int es = 0;

	Hisse* hs;
	Portfoy* pr;
	Satis* s;
	Alis* a;

	Emir(int,string*, string*, string*, int*,Hisse*,Portfoy*);
	string* getId();
	string* getIslem();
	string* getSembol();
	string* getAlislarSembol();
	string* getSatislarSembol();
	int* getAdet();
	int* getAlislarAdet();
	int* getSatislarAdet();
	int getEmirSayisi();
	Hisse* getHisse();
	Portfoy* getPortfoy();
	Alis* getAlis();
	Satis* getSatis();
	void alisIslemYonlendir(int,int*);
	void satisIslemYonlendir(int, int*);

};

