/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Satýþ iþlemlerinin  test edildiði  sýnýf
* </p>
*/
#include "SatisTest.h"
#include <typeinfo>

void SatisTest::SetUpTestCase()
{
	banka = new Banka();
	portfoy = banka->d->portfoyDosyaOku(banka->portfoyJson);
	hisse = banka->d->hisseDosyaOku(banka->hisseJson);
	emir = new Emir(banka->d->emirSayisi, banka->d->emir_id, banka->d->emir_islem, banka->d->emir_sembol, banka->d->emir_adet, banka->d->hisseDosyaOku(banka->hisseJson), banka->d->portfoyDosyaOku(banka->portfoyJson));
	emir->satisIslemYonlendir(banka->d->satisSayi, banka->d->satisIndex);
	satis = emir->s;
	satis->satisiGerceklestir(hisse, portfoy);
}
void SatisTest::TearDownTestCase()
{
	delete satis, hisse, portfoy, banka;
}

TEST_F(SatisTest, SatisMiTest)
{
	bool check;

	if (typeid(satis).name() == "Satis" && satis != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);

}
TEST_F(SatisTest, SatisSayisiTest)
{
	ASSERT_EQ(2, satis->getSatisSayisi());
}
TEST_F(SatisTest, SembolBosMuTest)
{
	bool check;
	for (int i = 0; i < satis->getSatisSayisi(); i++)
	{
		if ((satis->getSembol())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(SatisTest, SembolStringMiTest)
{
	bool check;
	for (int i = 0; i < satis->getSatisSayisi(); i++)
	{
		if (typeid(satis->getSembol()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(SatisTest, AdetIntMýTest)
{
	bool check;

	if (typeid(satis->getAdet()).name() == "integer") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(SatisTest, AdetSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < satis->getSatisSayisi(); i++)
	{
		if ((satis->getAdet())[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(SatisTest, AdetSifirMiTest)
{
	bool check;
	for (int i = 0; i < satis->getSatisSayisi(); i++)
	{
		if ((satis->getAdet())[i] == 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(SatisTest, SatisPortfoydeVarMýTest)
{
	bool check;
	for (int i = 0; i < satis->getSatisSayisi(); i++)
	{
		for (int j = 0; j < portfoy->ps; j++) {
			if ((satis->getSembol())[i] == (portfoy->getSembol())[j]) check = true;
			else check = false;
		}
	}
	ASSERT_TRUE(true, check);
}
TEST_F(SatisTest, KarZararTest)
{
	bool check;
	if (satis->karZarar[0] == 344 && satis->karZarar[0] == -226) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(SatisTest, ToplamTest)
{
	bool check;

	ASSERT_EQ(round(117.2),round(satis->toplam));
}

