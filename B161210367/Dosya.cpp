#include "Dosya.h"

Hisse* Dosya::hisseDosyaOku(string path)
{
	oku.open(path, ios::in);
	oku >> okunan_JH;

	hisseSayisi = okunan_JH["Hisseler"].size();

	hisse_id = new string[hisseSayisi];
	hisse_ad = new string[hisseSayisi];
	hisse_sembol = new string[hisseSayisi];
	hisse_fiyat = new double[hisseSayisi];

	for (int i = 0; i < hisseSayisi; i++) {

		hisse_id[i] = okunan_JH["Hisseler"][i]["_id"];
		hisse_ad[i] = okunan_JH["Hisseler"][i]["Ad"];
		hisse_sembol[i] = okunan_JH["Hisseler"][i]["Sembol"];
		hisse_fiyat[i] = okunan_JH["Hisseler"][i]["Fiyat"];
	}

	oku.close();

	h = new Hisse(hisseSayisi, hisse_id, hisse_ad, hisse_sembol, hisse_fiyat);
	return h;

}

Portfoy* Dosya::portfoyDosyaOku(string path)
{
	oku.open(path, ios::in);
	oku >> okunan_JP;

	portfoySayisi = okunan_JP["Portfoy"].size();

	portfoy_id = new string[portfoySayisi];
	portfoy_sembol = new string[portfoySayisi];
	portfoy_maliyet = new double[portfoySayisi];
	portfoy_adet = new int[portfoySayisi];

	for (int i = 0; i < portfoySayisi; i++) {

		portfoy_id[i] = okunan_JP["Portfoy"][i]["_id"];
		portfoy_sembol[i] = okunan_JP["Portfoy"][i]["Sembol"];
		portfoy_maliyet[i] = okunan_JP["Portfoy"][i]["Maliyet"];
		portfoy_adet[i] = okunan_JP["Portfoy"][i]["Adet"];
		
	}
	oku.close();

	p = new Portfoy(portfoySayisi,portfoy_id, portfoy_sembol, portfoy_maliyet, portfoy_adet);
	return p;
}

Emir* Dosya::emirDosyaOku(string path)
{
	oku.open(path, ios::in);
	oku >> okunan_JE;

	emirSayisi = okunan_JE["Emirler"].size();

	emir_id = new string[emirSayisi];
	emir_sembol = new string[emirSayisi];
	emir_islem = new string[emirSayisi];
	emir_adet = new int[emirSayisi];

	alisIndex = new int[emirSayisi];
	satisIndex = new int[emirSayisi];

	for (int i = 0; i < emirSayisi; i++) {

		emir_id[i] = okunan_JE["Emirler"][i]["_id"];
		emir_sembol[i] = okunan_JE["Emirler"][i]["Sembol"];
		emir_islem[i] = okunan_JE["Emirler"][i]["Islem"];
		emir_adet[i] = okunan_JE["Emirler"][i]["Adet"];
		
		if (emir_islem[i] == "ALIS") {
			alisIndex[alisSayi] =i;
			alisSayi++; 
		}

		else if (emir_islem[i] == "SATIS") {
			satisIndex[satisSayi] = i;
			satisSayi++;
		}
	}

	oku.close();
	e = new Emir(emirSayisi,emir_id, emir_islem, emir_sembol, emir_adet, h,p);
	e->alisIslemYonlendir(alisSayi, alisIndex);
	e->satisIslemYonlendir(satisSayi, satisIndex);
	cout << endl;
	cout << "Son:" << endl;;
	p->PortfoyYazdir();
	cout << endl;
	return e;
}

Dosya::Dosya(string Hpath, string Ppaths,string Epath)
{
	hisseDosyaOku(Hpath);
	portfoyDosyaOku(Ppaths);
	emirDosyaOku(Epath);
}


Dosya::~Dosya()
{
	
}
