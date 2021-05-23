/**
*
* @author Beyza KARACA beyza.karaca@ogr.sakarya.edu.tr
* @since 23.05.2021
* <p>
* Dosyan�n okunup geri d�nd��� banka s�n�f. Yani banka dosya s�n�f�n� �a��r�yor. Dosya s�n�f� okuyor ve s�n�flara ayr��t�r�yor. 
* Emir s�n�f� al�� ve sat��a g�re i�lem yap�p buraya geri d�nd�r�yor.
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
