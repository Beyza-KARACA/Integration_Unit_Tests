#include "Alis.h"

string* Alis::getSembol()
{
	return sembol;
}

int Alis::getAlisSayisi()
{
	return alisSayisi;
}

int* Alis::getAdet()
{
	return adet;
}

double Alis::getAlisTutar()
{
	return alisTutar;
}

Portfoy* Alis::getPortfoy()
{
	return ap;
}



Alis::Alis(int as, string* s, int* a)
{
	alisSayisi = as;

	sembol = new string[as];
	sembol = s;

	adet = new int[as];
	adet = a;

	idVarMi = false;
}

void Alis::alisiGerceklestir(Hisse *h, Portfoy *p)
{
	ap = new Portfoy(p->ps,p->id,p->sembol,p->maliyet,p->adet);
	for (int i = 0; i < alisSayisi; i++)
	{
		for (int j = 0; j < ap->ps; j++) {
			idVarMi = false;
			if (ap->sembol[j] == sembol[i]) {

				for (int z = 0; z < h->hs; z++)
				{
					idVarMi = false;
					if (h->sembol[z] == sembol[i]) {
						alisTutar = (adet[i])*(h->fiyat[z]);
						idVarMi = true;
						break;
					} 
				}
				if (idVarMi) {
					ap->maliyet[j] = ((ap->adet[j] * ap->maliyet[j]) + (alisTutar)) / (ap->adet[j] + adet[i]);
					maliyet = ap->maliyet[j];
					ap->adet[j] = ap->adet[j] + adet[i];
					adt = ap->adet[j];
					break;
				} else cout << "Verilen emir ile iliþkili bir hisse bulunamadýðý için alýþ iþleminiz gerçekleþtirilememiþtir" << endl;
				
			}
		}
		if(!idVarMi) cout << "Verilen emir ile iliþkili bir portfoy bulunamadýðý için alýþ iþleminiz gerçekleþtirilememiþtir" << endl; 
	}
	cout << endl;
	cout << "Alýþ sonrasý:" << endl;;
	ap->PortfoyYazdir();
	cout << endl;

}
