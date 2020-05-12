/**
 *
 * @author
 * Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
 * Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr
 *
 * @since 22/04/2020
 * <p>
 * Rastgele imei uretme ve kontrol etme .c dosyasi
 * </p>
 */
#include "IMEINo.h"
ImeiNo imeiNoOlustur()
{
    //oop'e benzemesi icin ImeiNo ile golgeleme islemi yapilmis structurumizi this ile belirtiyoruz
    ImeiNo this;
    this = (ImeiNo)malloc(sizeof(struct IMEINO)); //this icin bellekten yer tahsil ediyoruz
                                                  //dizi seklinde tanimaldigimiz degiskenler icin bellekten yer tahsil ediyoruz
    this->imeinodizi = (int *)malloc(sizeof(int) * 15);
    this->imeinochardizi = (char *)malloc(sizeof(char) * 16);
    this->temp = (int *)malloc(sizeof(int) * 15);
    //constructor olarak dusundugumuz rastgele fonksiyonunu cagiriyoruz
    this->randomsayisuper = RastgeleOlustur(1, 10);
    //fonskiyonlari ve fonksiyon gostercilerini esitliyoruz
    this->ieminouret = &_ImeiNoUret;
    this->imeiyaz = &_imeiyaz;
    this->imeikontrolet = &_ImeiNoKontrolet;
    this->imeiyoket = &_imeiyoket;
    //degiskenlerimize atama yapiyoruz
    this->imeinogecerlicount = 0;
    this->imeinogecersizcount = 0;
    this->toplam = 0;
    this->toplam1 = 0;
    this->toplam2 = 0;
    this->toplam3 = 0;
    this->katdeger = 0;
    // en sonda thisi geri donduruyoruz
    return this;
}
char *_ImeiNoUret(const ImeiNo this)
{
    int i;
    //ilk 13 rakam rastgele uretilecegi icin
    for (i = 0; i <= 13; i++)
    {
        this->imeinodizi[i] = this->randomsayisuper->uret(this->randomsayisuper);
        //imeino uretme algoritmasina uygun olarak dizilerimizi tanimliyoruz.
        //Algortimada 2ye carpilanlar oldugu icin onlari baska dizide tutmanin daha iyi olduguna karar verdik
        if (i % 2 == 1)
        {
            //tek hanelileri 2yle carpiyoruz
            this->temp[i] = 2 * this->imeinodizi[i];

            if (this->temp[i] < 10)
            {
                //dizideki deger 10 dan kucukse toplamini aliyoruz
                this->toplam1 += this->temp[i];
            }
            //10 dan buyukse 10'a gore modunu alip toplama islemini yapiyoruz
            else if (this->temp[i] >= 10)
            {

                this->temp[i] = (1 + (this->temp[i] % 10));
                this->toplam2 += this->temp[i];
            }
        }
        //dizideki cift basamaklilarin toplamini almak icin

        if (i % 2 == 0)
        {
            this->toplam3 += this->imeinodizi[i];
        }
    }
    this->toplam = this->toplam1 + this->toplam2 + this->toplam3;
    //14 basamagin toplaminin modu 0'a esitse zaten 15.basamak 0 olacagi icin
    if ((this->toplam % 10) == 0)
    {
        this->imeinodizi[14] = 0;
    }
    else
    {
        this->katdeger = ((this->toplam / 10) + 1) * 10;
        this->imeinodizi[14] = this->katdeger - this->toplam;
    }
    for (int i = 0; i < 15; i++)
    {
        //aldigimiz imei dizisini char'a donusturuyoruz
        this->imeinochardizi[i] = (char)this->imeinodizi[i] + 48;
    }
    //en sonda kapatiyoruz
    this->imeinochardizi[15] = '\0';
    //ve geri donduruyoruz
    return this->imeinochardizi;
}

void _ImeiNoKontrolet(const ImeiNo this, char *alinanimeino)
{

    this->toplam = 0;
    this->toplam1 = 0;
    this->toplam2 = 0;
    this->toplam3 = 0;
    this->katdeger = 0;
    //ilk 14 rakami aliyoruz
    for (int i = 0; i <= 13; i++)
    {
        this->imeinodizi[i] = (int)alinanimeino[i];
        //imeino algroitmasina gore indexi cift rakma olanlar 2'yle carpilacagi icin onlari baska bir idizide tutuyoruz
        //imei algoritmasi islmelerini yapiyoruz
        //daha detayli gormek icin rapora gozata bilirsiniz

        if (i % 2 == 1)
        {

            this->temp[i] = 2 * this->imeinodizi[i];
            //10'dan kucukse elelmanlarin toplamini aliyoruz
            if (this->temp[i] < 10)
            {
                this->toplam1 += this->temp[i];
            }
            //10'dan buyukse 10'a gore moduna alip sonra t elemanlarin toplamini aliyoruz
            else if (this->temp[i] >= 10)
            {

                this->temp[i] = (1 + (this->temp[i] % 10));
                this->toplam2 += this->temp[i];
            }
        }
        //tek hanede duranlarin toplamini aliyoruz
        if (i % 2 == 0)
        {
            this->toplam3 += this->imeinodizi[i];
        }
    }
    this->toplam = this->toplam1 + this->toplam2 + this->toplam3;
    //toplamin 10'a gore modu 0'sa zaten 15.hane 0 olacagi icin

    if ((this->toplam % 10) == 0)
    {
        this->imeinodizi[14] = 0;
    }
    else
    {
        //katdeger dedigimiz sey,iemi algoritmasinda bundan onceki  islemlere uygun olarak aldgimiz toplam degerinin 10'luk olarak bir ust katdegerini almak
        //Mesela hesaplamalarimiza gore toplam deger 57 ciktiysa katdeger 60 olacak
        //katdegeri tam olarak burada devreye giriyor

        this->katdeger = ((this->toplam / 10) + 1) * 10;
        //LUHN algoritmasinin son islemi olarak,katdegerle toplam degerinin farkini alarak 15. basamagi buluyoruz

        this->imeinodizi[14] = this->katdeger - this->toplam;
    }
    //Burada okunan degerin bizim hesaplamamiza uyup uymamasini kontrol ediyoruz

    if (this->imeinodizi[14] == (int)alinanimeino[14])
    {
        this->imeinogecerlicount++;
    }
    else
    {
        this->imeinogecersizcount++;
    }
}

void _imeiyaz(const ImeiNo this)
{
    //Menuye yazmak icin kullanilacak
    printf("IMEI Kontrol\n");
    printf("%d Gecerli\n", this->imeinogecerlicount);
    printf("%d Gecersiz\n", this->imeinogecersizcount);
}
void _imeiyoket(ImeiNo this)
{
    if (this == NULL)
        return;
    //bellekten yer tahsil ettigimiz degiskenleri iade ediyoruz
    free(this->imeinochardizi);
    free(this->imeinodizi);
    free(this->temp);
    this->randomsayisuper->rasgeleyoket;
    free(this);
}