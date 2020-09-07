#include "RastgeleKarakter.h"

int main(){
    char ilk = 'a' ,son = 'k' ;
	int adet = 2;
	char dizi[] = {'g','y','u','c','n','e'};
	int adet2 = 6;
    RastgeleKarakter rast = RastgeleKarakterOlustur();
    printf("Rastgele Karakter: %c",rast->RastgeleKarakterr(rast));
	printf("\n");
    printf("Rastgele Karakter: %c",rast->RastgeleKarakterr(rast));
    printf("\n");
    printf("Rastgele 3 karakter: ");
	rast->RastgeleKarakterler(rast,3);
    printf("\n");
    printf("Rastgele 3 karakter: ");
	rast->RastgeleKarakterler(rast,3);
    printf("\n");
    printf("Verilen iki Karakter(%c,%c): %c",ilk,son,rast->VerilenIkiKarakter(rast,ilk,son));
	printf("\n");
	printf("Verilen iki Karakter(%c,%c): %c",ilk,son,rast->VerilenIkiKarakter(rast,ilk,son));
	printf("\n");
	rast->VerilenIkiKarakterler(rast,ilk,son,adet);
    printf("\n");
    printf("%c",rast->BelirtilenKarakter(rast,dizi,adet2));
	printf("\n");
	rast->BelirtilenKarakterler(rast,dizi,adet2,adet);
    printf("\n");
	printf("Cumle: ");
	rast->CumleKur(rast,3,4);
    printf("\n");
	printf("Cumle: ");
	rast->CumleKurmak(rast,3,4,1);
	rast->Yokett(rast);
    return 0;
}