#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H

#include "Random.h"

struct RASTGELEKARAKTER{
	
	Random rastgele;
    
    char (*RastgeleKarakterr)(struct RASTGELEKARAKTER*);
    char (*BuyukRastgeleKarakter)(struct RASTGELEKARAKTER*);
    char (*KucukRastgeleKarakter)(struct RASTGELEKARAKTER*);
    void (*RastgeleKarakterler)(struct RASTGELEKARAKTER*,int);
    char (*VerilenIkiKarakter)(struct RASTGELEKARAKTER*,char,char);
    char (*VerilenIkiKarakterler)(struct RASTGELEKARAKTER*,char,char,int);
    char (*BelirtilenKarakter)(struct RASTGELEKARAKTER*,char[],int);
    void (*BelirtilenKarakterler)(struct RASTGELEKARAKTER*,char[],int,int);
    void (*CumleKur)(struct RASTGELEKARAKTER*,int,int);
    void (*CumleKurmak)(struct RASTGELEKARAKTER*,int,int,int);
    void (*Yokett)(struct RASTGELEKARAKTER*);

};

typedef struct RASTGELEKARAKTER* RastgeleKarakter;

RastgeleKarakter RastgeleKarakterOlustur();
char rastgeleKarakter(RastgeleKarakter);
char buyukRastgeleKarakter(RastgeleKarakter);
char kucukRastgeleKarakter(RastgeleKarakter);
void rastgeleKarakterler(RastgeleKarakter,int);
char verilenIkiKarakter(RastgeleKarakter,char,char);
char verilenIkiKarakterler(RastgeleKarakter,char,char,int);
char belirtilenKarakter(RastgeleKarakter,char[],int);
void belirtilenKarakterlerr(RastgeleKarakter,char[],int,int);
void cumleKur(RastgeleKarakter,int,int);
void cumleKurmak(RastgeleKarakter,int,int,int);
void RastgeleKarakterYoket(RastgeleKarakter);
#endif