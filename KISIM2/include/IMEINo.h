/**
 *
 * @author
 * Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
 * Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr
 *
 * @since 22/04/2020
 * <p>
 * Rastgele imei uretme ve kontrol etme .h dosyasi
 * </p>
 */
#ifndef IMEINO_H
#define IMEINO_H
#include "Rastgele.h"
struct IMEINO
{
//dizileri tanimladik
int*imeinodizi;
char*imeinochardizi;
//oop'e benzemesi icin nesne gibi dusunebilecegimiz degiskenleri turettik
Rastgele randomsayisuper;
//fonksiyon gostericileri
char*(*ieminouret)(struct IMEINO*);
void (*imeiyaz)(struct IMEINO*);
void (*imeikontrolet)(struct IMEINO*,char*);
void (*imeiyoket)(struct IMEINO*);
//degiskenler
int*temp;
int imeinogecerlicount;
int imeinogecersizcount;
 int toplam;
 int toplam1;
 int toplam2;
 int toplam3;
 int katdeger;
};
//struct IMEI'yi temsil eden degisken
typedef struct IMEINO* ImeiNo;
ImeiNo imeiNoOlustur();
char* _ImeiNoUret(const ImeiNo);
void _imeiyaz(const ImeiNo);
void _ImeiNoKontrolet(const ImeiNo,char*);
void _imeiyoket(const ImeiNo);

#endif