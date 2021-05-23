#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<fstream>
#include <nlohmann/json.hpp>
#include<nlohmann/json_fwd.hpp>

#include "Hisse.h"
#include "Emir.h"
#include "Portfoy.h"

using namespace std;
using namespace nlohmann;
using json = nlohmann::json;

class Dosya
{
public:

	ifstream oku;

	json okunan_JH, okunan_JP, okunan_JE;

	string okunan, *hisse_id, *hisse_ad, *hisse_sembol, *portfoy_id, *portfoy_sembol, *emir_id, *emir_sembol, *emir_islem;

	double *hisse_fiyat, *portfoy_maliyet;

	int* portfoy_adet, *emir_adet;
	int* alisIndex = NULL;
	int *satisIndex = NULL;

	int emirSayisi, hisseSayisi, portfoySayisi;
	int alisSayi = 0;
	int satisSayi = 0;

	Hisse* h;
	Portfoy* p;
	Emir* e;

	Hisse* hisseDosyaOku(string);
	Portfoy* portfoyDosyaOku(string);
	Emir* emirDosyaOku(string);

	Dosya(string, string, string);
	~Dosya();
	
};

