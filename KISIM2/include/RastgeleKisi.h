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
#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include "Kisi.h"
//structimizi tanimladik
struct RASTGELEKISI
{
int deger;
//nesne gibi dusunebilecegimiz degiskenleri kendi siniflarindan turettik
Kisi kisisuper;
//fonksiyon gostericleri
void (*RastgeleKisiUret)(struct RASTGELEKISI*);
void (*KisiYaz)(struct RASTGELEKISI*);
void (*RastgeleKisiyoket)(struct RASTGELEKISI*);
};
//Rastgelekisi structurini temsil eden degisken
typedef struct RASTGELEKISI* Rastgelekisi;
//constructor olarak dusunulebilir
Rastgelekisi RastgeleKisiolustur();
//fonksiyonlar
void _RastgeleKisiUret(const Rastgelekisi);
void _KisiYaz(const Rastgelekisi);
void _RastgeleKisiYoket(const Rastgelekisi);
#endif