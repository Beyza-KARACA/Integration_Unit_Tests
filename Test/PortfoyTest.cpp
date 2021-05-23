/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Portfoy bilgilerinin test edildiði  sýnýf
* </p>
*/
#include "PortfoyTest.h"
#include <typeinfo>

void PortfoyTest::SetUpTestCase()
{
	banka = new Banka();
	portfoy = banka->d->portfoyDosyaOku(banka->portfoyJson);
}

void PortfoyTest::TearDownTestCase()
{
	delete portfoy, banka;
}

TEST_F(PortfoyTest, PortfoySayisiTest)
{
	ASSERT_EQ(4, portfoy->getPortfoySayisi());
}

TEST_F(PortfoyTest, IdUzunluguTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->id[i].length() == 24) check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, PortfoyMuTest)
{
	bool check;

	if (typeid(portfoy).name() == "Portfoy" && portfoy != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, IdBosMuTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->id[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, IdStringMiTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (typeid(portfoy->id[i]).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, SembolBosMuTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->sembol[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, SembolStringMiTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (typeid(portfoy->getSembol()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}

TEST_F(PortfoyTest, MaliyetSifirMiTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->maliyet[i] == 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, MaliyetDoubleMýTest)
{
	bool check;

	if (typeid(portfoy->getMaliyet()).name() == "double") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, MaliyetSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->maliyet[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, AdetInteMýTest)
{
	bool check;

	if (typeid(portfoy->getAdet()).name() == "integer") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(PortfoyTest, AdetSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->adet[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}