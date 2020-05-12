/**
*
* @author 
* Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
  Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr

* @since 22/04/2020
* <p>
*Rastgele kisi uretme .h dosyasi
* </p>
*/
#ifndef KISI_H
#define KISI_H
#include "string.h"
#include "stdio.h"
#include "Rastgele.h"
#include "KimlikNo.h"
#include "Telefon.h"
struct KISI
{
//degiskenleri tanimliyoruz
int yas;
char* isimsoyisim;
//nesne gibi dusunebilecegimiz degiskenleri kendi siniflarindan turettik
Telefon telefonsuper;
KimlikNo kimliknosuper;
Rastgele randomsayisuper;
Rastgele randomyassuper;
//fonksiyon gostericileri
char* (*isimsoyisimoku)(struct KISI*);
void(*kisiyoket)(struct KISI*);
};
//KISI structurini temsil eden degisken
typedef struct KISI* Kisi;
//constructor olarak dusunebiliriz
Kisi KisiOlustur();
char* _isimsoyisimoku(const Kisi);
void _kisiyoket(const Kisi);
#endif