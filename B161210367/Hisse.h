#pragma once 
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>

using namespace std;

class Hisse
{
public:

	string* id, * ad, * sembol;
	double* fiyat;
	int hs;

	Hisse();
	Hisse(int, string*, string*, string*, double*);
	~Hisse();
	string* getID();
	string* getAd();
	string* getSembol();
	double* getFiyat();
	int getHisseSayisi();
	bool Deneme();
};

