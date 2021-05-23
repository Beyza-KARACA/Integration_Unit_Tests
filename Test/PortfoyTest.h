#pragma once
#include "../B161210367/Portfoy.h"
#include "../B161210367/Banka.h"
#include <gtest/gtest.h>
class PortfoyTest :public::testing::Test
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Portfoy* portfoy;
	static Banka* banka;
};
Portfoy* PortfoyTest::portfoy = NULL;
Banka* PortfoyTest::banka = NULL;

