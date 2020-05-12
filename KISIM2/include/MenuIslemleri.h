/**
*
* @author 
* Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
  Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr

* @since 22/04/2020
* <p>
*Menu islemlerinin tutuldugu .h dosyasi
* </p>
*/

#ifndef MENUISLEMLERI_H
#define MENUISLEMLERI_H
#include "RastgeleKisi.h"
#include <conio.h>
struct MENUISLEMLERI
{
    //degiskenler
int i;
int j;
int k;
//fonksiyonlar
void (*KisiUretMenu)(struct MENUISLEMLERI*);
void (*KisiKontroletMenu)(struct MENUISLEMLERI*);
void (*menuyoket)(struct MENUISLEMLERI*);
};
// MENUISLEMLERI structurini temsil eden degisken
typedef struct MENUISLEMLERI* MenuIslemleri;
//constructor olarak dusunebiliriz
MenuIslemleri MenuOlustur();
void _KisiUretMenu(const MenuIslemleri);
void _KisiKontroletMenu(const MenuIslemleri);
void _menuyoket(const MenuIslemleri);
#endif