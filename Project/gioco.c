#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pila_scarti.h"
#include "gioco.h"



bool gioca(List manoG, Scarti s, struct carta cartaATerra) {
    stampaMano(manoG);

    int occr;
    bool giocabile=false;
    printf("\nDigita la posizione della carta da giocare:\n");
    scanf("%d", &occr);

   while (!giocabile) {
    while (occr < 1 || occr > numeroCarteMano(manoG)) {
        printf("posizione errata\n");
        printf("digita la posizione della carta da giocare:\n");
        scanf("%d", &occr);
    }

    struct carta cartaDaGiocare = estraiCarta(manoG, occr);

    if (cartaDaGiocare.num == cartaATerra.num ||
        cartaDaGiocare.colore == cartaATerra.colore ||
        cartaATerra.colore == NEUTRO) {
        giocabile = true;
        pushScarto(s, cartaDaGiocare);
        return false;
    }
    else {
        printf("Carta non giocabile\n");
        aggiungiCarta(manoG, cartaDaGiocare);
        ordinaMano(manoG);

        int draw = 1;
        printf("Se vuoi pescare digita 0, altrimenti un numero qualsiasi:\n");
        scanf("%d", &draw);
        if (draw == 0)
            return true;
    }

    if (!giocabile) {
        printf("Digita la posizione della carta da giocare:\n");
        scanf("%d", &occr);
    }
   }
   return false;
}



void pesca(List manoG,List mazzo){
    struct carta cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
    printf("\ncarta pescata: ");
    stampaCarta(cartaPescata);
}
