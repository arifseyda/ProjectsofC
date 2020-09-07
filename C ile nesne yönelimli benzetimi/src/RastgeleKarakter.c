#include "RastgeleKarakter.h"

RastgeleKarakter RastgeleKarakterOlustur(){
    RastgeleKarakter this;
	this = (RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));
	this->rastgele = RandomOlustur();

     this->BelirtilenKarakter = &belirtilenKarakter;
     this->BelirtilenKarakterler = &belirtilenKarakterlerr;
    this->BuyukRastgeleKarakter = &buyukRastgeleKarakter;
    this->KucukRastgeleKarakter = &kucukRastgeleKarakter;
    this->RastgeleKarakterler = &rastgeleKarakterler;
    this->RastgeleKarakterr = &rastgeleKarakter;
    this->VerilenIkiKarakter = &verilenIkiKarakter;
    this->VerilenIkiKarakterler = &verilenIkiKarakterler;
	this->CumleKur = &cumleKur;
	this->CumleKurmak = &cumleKurmak;
	this->Yokett = &RastgeleKarakterYoket;
	return this;
}
char rastgeleKarakter(RastgeleKarakter this){
    int sayi = this->rastgele->Uret(this->rastgele,0,123);
	while(1){
		sayi = this->rastgele->Uret(this->rastgele,0,123);
        if(sayi>=(int)'a' && sayi<=(int)'z') break;
        else if (sayi>=(int)'A' && sayi<=(int)'Z') break;
    }
	return (char)sayi%123;
}
char buyukRastgeleKarakter(RastgeleKarakter this){
    int sayi = this->rastgele->Uret(this->rastgele,0,123);
	while(1){
        sayi = this->rastgele->Uret(this->rastgele,0,123);
        if(sayi>=(int)'A' && sayi<=(int)'Z') break;
    }
	return (char)sayi%123;
}
char kucukRastgeleKarakter(RastgeleKarakter this){
    int sayi = this->rastgele->Uret(this->rastgele,0,123);
	while(1){
        sayi = this->rastgele->Uret(this->rastgele,0,123);
        if(sayi>=(int)'a' && sayi<=(int)'z') break;
    }
	return (char)sayi%123;
}
void rastgeleKarakterler(RastgeleKarakter this,int adet){
    char* karakter = malloc(sizeof(char)*adet);
	int i;
	for(i = 0; i < adet; i++)
	{
		karakter[i] = this->RastgeleKarakterr(this);
		printf("%c", karakter[i]);
	}
}
char verilenIkiKarakter(RastgeleKarakter this,char kar1,char kar2){
    int sayi = this->RastgeleKarakterr(this);
	
	while(sayi < (int)kar1 || sayi > (int)kar2){
		sayi = this->RastgeleKarakterr(this);
	}
	return (char)sayi;
}
char verilenIkiKarakterler(RastgeleKarakter this,char kar1,char kar2,int adet){
    char *karakterler = malloc(sizeof(char)*adet);
	int i;
	printf("Verilen iki Karakter(%c,%c): ",kar1,kar2);
	for( i = 0; i < adet; i++)
	{
		karakterler[i] = this->VerilenIkiKarakter(this,kar1,kar2);
		printf("%c", karakterler[i]);
	}	
}
char belirtilenKarakter(RastgeleKarakter this,char dizi[],int uzunluk){
    char *karakterler = malloc(sizeof(char)*uzunluk);
	karakterler = dizi;
	int sayi;
	printf("Belirtilen karakterler(");
    for (int i = 0; i < uzunluk; i++) {
        printf("%c",dizi[i]);
        if (i+1 != uzunluk) {
        	printf(",");
        }
    }
    printf("): ");
	sayi = this->RastgeleKarakterr(this);
	sayi = sayi % uzunluk;
	return dizi[sayi];
}
void belirtilenKarakterlerr(RastgeleKarakter this,char dizi[],int uzunluk,int adet){
    char *karakterler = malloc(sizeof(char)*uzunluk);
	karakterler = dizi;
	int sayi;
	printf("Belirtilen karakterler(");
    for (int i = 0; i < uzunluk; i++) {
        printf("%c",karakterler[i]);
        if (i+1 != uzunluk) {
        	printf(",");
        }
    }
    printf("): ");
	int i;
	for( i = 0; i < adet; i++)
	{
		sayi = this->RastgeleKarakterr(this);
		sayi = sayi % uzunluk;
		printf("%c", dizi[sayi]);
	}
}

void cumleKur(RastgeleKarakter this,int kacHarf,int kacKelime){
	char *kelime = malloc(sizeof(char)*kacHarf);
	int i,j,sayi;
	sayi = this->BuyukRastgeleKarakter(this);
	for(i = 0; i < kacKelime; i++)
	{
		for(j = 0; j < kacHarf; j++){
			if (j==0 && i== 0) {
				sayi = this->BuyukRastgeleKarakter(this);
				kelime[j] = (char)sayi;
				printf("%c", kelime[j]);
			}
			else {
				sayi = this->KucukRastgeleKarakter(this);
				kelime[j] = (char)sayi;
				printf("%c", kelime[j]);
			}
		}
		if (i == kacKelime-1) {
			printf(".");
		}
		
		printf(" ");
		
	}
}
void cumleKurmak(RastgeleKarakter this,int kacHarf,int kacKelime,int kacArttirma){
	char *kelime = malloc(sizeof(char)*kacHarf);
	int i,j,sayi;
	sayi = this->BuyukRastgeleKarakter(this);
	for(i = 0; i < kacKelime; i++)
	{
		for(j = 0; j < kacHarf; j++){
			if (j==0 && i== 0) {
				sayi = this->BuyukRastgeleKarakter(this);
				kelime[j] = (char)sayi;
				printf("%c", kelime[j]);
			}
			else {
				sayi = this->KucukRastgeleKarakter(this);
				kelime[j] = (char)sayi;
				printf("%c", kelime[j]);
			}
		}
		if (i == kacKelime-1) {
			printf(".");
		}
		kacHarf = kacHarf + kacArttirma;
		printf(" ");
		
	}
}
void RastgeleKarakterYoket(RastgeleKarakter this){
	if (this ==NULL) {
		return;
	}
	this->rastgele->Yoket(this->rastgele);
	free(this);
	
}