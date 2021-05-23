/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Hisse bilgilerinin test edildiði sýnýf
* </p>
*/
#include "HisseTest.h"
#include <typeinfo>

void HisseTest::SetUpTestCase()
{
	banka = new Banka();
	hisse = banka->d->hisseDosyaOku(banka->hisseJson);
}

void HisseTest::TearDownTestCase()
{
	delete hisse, banka;
}

TEST_F(HisseTest, HisseMiTest)
{
	bool check;

	if (typeid(hisse).name() == "Hisse" && hisse != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, HisseSayisiTest)
{
	ASSERT_EQ(100, hisse->getHisseSayisi());
}

TEST_F(HisseTest, IdUzunluguTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getID())[i].length() == 24) check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}

TEST_F(HisseTest, IdBosMuTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getID())[i]=="") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, IdStringMiTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if (typeid((hisse->getID())[i]).name() =="string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, SembolBosMuTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getSembol())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, SembolStringMiTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if (typeid(hisse->getSembol()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, AdStringMiTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if (typeid(hisse->getAd()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, AdBosMuTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getAd())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, FiyatSifirMiTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getFiyat())[i] == 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, FiyatDoubleMýTest)
{
	bool check;
	
		if (typeid(hisse->getFiyat()).name() == "double") check = true;
		else check = false;
	
	ASSERT_TRUE(true, check);
}
TEST_F(HisseTest, FiyatSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getFiyat())[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}