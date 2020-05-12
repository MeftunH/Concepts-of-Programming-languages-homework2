/**
*
* @author 
* Maftun Hashimli maftun.hashimli@ogr.sakarya.edu.tr
  Muhammed Mustafa Çelik   muhammed.celik6@ogr.sakarya.edu.tr

* @since 22/04/2020
* <p>
*Rastgele sayi uretme .c dosyasi
* </p>
*/
#include "Rastgele.h"

Rastgele RastgeleOlustur(int uzunluk, int mod)
{
    //oop'e benzemesi icin Rastgele ile golgeleme islemi yapilmis structurumizi this ile belirtiyoruz
    Rastgele this;
    //this icin bellekten yer tahsil ediyoruz
    this = (Rastgele)malloc(sizeof(struct RASTGELE));
    //degiskenler
    this->uzunluk = uzunluk;
    this->mod=mod;
    this->lfsr = 0xACE1u;
    this->bit ^= (this->lfsr ^ this->uzunluk);
    //fonskyion gostericileriyle fonksiyonlar arasindaki baginti
    this->uret = &randomuret;
    this->rasgeleyoket=&_rastgeleyoket;
    //thisi geridondur
    return this;
}
//o anki  zmaani almabilmemiz icin struct
int system_clock()
{
    
    clock_t t1;
    t1 = clock();
    return t1;
}
int randomuret(const Rastgele this)
{
//daha hassas zamani kullanabilmemiz icin
    struct timeb time;
    ftime(&time);

        for (int i = 0; i < this->uzunluk; i++)
        {
            this->bit ^= (this->lfsr - i) ^ i ^ 1000 ^ i / this->bit;
            this->lfsr = (this->lfsr >> 1) | (this->bit << 15);
            this->rakam = (this->bit^16+this->bit^14+this->bit^13*this->lfsr ^ (unsigned)system_clock() ^ this->lfsr / this->bit * this->lfsr / this->bit ^ this->lfsr ^ 100 ^ this->bit * (this->lfsr * time.millitm * this->lfsr / this->bit ^ this->lfsr ^ 100 ^ this->bit)) % this->mod;
    }  
    return this->rakam;
}
//yoketme metodu 
void _rastgeleyoket( Rastgele this)
{
    
   if(this == NULL) return;
	free(this);
    
}