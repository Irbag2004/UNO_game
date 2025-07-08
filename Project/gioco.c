#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pila_scarti.h"




bool gioca(List manoG,Scarti s,struct carta cartaATerra){
    stampaMano(manoG);
                        int occr;
                        printf("\ndigita la posizione della carta da giocare all'interno della mano:\n");
                        scanf("%d",&occr);
                        bool giocabile=false;
                        struct carta cartaDaGiocare;
                        while(!giocabile){
                            while((occr<1||occr>numeroCarteMano(manoG))){
                                printf("posizione errata");
                                printf("\ndigita la posizione della carta da giocare all'interno della mano:\n");
                                scanf("%d",&occr);
                            }
                            cartaDaGiocare=estraiCarta(manoG,occr);
                            if(cartaDaGiocare.num==cartaATerra.num||cartaDaGiocare.colore==cartaATerra.colore||cartaATerra.colore==NEUTRO)
                                break;
                            printf("carta non giocabile\n");

                            printf("se vuoi pescare digita 1 altrimenti 0\n");
                            int draw;
                            scanf("%d",&draw);
                            if(draw==1)
                                return true;

                            printf("\ndigita la posizione della carta da giocare all'interno della mano:\n");
                            scanf("%d",&occr);
                        }
                        pushScarto(s,cartaDaGiocare);
                        return false;
}


void pesca(List manoG,List mazzo){
    struct carta cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
}
