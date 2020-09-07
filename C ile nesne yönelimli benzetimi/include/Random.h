#ifndef RANDOM_H
#define RANDOM_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"


struct RANDOM
{
    unsigned int adresleme;
    unsigned int bit,bityardim;

    unsigned int (*Uret)(struct RANDOM*,unsigned int,unsigned int);
    void (*Yoket)(struct RANDOM*);
};

typedef struct RANDOM* Random;

Random RandomOlustur();
unsigned int RandomUret(Random, unsigned int, unsigned int);
void RandomYoket(Random);
#endif