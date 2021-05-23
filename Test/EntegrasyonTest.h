#pragma once
#include "../B161210367/Hisse.h"
#include "../B161210367/Dosya.h"
#include "../B161210367/Portfoy.h"
#include "../B161210367/Emir.h"
#include <gtest/gtest.h>

class EntegrasyonTest :public::testing::Test
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Dosya* dosya;
	static Portfoy* portfoy;
	static Hisse* hisse;
	static Emir* emir; 
	static string hisseJson;
	static string portfoyJson;
	static string emirJson;
	~EntegrasyonTest();
};
Hisse* EntegrasyonTest::hisse = NULL;
Dosya* EntegrasyonTest::dosya = NULL;
Portfoy* EntegrasyonTest::portfoy = NULL;
Emir* EntegrasyonTest::emir = NULL;
string EntegrasyonTest::hisseJson = "";
string EntegrasyonTest::portfoyJson = "";
string EntegrasyonTest::emirJson = "";