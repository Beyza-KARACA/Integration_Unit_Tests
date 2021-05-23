#pragma once
#include "../B161210367/Hisse.h"
#include "../B161210367/Banka.h"
#include "../B161210367/Portfoy.h"
#include "../B161210367/Satis.h"
#include <gtest/gtest.h>
class SatisTest :public::testing::Test
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Banka* banka;
	static Portfoy* portfoy;
	static Satis* satis;
	static Hisse* hisse;
	static Emir* emir;
};
Hisse* SatisTest::hisse = NULL;
Banka* SatisTest::banka = NULL;
Portfoy* SatisTest::portfoy = NULL;
Satis* SatisTest::satis = NULL;
Emir* SatisTest::emir = NULL;