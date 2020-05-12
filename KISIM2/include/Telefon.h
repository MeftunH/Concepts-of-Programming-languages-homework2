/**
*
* @author 
* Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
  Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr

* @since 22/04/2020
* <p>
*Rastgele telefon uretme .h dosyasi
* </p>
*/
#ifndef TELEFON_H
#define TELEFON_H
#include "string.h"
#include "Rastgele.h"
#include "IMEINo.h"
struct TELEFON
{
//degiskenleri tanimladik
char* telefondizi;
//nesne gibi dusunebilecegimiz degiskenleri kendi siniflarindan turettik
Rastgele secicisuper;
Rastgele randomsayisuper;
ImeiNo imenosuper;
//fonskiyon gostericileri
char*(*Telefonnouret)(struct TELEFON*);
void (*telyaz)(struct TELEFON*);
void(*telyoket)(struct TELEFON*);
};
//Telefon structurini temsil eden degisken
typedef struct TELEFON* Telefon;
//constructor olarak dusunulebilir
Telefon TelefonOlustur();
//fonksiyonlar
char* _Telefonnouret(const Telefon);
void _telyoket(const Telefon);
#endif