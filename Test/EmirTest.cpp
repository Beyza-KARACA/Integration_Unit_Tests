/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Emirlerin test edildiði sýnýf 
* </p>
*/
#include "EmirTest.h"
#include <typeinfo>

void EmirTest::SetUpTestCase()
{
	banka = new Banka();
	emir =new Emir(banka->d->emirSayisi, banka->d->emir_id, banka->d->emir_islem, banka->d->emir_sembol, banka->d->emir_adet, banka->d->hisseDosyaOku(banka->hisseJson), banka->d->portfoyDosyaOku(banka->portfoyJson));
	portfoy= banka->d->portfoyDosyaOku(banka->portfoyJson);
}

void EmirTest::TearDownTestCase()
{
	delete emir, portfoy, banka;
}
TEST_F(EmirTest, HisseMiTest)
{
	bool check;

	if (typeid(emir->getHisse()).name() == "Hisse"&& emir->getHisse() != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, PortfoyMuTest)
{
	bool check;

	if (typeid(emir->getPortfoy()).name() == "Portfoy" && emir->getPortfoy() != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, EmirMiTest)
{
	bool check;

	if (typeid(emir).name() == "Emir" && emir != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}

TEST_F(EmirTest, EmirSayisiTest)
{
	ASSERT_EQ(3, emir->getEmirSayisi());
}

TEST_F(EmirTest, IdUzunluguTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getId())->length() == 24) check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}

TEST_F(EmirTest, IdBosMuTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getId())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, IdStringMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if (typeid((emir->getId())[i]).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, SembolBosMuTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getSembol())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, SembolStringMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if (typeid(emir->getSembol()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}

TEST_F(EmirTest, IslemBosMuTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getIslem())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, IslemStringMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if (typeid(emir->getIslem()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, AlisSatisMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getIslem())[i] =="ALIS"|| (emir->getIslem())[i] == "SATIS") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, AdetIntMýTest)
{
	bool check;

	if (typeid(emir->getAdet()).name() == "integer") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, AdetSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getAdet())[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, AdetSifirMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getAdet())[i] == 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest,AlisSatisPortfoydeVarMýTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		for(int j=0;j<portfoy->ps;j++){
			if ((emir->getSembol())[i] == (portfoy->getSembol())[j]) check = true;
			else check = false;
		}
	}
	ASSERT_TRUE(true, check);
}

TEST_F(EmirTest, YeteriKadarVarMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		for (int j = 0; j < portfoy->ps; j++) {
			if ((emir->getIslem())[i] == "SATIS"&& (emir->getSembol())[i]==(portfoy->getSembol())[j]&&portfoy->getAdet()>=emir->getAdet()) check = true;
			else check = false;
		}
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EmirTest, AlisOlustuMuTest)
{
	bool check;

	if (typeid(emir->getAlis()).name() == "Alis" && emir->getAlis() != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);

}
TEST_F(EmirTest, SatisOlustuMuTest)
{
	bool check;

	if ((typeid(emir->getSatis()).name() == "Satis") && emir->getSatis() != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);

}

TEST_F(EmirTest, AlisSayisiTest)
{
	ASSERT_EQ(1, banka->d->alisSayi);
}
TEST_F(EmirTest, SatisSayisiTest)
{
	ASSERT_EQ(2, banka->d->satisSayi);
}
