#pragma once
#include "../B161210367/Hisse.h"
#include "../B161210367/Banka.h"
#include <gtest/gtest.h>
class HisseTest:public::testing::Test
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();
	static Hisse* hisse;
	static Banka* banka;
};
Hisse* HisseTest::hisse = NULL;
Banka* HisseTest::banka = NULL;