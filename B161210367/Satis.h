#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>

#include "Hisse.h"
#include "Portfoy.h"

using namespace std;

class Satis
{
public:

	string *sembol;

	int satisSayisi = 0;
	int* adet;

	double* karZarar, guncelFiyat, maliyet, toplam;

	bool idVarMi;

	string* getSembol();
	int* getAdet();
	double* getKarZarar();
	double getGuncelFiyat();
	double getMaliyet();
	double getToplam();
	int getSatisSayisi();

	Satis(int, string*, int*);
	void satisiGerceklestir(Hisse*, Portfoy*);
	void sonucYaz();
};

