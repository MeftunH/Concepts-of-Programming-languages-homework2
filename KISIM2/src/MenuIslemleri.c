/**
*
* @author 
* Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
  Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr

* @since 22/04/2020
* <p>
*Menu islemlerinin tutuldugu .c dosyasi
* </p>
*/
#include "MenuIslemleri.h"
MenuIslemleri MenuOlustur()
{
  //oop'e benzemesi icin Kisi ile golgeleme islemi yapilmis structurumizi this ile belirtiyoruz
  MenuIslemleri this;
    //this icin bellekten yer tahsil ediyoruz
   this = (MenuIslemleri)malloc(sizeof(struct MENUISLEMLERI));
   //fonksiyon gostericleri ve fonksiyonlar arasindaki baginti
  this->KisiUretMenu=&_KisiUretMenu;
  this->KisiKontroletMenu=&_KisiKontroletMenu;
  this->menuyoket=&_menuyoket;
   //en son this'i geri donduruyoruz
  return this;
}
void _KisiUretMenu(const MenuIslemleri this)
{
  //oop'e benzemesi icin RastgeleKisi ile golgeleme islemi yapilmis structurumizi rastgelekisisuper ile belirtiyoruz
      Rastgelekisi rastgeleKisisuper;
      //constructor gibi dusundugumuz fonksiyonu cagiriyoruz
      rastgeleKisisuper = RastgeleKisiolustur();
      //kisiureti cagiriyoruz.Kisilerimiz uretiliyor
      rastgeleKisisuper->RastgeleKisiUret(rastgeleKisisuper);
      //dosyaya yaziyoruz
      rastgeleKisisuper->KisiYaz(rastgeleKisisuper);
      //copleri temizliyoruz
      rastgeleKisisuper->RastgeleKisiyoket(rastgeleKisisuper);
}
void _KisiKontroletMenu(const MenuIslemleri this)
{
  //oop'e benzemesi icin RastgeleKisi ile golgeleme islemi yapilmis structurumlarizi belirtiyoruz
    //constructor gibi dusundugumuz fonksiyonu cagiriyoruz
   Telefon telefonsuper = TelefonOlustur();
      KimlikNo kimliknosuper = KimlikNoOlustur();
      //degiskenleri tanimliyoruz
      char *line, *kelime, *tcdizi, *imei, *telefon;
      int wordcounter = 0, linecounter = 0, tcdizisirasi = 0, imeisirasi = 0;
//file pointerini olusuturup dosyayi yazma modunda ac diyoruz
      FILE *file = fopen("Kisiler.txt", "r");
      char dizi[1024];
      //okudugumuz dosyayi satir satir ayirip line degiskenine atiyoruz
      line = fgets(dizi, 1024, file);
//dizileri tanimliyoruz
      kelime = (char *)malloc(sizeof(char) * 1024);
      tcdizi = (char *)malloc(sizeof(char) * 11);
      imei = (char *)malloc(sizeof(char) * 15);
      while (line != NULL)
      {
        //satir sonuna kadar taramamizi sagliyor
        for (this->i = 0; this->i < strlen(line); this->i++)
        {
          //eger bosluga denk gelirse artir
          if (line[this->i] == ' ')
          {
            wordcounter++;
            

            if (wordcounter == 1)
            {
              //ilk kelime tc numarasi oldugu icin aliyoruz
              //bu tcnin uzun oldugu durumda kimlik kontrole girmiyor.Gecersiz kimlik counterini arttiriyor
              if(line[11]==' ')
              kimliknosuper->kimliknokontrolet(kimliknosuper, tcdizi);
              else
              {
                kimliknosuper->kimliknogecersizcount++;
              }
              tcdizisirasi = 0;
            }
          }
          else
          {
            //dizisirasini 0ladigimiz icin  bastan saymaya basliyor
            if (wordcounter == 0)
            {
              
              tcdizi[tcdizisirasi] = line[this->i];
              tcdizisirasi++;
            }
//imeiyi tespit etmek icin
            if (line[this->i] == '(')
            {
              if (wordcounter == 5)
              {
                imeisirasi = this->i;
              }
            }
//imei 15 rakamdan olustugu icin.Bunu daha sonra parantez kapanisini bulmak icin kullanicagiz
            int imeiuzunluk = imeisirasi + 16;

            if (strlen(line) == this->i + 1)
            {
              //imei 15 rakamdan uzun oldugunda gecerli sayilmamasi ve tespit edilmesi icin yazdigimiz blok
              if (line[imeiuzunluk] == ')')
              {
                int temp = 0;

                for (this->j = imeisirasi + 1; this->j < imeiuzunluk; this->j++)
                { // imei bilgimizi aliyoruz
                  imei[temp] = line[this->j] - '0';
                  temp++;
                }
//eger imeinin uznlugu normalse kontrol metoduna yonlediriliyor
                telefonsuper->imenosuper->imeikontrolet(telefonsuper->imenosuper, imei);
              }
              else
              {
                //degilse gecerisz
                telefonsuper->imenosuper->imeinogecersizcount++;
              }
            }
          }
        }

        wordcounter = 0;
        //satir sayacini arttir
        linecounter++;
        line = fgets(dizi, 1024, file);
      }
//gecerli geceriszi yazmak icin siniflarinda tanimladigimiz fonksiyonlari cagirdik
      kimliknosuper->yaz(kimliknosuper);
      telefonsuper->imenosuper->imeiyaz(telefonsuper->imenosuper);
      //kullandigimiz dizileri bellege iade ediyoruz
      free(kelime);
      free(tcdizi);
      free(imei);
      kimliknosuper->kimliknoyoket(kimliknosuper);
      telefonsuper->imenosuper->imeiyoket(telefonsuper->imenosuper);
}
void _menuyoket(const MenuIslemleri this)
{
free(this);
}