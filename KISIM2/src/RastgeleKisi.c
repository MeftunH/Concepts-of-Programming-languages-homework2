/**
*
* @author 
* Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
  Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr

* @since 22/04/2020
* <p>
*Rastgele kisi uretme .c dosyasi
* </p>
*/
#include "RastgeleKisi.h"
Rastgelekisi RastgeleKisiolustur()
{
//oop'e benzemesi icin Rastgele ile golgeleme islemi yapilmis structurumizi this ile belirtiyoruz
    Rastgelekisi this;
    //this icin bellekten yer tahsil ediyoruz
    this = (Rastgelekisi)malloc(sizeof(struct RASTGELEKISI));
    //fonskyion gostericileriyle fonksiyonlar arasindaki baginti
    this->KisiYaz = &_KisiYaz;
    this->RastgeleKisiUret = &_RastgeleKisiUret;
    this->RastgeleKisiyoket=&_RastgeleKisiYoket;
    //this'i geri donduruyoruz
    return this;
}
void _RastgeleKisiUret(Rastgelekisi this)
{//kullanicidan kac tane kisi uretecegi aliniyor 
    this->deger = 0;
    printf("Kac tane kisi uretilecek?");
    scanf("%d", &this->deger);
}
void _KisiYaz(const Rastgelekisi this)
{
     
    int adet = this->deger;
    //dosyadan temsili pointer olusturduk ve yazma modunda actik her calistiginda dosyaya 0'dan yazacak
    FILE *filepointer;
 filepointer = fopen("Kisiler.txt", "w"); 
    for (int i = 0; i < adet; i++)
    {     
        //aldigimiz deger kadar kisi olusuyor
        this->kisisuper = KisiOlustur(); 
        //dosyaya yazdiriyoruz       
         fprintf(filepointer, "%s %s %d %s (%s) \n",this->kisisuper->kimliknosuper->kimliknouret(this->kisisuper->kimliknosuper),this->kisisuper->isimsoyisimoku(this->kisisuper),this->kisisuper->yas,this->kisisuper->telefonsuper->Telefonnouret(this->kisisuper->telefonsuper),this->kisisuper->telefonsuper->imenosuper->ieminouret(this->kisisuper->telefonsuper->imenosuper));

    }
    //dosyayi kapattik    
    fclose(filepointer);

    
}
void _RastgeleKisiYoket(Rastgelekisi this)
{
    if (this == NULL)
        return;
        //kullanidigmiz kisi pointerinin yoket metodunu cagiriyoruz
       this->kisisuper->kisiyoket;
}