/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Dýþ kaynakla baðlantýlý yani dosyadan okuma yaparak atama yapan ve  test gerçekleþtiren sýnýf
* </p>
*/

#include "EntegrasyonTest.h"

void EntegrasyonTest::SetUpTestCase()
{
	hisseJson = "../hisseler.json";
	portfoyJson = "../portfoy.json";
	emirJson = "../emirler.json";
	dosya = new Dosya(hisseJson,portfoyJson, emirJson);
	hisse = dosya->hisseDosyaOku(hisseJson);
	portfoy = dosya->portfoyDosyaOku(portfoyJson);
	emir = new Emir(dosya->emirSayisi, dosya->emir_id, dosya->emir_islem, dosya->emir_sembol, dosya->emir_adet, hisse, portfoy);
}

void EntegrasyonTest::TearDownTestCase()
{

}

EntegrasyonTest::~EntegrasyonTest()
{
	
}

TEST_F(EntegrasyonTest, Hisse_HisseMiTest)
{
	bool check;

	if (typeid(hisse).name() == "Hisse" && hisse != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}

TEST_F(EntegrasyonTest, Hisse_HisseSayisiTest)
{
	ASSERT_EQ(100, hisse->getHisseSayisi());
}

TEST_F(EntegrasyonTest, Hisse_IdUzunluguTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getID())[i].length() == 24) check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Hisse_IdBosMuTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getID())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Hisse_IdStringMiTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if (typeid((hisse->getID())[i]).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Hisse_SembolBosMuTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getSembol())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Hisse_SembolStringMiTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if (typeid(hisse->getSembol()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Hisse_AdStringMiTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if (typeid(hisse->getAd()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Hisse_AdBosMuTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getAd())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Hisse_FiyatSifirMiTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getFiyat())[i] == 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Hisse_FiyatDoubleMýTest)
{
	bool check;

	if (typeid(hisse->getFiyat()).name() == "double") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}

TEST_F(EntegrasyonTest, Hisse_FiyatSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < hisse->hs; i++)
	{
		if ((hisse->getFiyat())[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_PortfoySayisiTest)
{
	ASSERT_EQ(4, portfoy->getPortfoySayisi());
}
TEST_F(EntegrasyonTest, Portfoy_IdUzunluguTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->id[i].length() == 24) check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_PortfoyMuTest)
{
	bool check;

	if (typeid(portfoy).name() == "Portfoy" && portfoy != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_IdBosMuTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->id[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_IdStringMiTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (typeid(portfoy->id[i]).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_SembolBosMuTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->sembol[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_SembolStringMiTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (typeid(portfoy->getSembol()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}

TEST_F(EntegrasyonTest, Portfoy_MaliyetSifirMiTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->maliyet[i] == 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_MaliyetDoubleMýTest)
{
	bool check;

	if (typeid(portfoy->getMaliyet()).name() == "double") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_MaliyetSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->maliyet[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_AdetInteMýTest)
{
	bool check;

	if (typeid(portfoy->getAdet()).name() == "integer") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Portfoy_AdetSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < portfoy->ps; i++)
	{
		if (portfoy->adet[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_HisseMiTest)
{
	bool check;

	if (typeid(emir->getHisse()).name() == "Hisse" && emir->getHisse() != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}

TEST_F(EntegrasyonTest, Emir_PortfoyMuTest)
{
	bool check;

	if (typeid(emir->getPortfoy()).name() == "Portfoy" && emir->getPortfoy() != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}


TEST_F(EntegrasyonTest, Emir_EmirMiTest)
{
	bool check;

	if (typeid(emir).name() == "Emir" && emir != NULL) check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}

TEST_F(EntegrasyonTest, Emir_AdetIntMýTest)
{
	bool check;

	if (typeid(emir->getAdet()).name() == "integer") check = true;
	else check = false;

	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_EmirSayisiTest)
{
	ASSERT_EQ(3, emir->getEmirSayisi());
}
TEST_F(EntegrasyonTest, Emir_IdUzunluguTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getId())->length() == 24) check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}

TEST_F(EntegrasyonTest, Emir_IdBosMuTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getId())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_IdStringMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if (typeid((emir->getId())[i]).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_SembolBosMuTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getSembol())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_SembolStringMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if (typeid(emir->getSembol()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}

TEST_F(EntegrasyonTest, Emir_IslemBosMuTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getIslem())[i] == "") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_IslemStringMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if (typeid(emir->getIslem()).name() == "string") check = true;
		else check = false;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_AlisSatisMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getIslem())[i] == "ALIS" || (emir->getIslem())[i] == "SATIS") check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_AdetSifirdanBuyukMuTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getAdet())[i] < 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_AdetSifirMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		if ((emir->getAdet())[i] == 0) check = false;
		else check = true;
	}
	ASSERT_TRUE(true, check);
}
TEST_F(EntegrasyonTest, Emir_AlisSatisPortfoydeVarMýTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		for (int j = 0; j < portfoy->ps; j++) {
			if ((emir->getSembol())[i] == (portfoy->getSembol())[j]) check = true;
			else check = false;
		}
	}
	ASSERT_TRUE(true, check);
}

TEST_F(EntegrasyonTest, Emir_YeteriKadarVarMiTest)
{
	bool check;
	for (int i = 0; i < emir->es; i++)
	{
		for (int j = 0; j < portfoy->ps; j++) {
			if ((emir->getIslem())[i] == "SATIS" && (emir->getSembol())[i] == (portfoy->getSembol())[j] && portfoy->getAdet() >= emir->getAdet()) check = true;
			else check = false;
		}
	}
	ASSERT_TRUE(true, check);
}