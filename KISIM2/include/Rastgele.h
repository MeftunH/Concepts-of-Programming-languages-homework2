/**
*
* @author 
* Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
  Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr

* @since 22/04/2020
* <p>
*Rastgele sayi uretme .h dosyasi
* </p>
*/
#ifndef RASTGELE_H
#define RASTGELE_H
#include "sys/timeb.h"
#include "stdio.h"     //kutuphaneler
#include "stdlib.h"
#include "time.h"
struct RASTGELE
{

   //kullanacagimiz degiskenleri tanimladik
   int rakam;
  int uzunluk;
  int mod;
	 int lfsr;
	int bit;
  //fonskyion gostericelerini tanimladik
   int (*uret)(struct RASTGELE*);
   void(*rasgeleyoket)(struct RASTGELE*);
};
//structun typedef'ini tanimladim ve pointer turettim
typedef struct RASTGELE*Rastgele;
//constructor gorevi gorecek fonskyion
Rastgele RastgeleOlustur(int,int);
//fonksyionlar
int randomuret(const Rastgele);
void _rastgeleyoket(const Rastgele);
#endif