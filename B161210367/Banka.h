#pragma once
#include "Dosya.h"

using namespace std;

class Banka
{
public:
	string hisseJson = "../hisseler.json";
	string portfoyJson = "../portfoy.json";
	string emirJson = "../emirler.json";
	Dosya* d;
	Dosya* getBilgiler();
	Banka();
	~Banka();
};

