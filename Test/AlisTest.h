#pragma once
#include "../B161210367/Hisse.h"
#include "../B161210367/Banka.h"
#include "../B161210367/Portfoy.h"
#include "../B161210367/Alis.h"
#include <gtest/gtest.h>
class AlisTest :public::testing::Test
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Banka* banka;
	static Portfoy* portfoy;
	static Alis* alis;
	static Hisse* hisse;
	static Emir* emir;
};
Hisse* AlisTest::hisse = NULL;
Banka* AlisTest::banka = NULL;
Portfoy* AlisTest::portfoy = NULL;
Alis* AlisTest::alis = NULL;
Emir* AlisTest::emir = NULL;

