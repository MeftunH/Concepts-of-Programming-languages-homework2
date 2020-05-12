/**
 *
 * @author
 * Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
 * Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr
 *
 * @since 22/04/2020
 * <p>
 * Rastgele kimlk numarasi uretme ve kontrol etme .c dosyasi
 * </p>
 */
#include "KimlikNo.h"

KimlikNo KimlikNoOlustur()
{
    //oop'e benzemesi icin ImeiNo ile golgeleme islemi yapilmis structurumizi this ile belirtiyoruz
    KimlikNo this;
    this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));//this icin bellekten yer tahsil ediyoruz
    //dizi seklinde tanimaldigimiz degiskenler icin bellekten yer tahsil ediyoruz
    this->tctempdizi = (int *)malloc(sizeof(int) * 12);
    this->tcdizi = malloc(sizeof(char) * 11);
   //constructor olarak dusundugumuz rastgele fonksiyonunu cagiriyoruz  
    this->randomsayisuper = RastgeleOlustur(1, 10);
     //fonskiyonlari ve fonksiyon gostercilerini esitliyoruz
    this->kimliknouret = &_KimlikNoUret;
    this->kimliknokontrolet = &_KimlikNokontrolet;
    this->kimliknoyoket = &_kimliknoyoket;
    this->yaz = &_yaz;
    this->kimliknoyoket = &_kimliknoyoket;
    this->kimliknogecerlicount = 0;
    this->kimliknogecersizcount = 0;
   // en sonda thisi geri donduruyoruz
    return this;
}
char *_KimlikNoUret(const KimlikNo this)
{

    int tc = 0;
    int i;
//dizinin ilk 9 elemanina rastgele fonksiyonunu kullanarak atama yaptim
    for (i = 0; i < 9; i++)
    {
        this->tctempdizi[i] = this->randomsayisuper->uret(this->randomsayisuper);
    }
//tcnin ilk rakaminin 0 olmamasi gerekiyor o yuzden 0 geldigi surece yeni deger uret
    while (this->tctempdizi[0] == 0)
    {
        this->tctempdizi[0] = this->randomsayisuper->uret(this->randomsayisuper);
    }
//tc algoritmasi uygun olarak kimliknumasanin 10 ve 11. basamaklarini urettim
    this->tctempdizi[9] = ((((this->tctempdizi[0] + this->tctempdizi[2] + this->tctempdizi[4] + this->tctempdizi[6] + this->tctempdizi[8]) * 7) - (this->tctempdizi[1] + this->tctempdizi[3] + this->tctempdizi[5] + this->tctempdizi[7])) % 10);
    this->tctempdizi[10] = ((this->tctempdizi[0] + this->tctempdizi[1] + this->tctempdizi[2] + this->tctempdizi[3] + this->tctempdizi[4] + this->tctempdizi[5] + this->tctempdizi[6] + this->tctempdizi[7] + this->tctempdizi[8] + this->tctempdizi[9]) % 10);
    for (int i = 0; i < 11; i++)
    {
        //int dizisini char dizisine donusturuyoruz
        this->tcdizi[i] = (char)this->tctempdizi[i] + 48;
    }
    //diziyi kapatiyoruz
    this->tcdizi[11] = '\0';
    //ve geri donduruyoruz
    return this->tcdizi;
}
void _KimlikNokontrolet(KimlikNo this, char *alinankimlikno)
{
    int i;
    int tcuzunluk;
        //bu dizi,okunan tcnin dogrulugu kontrol etmek icin kullanilacak
//dizi icin bellekten yer aciyoruz
        int *tckimlikhesapladizi = (int *)malloc(sizeof(int) * 11);
//tcnin ilk 9 rakamini dizimize aciyoruz
        for (i = 0; i < 9; i++)
        {
            tckimlikhesapladizi[i] = (int)(alinankimlikno[i] - 48);
        }
//10 ve 11.basamaklarinin dogrulugunu kontrol etmek icin tckimlik algoritmasina uygun sekilde islmeleri yapiyoruz
        tckimlikhesapladizi[9] = ((((tckimlikhesapladizi[0] + tckimlikhesapladizi[2] + tckimlikhesapladizi[4] + tckimlikhesapladizi[6] + tckimlikhesapladizi[8]) * 7) - (tckimlikhesapladizi[1] + tckimlikhesapladizi[3] + tckimlikhesapladizi[5] + tckimlikhesapladizi[7])) % 10);

        tckimlikhesapladizi[10] = ((tckimlikhesapladizi[0] + tckimlikhesapladizi[1] + tckimlikhesapladizi[2] + tckimlikhesapladizi[3] + tckimlikhesapladizi[4] + tckimlikhesapladizi[5] + tckimlikhesapladizi[6] + tckimlikhesapladizi[7] + tckimlikhesapladizi[8] + tckimlikhesapladizi[9]) % 10);

        if (tckimlikhesapladizi[9] == (int)alinankimlikno[9] - 48 && tckimlikhesapladizi[10] == (int)alinankimlikno[10] - 48)
        {
//eger dogruysa sayaci artiracak
            this->kimliknogecerlicount++;
        }
        else
        {
            this->kimliknogecersizcount++;
        }
  
    
}

void _yaz(const KimlikNo this)
{//2.secenek icin ekrana bunlari basmamiza yarayacak
    printf("\nT.C. Kimlik Kontrol\n");
    printf("%d Gecerli\n", this->kimliknogecerlicount);
    printf("%d Gecersiz\n\n", this->kimliknogecersizcount);
}
void _kimliknoyoket(KimlikNo this)
{
    if (this == NULL)
        return;
    
//diziler icin acdigimiz yerleri bellege geri iade ediyoruz
    free(this->tcdizi);

    free(this->tctempdizi);
//randomsayi nesnesi turetmisdik onun yoket metodunu cagirarak onu da iade ediyoruz
    this->randomsayisuper->rasgeleyoket;
    free(this);
}
