#include "Banka.h"
#include "Dosya.h"

Dosya* Banka::getBilgiler()
{
	return d;
}

Banka::Banka()
{
	 d = new Dosya(hisseJson,portfoyJson,emirJson);
}

Banka::~Banka()
{
	
}
