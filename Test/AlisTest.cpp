/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Alýþ iþleminin test edildiði sýnýf
* </p>
*/
#include "AlisTest.h"
#include <typeinfo>

void AlisTest::SetUpTestCase()
{
	banka = new Banka();
	portfoy = banka->d->portfoyDosyaOku(banka->portfoyJson);
	hisse = banka->d->hisseDosyaOku(banka->hisseJson);
	emir = new Emir(banka->d->emirSayisi, banka->d->emir_id, banka->d->emir_islem, banka->d->emir_sembol, banka->d->emir_adet, banka->d->hisseDosyaOku(banka->hisseJson), banka->d->portfoyDosyaOku(banka->portfoyJson));
	emir->alisIslemYonlendir(banka->d->alisSayi, banka->d->alisIndex);
	alis = emir->a;
	alis->alisiGerceklestir(hisse, portfoy);
}
void AlisTest::TearDownTestCase()
{
	delete alis,hisse, portfoy, banka;
}
TEST_F(AlisTest, PortfoyMuTest)
{
	bool check;

	if (typeid(alis->getPortfoy()).name() == "Portfoy" && alis->getPortfoy() != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(AlisTest, AlisMiTest)
{
	bool check;

	if (typeid(alis).name() == "Alis" && alis != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);

}
TEST_F(AlisTest, AlisSayisiTest)
{
	ASSERT_EQ(1,alis->getAlisSayisi());
}
TEST_F(AlisTest, SembolBosMuTest)
{
	bool check;
	for (int i = 0; i < alis->getAlisSayisi(); i++)
	{
		if ((alis->getSembol())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(AlisTest, SembolStringMiTest)
{
	bool check;
	for (int i = 0; i < alis->getAlisSayisi(); i++)
	{
		if (typeid(alis->getSembol()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(AlisTest, AdetIntMýTest)
{
	bool check;

	if (typeid(alis->getAdet()).name() == "integer") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(AlisTest, AdetSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < alis->getAlisSayisi(); i++)
	{
		if ((alis->getAdet())[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(AlisTest, AdetSifirMiTest)
{
	bool check;
	for (int i = 0; i < alis->getAlisSayisi(); i++)
	{
		if ((alis->getAdet())[i] == 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(AlisTest, AlisPortfoydeVarMýTest)
{
	bool check;
	for (int i = 0; i < alis->getAlisSayisi(); i++)
	{
		for (int j = 0; j < portfoy->ps; j++) {
			if ((alis->getSembol())[i] == (portfoy->getSembol())[j]) check = true;
			else check = false;
		}
	}
	ASSERT_TRUE(true, check);
}
TEST_F(AlisTest, AlisTutarTest)
{
	bool check;
	
	ASSERT_EQ(2322.5, alis->getAlisTutar());
}
TEST_F(AlisTest, AlisAdetTest)
{
	bool check;

	ASSERT_EQ(750, alis->adt);
}
TEST_F(AlisTest, AlisMaliyetTest)
{
	bool check;
	ASSERT_EQ(round(8.76), round(alis->maliyet));
}

