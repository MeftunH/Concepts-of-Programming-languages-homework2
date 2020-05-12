/**
 *
 * @author
 * Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
 * Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr
 *
 * @since 22/04/2020
 * <p>
 * Rastgele kimlk numarasi uretme ve kontrol etme .h dosyasi
 * </p>
 */
#ifndef KIMLIKNO_H
#define KIMLIKNO_H
#include "Rastgele.h"
#include "string.h"
struct KIMLIKNO
{

int kimliknogecerlicount; //gecerli kimlik numaralini saymak icin
int kimliknogecersizcount; //gecersiz kimlik numaralini saymak icin
   int* tctempdizi; //int to char donusumunde buffer rolu oynayacak
   char* tcdizi; //tcnin tutulacagi dizi
   char*alinankimlikno;
   Rastgele randomsayisuper; //Nesne gibi dusunebilir.Sonucta c ile olabildigince oop yapmaya calisiyoruz
  //fonksiyon gostericileri
   char* (*kimliknouret)(struct KIMLIKNO*);
   void (*yaz)(struct KIMLIKNO*);
   void(*kimliknokontrolet)(struct KIMLIKNO*,char*);
   void (*kimliknoyoket)(struct KIMLIKNO*);
};
//struct Kimlikno'yu temsil eden degisken
typedef struct KIMLIKNO* KimlikNo;

//constructor olarak dusunebiliriz
KimlikNo KimlikNoOlustur();
//fonskiyonlar
char* _KimlikNoUret(const KimlikNo);
void _KimlikNokontrolet(struct KIMLIKNO*,char*);
void _yaz(const KimlikNo);
void _kimliknoyoket();
#endif