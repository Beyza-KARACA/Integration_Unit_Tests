/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Dosyanýn okunup geri döndüðü banka sýnýf. Yani banka dosya sýnýfýný çaðýrýyor. Dosya sýnýfý okuyor ve sýnýflara ayrýþtýrýyor. 
* Emir sýnýfý alýþ ve satýþa göre iþlem yapýp buraya geri döndürüyor.
* </p>
*/
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
