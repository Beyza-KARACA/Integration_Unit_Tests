#include "Satis.h"
Satis::Satis(int ss , string* s, int* a)
{
	satisSayisi = ss;

	sembol = new string[ss];
	sembol= s;

	adet = new int[ss];
	adet = a;

	karZarar = new double[ss];

	toplam = 0.0;
}
void Satis::satisiGerceklestir(Hisse* h, Portfoy* p)
{
	for (int i = 0; i < satisSayisi; i++)
	{
		for (int j = 0; j < p->ps; j++) {
			idVarMi = false;
			if (p->sembol[j] == sembol[i]) {
				if (p->adet[j] >= adet[i]) {
					for (int z = 0; z < h->hs; z++)
					{
						idVarMi = false;
						if (h->sembol[z] == sembol[i]) {
							guncelFiyat = adet[i] * h->fiyat[z];
							idVarMi = true;
							break;
						}
					}
					if (idVarMi) {
						maliyet = p->maliyet[j] * adet[i];
						p->adet[j] -= adet[i];
						break;
					}
					else cout << "Verilen emir ile ili�kili bir hisse bulunamad��� i�in al�� i�leminiz ger�ekle�tirilememi�tir" << endl;
				}
				else cout << "Stok olmamas� nedeniyle istenilen adette sat�� yap�lamamaktad�r" << endl;
			}
		}
		if (idVarMi) karZarar[i] = guncelFiyat - maliyet;
			else cout << "Verilen emir ile ili�kili bir portfoy bulunamad��� i�in al�� i�leminiz ger�ekle�tirilememi�tir" << endl;
	}
	cout << endl;
	cout << "Sat�� sonras�:" << endl;;
	p->PortfoyYazdir();
	cout << endl;
	sonucYaz();
	cout << endl;
}

void Satis::sonucYaz()
{
	toplam = 0;
	for (int i = 0; i < satisSayisi; i++) {
		cout<<sembol[i]<<": " << karZarar[i] << endl; 
		toplam += karZarar[i];
	}
	cout << toplam << endl;
}

string* Satis::getSembol()
{
	return sembol;
}

int* Satis::getAdet()
{
	return adet;
}

double* Satis::getKarZarar()
{
	return karZarar;
}

double Satis::getGuncelFiyat()
{
	return guncelFiyat;
}

double Satis::getMaliyet()
{
	return maliyet;
}

double Satis::getToplam()
{
	return toplam;
}

int Satis::getSatisSayisi()
{
	return satisSayisi;
}
