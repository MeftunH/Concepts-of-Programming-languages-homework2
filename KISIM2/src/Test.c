#include "MenuIslemleri.h"
int main()
{
 //oop'e benzemesi icin MenuIslemleri ile golgeleme islemi yapilmis structurumizi menu ile belirtiyoruz
 //ve consturctor olarak dusundugumuz
MenuIslemleri menu;
menu=MenuOlustur();   
  int tercih;
  do
  {
    printf("\n1. Rastgele Kisi Uret\n");
    printf("2. Dosyayi Kontrol Et\n");
    printf("3. Cikis");
    printf("\n Seciminizi giriniz \n");
//tercihin yapilmasi icin
    scanf("%d", &tercih);
  
switch(tercih)
{
    case 1:
    //1.tercih secilirse menunun kisiuretme fonnksiyonu calisacak
  menu->KisiUretMenu(menu);
    break;
    case 2:
    //2.tercih secilirse menunun kisiuretme fonnksiyonu calisacak
     menu->KisiKontroletMenu(menu);
   break;
    }

  } while (tercih != 3);//3.secilmeyene kadar menu cikmaya devam edecek
//sonda olusturugumuz pointeri ve kullandigiimiz alani bellege iade ediyoruz
menu->menuyoket(menu);
}

