    #include "chain_heal.h"

    void zincir_iyilestirme(Node* node, int hop, int ziplama_sayisi, int total_iyilesme_sayisi, Node* from,int kose_dizisi)
    {

        int needed_iyilesme_sayisi;
        int reset_init_power = initial_power;

        if(node->gezme == 1 || hop>ziplama_sayisi){
            node->gezme = 0;
            return;
        }
        int count;

        gecici_yol[kose_dizisi] = node;

        if(kose_dizisi == ziplama_sayisi-1){
            int loop_C;
            for(loop_C = 0; loop_C<ziplama_sayisi;loop_C++){

                printf("%s", gecici_yol[loop_C]->name);
                needed_iyilesme_sayisi = gecici_yol[loop_C]->max_PP - gecici_yol[loop_C]->cur_PP;
                if(needed_iyilesme_sayisi<initial_power)
                    gecici_yol[loop_C]->iyilesme_sayisi = needed_iyilesme_sayisi;
                else
                    gecici_yol[loop_C]->iyilesme_sayisi = rint(initial_power);

                initial_power = initial_power * (1-power_reduction);
                total_iyilesme_sayisi = total_iyilesme_sayisi + gecici_yol[loop_C]->iyilesme_sayisi;
                simdiki_iyilesme[loop_C] = gecici_yol[loop_C]->iyilesme_sayisi;
                printf(" %d \n", simdiki_iyilesme[loop_C]);
            }
            int dupC;
            int dupC2;
            for(dupC=0; dupC<ziplama_sayisi-1;dupC++){
                for(dupC2=dupC+1;dupC2<ziplama_sayisi;dupC2++){
                    kontrol1 = gecici_yol[dupC];
                    kontrol2 = gecici_yol[dupC2];
                    if(kontrol1 == kontrol2)
                        total_iyilesme_sayisi = 0;
                    }
            }
            initial_power = reset_init_power;

            int x;
            if(total_iyilesme_sayisi>iyilesme){

                iyilesme = total_iyilesme_sayisi;
                for(x=0;x<ziplama_sayisi;x++){
                    iyi_yol[x]=gecici_yol[x];
                    iyilesme_sayisi[x]=simdiki_iyilesme[x];
                }
            }
        }
        for(count = 0; count<node->buyukluk; count++){
        node->gezme = 1;

        zincir_iyilestirme(node->buyukluk_list[count], hop+1, ziplama_sayisi,total_iyilesme_sayisi,node->next,kose_dizisi+1);
        }
    }


    int main(int argc, char **argv){

        ilk = (Node*) malloc(sizeof(Node));
        simdi = (Node*) malloc(sizeof(Node));
        ilk = NULL;

        int x, y, cur_PP, max_PP;
        char *name = malloc(sizeof(char) * 100);

        initial_range = atoi(argv[1]);
        jump_range = atoi(argv[2]);
        num_jumps = atoi(argv[3]);
        initial_power = atoi(argv[4]);
        power_reduction = atof(argv[5]);

        char *dosya = argv[6];
        FILE *f = fopen(dosya,"r");
        int dugum_sayisi = 0;

            while (fscanf(f, "%d %d %d %d %s", &x, &y, &cur_PP, &max_PP, name) != EOF){

            gecici = (Node*) malloc(sizeof(Node));
            gecici->X = x;
            gecici->Y = y;
            gecici->cur_PP = cur_PP;
            gecici->max_PP = max_PP;
            gecici->name = malloc(sizeof(char) * 100);
            strcpy(gecici->name, name);

            if(dugum_sayisi <= 0){
                ilk = gecici;
                ilk->next = NULL;
                simdi = ilk;
            }else{
                simdi->next = gecici;
                simdi = gecici;
                simdi->next = NULL;
            }

            dugum_sayisi++;
        }

            fclose(f);


        simdi = ilk;
        int looper = 0;
        Node *dis_simdi = (Node*) malloc(sizeof(Node));
        Node *ic_simdi = (Node*) malloc(sizeof(Node));

        dis_simdi = ilk;


        while(dis_simdi){
            int adj_counter = 0;
            ic_simdi = ilk;


            while(ic_simdi ){

                if( dis_simdi != ic_simdi){
                if(sqrt(((dis_simdi->X - ic_simdi->X)*(dis_simdi->X - ic_simdi->X)) + ((dis_simdi->Y - ic_simdi->Y)*(dis_simdi->Y
                    - ic_simdi->Y))) <= jump_range){
                    adj_counter++;
                }
            }

                ic_simdi = ic_simdi->next;
            }

            dis_simdi->buyukluk = adj_counter;
            dis_simdi = dis_simdi->next;
        }
        dis_simdi = ilk;

        while(dis_simdi){
            dis_simdi->buyukluk_list = (Node**)malloc(sizeof(Node*) * dis_simdi->buyukluk);
            int index_counter = 0;
            ic_simdi = ilk;


            while(ic_simdi){

                    if(dis_simdi == ilk){

                    }

                if( dis_simdi != ic_simdi){
                    if(sqrt(((dis_simdi->X - ic_simdi->X)*(dis_simdi->X - ic_simdi->X)) + ((dis_simdi->Y -
                    ic_simdi->Y)*(dis_simdi->Y - ic_simdi->Y))) <= jump_range){
                        dis_simdi->buyukluk_list[index_counter++]=ic_simdi;
                    }
                }

                ic_simdi = ic_simdi->next;
            }
            dis_simdi = dis_simdi->next;
        }


        gecici_yol = (Node**)malloc(sizeof(Node*) * num_jumps);
        simdiki_iyilesme =  (int**)malloc(sizeof(int*) * num_jumps);

        iyi_yol = (Node**)malloc(sizeof(Node*) * num_jumps);
        iyilesme_sayisi =   (int**)malloc(sizeof(int*)*num_jumps);

        kontrol1 = (Node*) malloc(sizeof(Node));
        kontrol2 = (Node*) malloc(sizeof(Node));

        iyilesme = 0;

        int counter;
        simdi = ilk;

        for(counter = 0; counter<dugum_sayisi; counter++){
                if(sqrt(((ilk->X - simdi->X)*(ilk->X - simdi->X)) +
                        ((ilk->Y - simdi->Y)*(ilk->Y - simdi->Y))) <= initial_range){
                            zincir_iyilestirme(simdi, 1, num_jumps,0, NULL,0);
                            simdi = simdi->next;

            }
        }

        int cX=0;
        printf("\nTotal_iyileşme: %d", iyilesme);
        printf("\n");
        return 0;
    }   