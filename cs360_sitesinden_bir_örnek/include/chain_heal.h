#ifndef CHAIN_HEAL
#define CHAIN_HEAL
    
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node{
    
    int X, Y;
    int cur_PP, max_PP;
    char *name;
    struct node *next;
    int gezme;
    int buyukluk;
    struct node **buyukluk_list;
    int iyilesme_sayisi;
} Node;

int initial_range, jump_range, num_jumps, initial_power = 0;
double power_reduction;

Node *ilk;
Node *simdi;
Node *gecici;

int iyilesme;
Node **iyi_yol;
int **iyilesme_sayisi;

Node **gecici_yol;
int **simdiki_iyilesme;

Node *kontrol1;
Node *kontrol2;

void zincir_iyilestirme(Node*, int, int, int,Node*, int);
int main(int, char**);

#endif  