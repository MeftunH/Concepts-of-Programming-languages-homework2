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
#include "Kisi.h"
Kisi KisiOlustur()
{
//oop'e benzemesi icin Kisi ile golgeleme islemi yapilmis structurumizi this ile belirtiyoruz
    Kisi this;
    //this icin bellekten yer tahsil ediyoruz
    this = (Kisi)malloc(sizeof(struct KISI));
     //constructor olarak dusundugumuz rastgele fonksiyonunu cagiriyoruz 
    this->kimliknosuper = KimlikNoOlustur();
    this->telefonsuper = TelefonOlustur();
    this->randomsayisuper = RastgeleOlustur(9999, 9999);
    this->randomyassuper = RastgeleOlustur(1, 100);  
 //dizi seklinde tanimaldigimiz degiskenler icin bellekten yer tahsil ediyoruz
    this->isimsoyisim = malloc(sizeof(char) * 1024);
    //yasi rastgele atiyoruz
    this->yas = this->randomyassuper->uret(this->randomyassuper);
    //fonksiyon gostericileri ile fonksiyonlar arasindaki baglantiyi yapiyoruz
    this->isimsoyisimoku = &_isimsoyisimoku;
    this->kisiyoket=&_kisiyoket;
    //en son this'i geri donduruyoruz
    return this;
}

char* _isimsoyisimoku(const Kisi this) {
    int satirsayi = 0;
    int i;
    char* satir;
    char temp[1024];
    int nLines = 0;
//file nesnesi olusturup dosyayi okuma modunda aciyoruz
    FILE* input = fopen("random_isimler.txt", "r");
    satir = fgets(temp, 1024, input); // fgets satir satir okuyor ilk satiri atiyoruz
    while (satir != NULL) {
        satirsayi++;
        satir = fgets(temp, 1024, input); // sonra dosya sonuna kadar atmaya devam ediyoruz
    }
    //dosyayi kapatiyourz
    fclose(input);
//rastgele satir secmek icin
    int RastgeleSayi = this->randomsayisuper->uret(this->randomsayisuper)%satirsayi;
   satir = NULL;
    input = fopen("random_isimler.txt", "r");
    satir = fgets(temp, 1024, input); 
    while (satir != NULL) {
        RastgeleSayi--;
        if (RastgeleSayi == 0) {
            //okuduggumuz satiri isimsoyisme atiyoruz
            strcpy(this->isimsoyisim, satir);
            break;
        }
        satir = fgets(temp, 1024, input); 
    }
    fclose(input);
//rastgele satrimizi aldik ve char dizimizi '\0' ile kapatiyoruz
    this->isimsoyisim[strlen(this->isimsoyisim)-1] = '\0';
    //geri donduruyoruz
        return this->isimsoyisim;
        //cop kalmamasi icin dizileri bellege iade ediyoruz
    free(satir);
    free(temp);
}
void _kisiyoket(Kisi this)
{
      if (this == NULL)
        return;
        free(this->isimsoyisim);
        //kullanidigmiz degiskenleri kendi yoket metodlarini cagirarak yokediyoruz
      this->randomsayisuper->rasgeleyoket;
        this->randomyassuper->rasgeleyoket;
        this->telefonsuper->telyoket;
        this->kimliknosuper->kimliknoyoket;
        //sonda nesneyi yokediyoruz
        free(this);
}