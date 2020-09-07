#include "Random.h"

Random RandomOlustur(){
    Random this;
    this = (Random)malloc(sizeof(struct RANDOM));
    this->adresleme = 0xACE1u;
    this->bityardim = 0;
    this->bit = 0x00000;

    this->Yoket = &RandomYoket;
    this->Uret = &RandomUret;
    return this;
}

unsigned int RandomUret(const Random this,unsigned int baslangic,unsigned int son)
{
    if(baslangic == son) return baslangic;
    int *p = malloc(sizeof(int));
    this->bityardim = this->bityardim^(int)p;
    this->bit  = ((this->adresleme >> 0) ^ (this->adresleme >> 2) ^ (this->adresleme >> 3) ^ (this->adresleme >> 5) ) & 1;
    this->adresleme = ((this->bit<<15) | (this->adresleme>>1) | this->bityardim)%son;
    while(this->adresleme<baslangic){
       this->adresleme = this->adresleme + son - baslangic;
    }
    return this->adresleme;
}
void RandomYoket(Random this){
	if(this == NULL) return;
	free(this);
	this = NULL;
}