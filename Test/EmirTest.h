#pragma once
#include "../B161210367/Emir.h"
#include "../B161210367/Banka.h"
#include "../B161210367/Portfoy.h"
#include <gtest/gtest.h>
class EmirTest :public::testing::Test
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Emir* emir;
	static Banka* banka;
	static Portfoy* portfoy;
};
Emir* EmirTest::emir = NULL;
Banka* EmirTest::banka = NULL;
Portfoy* EmirTest::portfoy = NULL;

