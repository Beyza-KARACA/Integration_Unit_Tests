#include "Emir.h"

Emir::Emir(int emirler,string* i, string* is, string *s, int* a,Hisse* h,Portfoy* p)
{
	es = emirler;

	id = new string[emirler];
	id = i;

	islem = new string[emirler];
	islem = is;

	sembol = new string[emirler];
	sembol = s;

	adet = new int[emirler];
	adet = a;

	hs = new Hisse(h->hs,h->id, h->ad, h->sembol,h->fiyat);
	pr = new Portfoy(p->ps, p->id, p->sembol, p->maliyet, p->adet);
	
}

string* Emir::getId()
{
	return id;
}

string* Emir::getIslem()
{
	return islem;
}

string* Emir::getSembol()
{
	return sembol;
}

string* Emir::getAlislarSembol()
{
	return alislar_sembol;
}

string* Emir::getSatislarSembol()
{
	return satislar_sembol;
}

int* Emir::getAdet()
{
	return adet;
}

int* Emir::getAlislarAdet()
{
	return alislar_adet;
}

int* Emir::getSatislarAdet()
{
	return satislar_adet;
}

int Emir::getEmirSayisi()
{
	return es;
}

Hisse* Emir::getHisse()
{
	return hs;
}

Portfoy* Emir::getPortfoy()
{
	return pr;
}

Alis* Emir::getAlis()
{
	return a;
}

Satis* Emir::getSatis()
{
	return s;
}

void Emir::alisIslemYonlendir(int as, int* ai)
{
	alislar_sembol = new string[as];
	alislar_adet = new int[as];

	for(int i = 0; i < as ;i++ )
	{
		alislar_sembol[i] = sembol[ai[i]];
		alislar_adet[i] = adet[ai[i]];
	}

	a = new Alis(as, alislar_sembol, alislar_adet);
	
	a->alisiGerceklestir(hs,pr);
}

void Emir::satisIslemYonlendir(int ss, int* si)
{
	satislar_sembol = new string[ss];
	satislar_adet = new int[ss];
	for (int i = 0; i < ss; i++)
	{
		satislar_sembol[i] = sembol[si[i]];
		satislar_adet[i] = adet[si[i]];
	}
	s = new Satis(ss, satislar_sembol, satislar_adet);
	s->satisiGerceklestir(hs, pr);
}

