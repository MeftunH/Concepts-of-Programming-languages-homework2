/**
*
* @author 
* Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
  Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr

* @since 22/04/2020
* <p>
*yazdigimiz kutuphaneyi etmek icin kullanilan Test sinifi
* </p>
*/
#include "Telefon.h"

Telefon TelefonOlustur()
{
    //oop'e benzemesi icin Rastgele ile golgeleme islemi yapilmis structurumizi this ile belirtiyoruz
    Telefon this;
      //this icin bellekten yer tahsil ediyoruz
    this = (Telefon)malloc(sizeof(struct TELEFON));
    this->telefondizi = (char *)malloc(sizeof(char) * 11);
     //constructor olarak dusundugumuz rastgele fonksiyonunu cagiriyoruz 
    this->randomsayisuper = RastgeleOlustur(1, 10);
    this->secicisuper = RastgeleOlustur(1, 27);
    this->imenosuper = imeiNoOlustur();
    //fonskyion gostericileriyle fonksiyonlar arasindaki baginti
    this->Telefonnouret = &_Telefonnouret;
this->telyoket=&_telyoket;
//thisi geridonduruyoruz
    return this;
}
char *_Telefonnouret(const Telefon this)
{
//gsm kodlarini tutacak 2d array
    char gsm[27][3]=
    {

{'5', '3', '1'},
{'5', '3', '2'},
{'5', '3', '3'},
{'5', '3', '4'},
{'5', '3', '5'},
{'5', '3', '6'},
{'5', '3', '7'},
{'5', '3', '8'},
{'5', '3', '9'},
{'5', '4', '1'},
{'5', '4', '2'},
{'5', '4', '3'},
{'5', '4', '4'},
{'5', '4', '5'},
{'5', '4', '6'},
{'5', '0', '5'},
{'5', '0', '6'},
{'5', '0', '7'},
{'5', '5', '1'},
{'5', '5', '2'},
{'5', '5', '3'},
{'5', '5', '4'},
{'5', '5', '5'},
{'5', '5', '6'},
{'5', '5', '7'},
{'5', '5', '8'},
{'5', '5', '9'}

    };
    //secici gsm dizisinden rastgele secmemize yariyor
    int secimtemp=this->secicisuper->uret(this->secicisuper);
        this->telefondizi[0] = '0';
        this->telefondizi[1] = gsm[secimtemp][0];
        this->telefondizi[2] = gsm[secimtemp][1];
        this->telefondizi[3] = gsm[secimtemp][2];
        //rastgele sekilde telefon numarasi
        this->telefondizi[4] =(char) this->randomsayisuper->uret(this->randomsayisuper)+48;
        this->telefondizi[5] = (char) this->randomsayisuper->uret(this->randomsayisuper)+48;
        this->telefondizi[6] = (char) this->randomsayisuper->uret(this->randomsayisuper)+48;
        this->telefondizi[7] = (char) this->randomsayisuper->uret(this->randomsayisuper)+48;
        this->telefondizi[8] = (char) this->randomsayisuper->uret(this->randomsayisuper)+48;
        this->telefondizi[9] = (char) this->randomsayisuper->uret(this->randomsayisuper)+48;
        this->telefondizi[10] = (char) this->randomsayisuper->uret(this->randomsayisuper)+48;
        //diziyi kapatmamiz icin
        this->telefondizi[11] = '\0';

//telefon dizisini geridondur
    return this->telefondizi;
 
    
}

void _telyoket(const Telefon this)
{
      if (this == NULL)
        return;
        //kullanidgimiz pointerlari kendi yoket metodlarini cagirarak bellege iade ediyoruz
        free(this->telefondizi);
        free(this->imenosuper->imeiyoket);
        free(this->randomsayisuper->rasgeleyoket);
        free(this->secicisuper->rasgeleyoket);
        free(this);
}