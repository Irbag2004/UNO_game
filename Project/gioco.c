#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pila_scarti.h"
#include "gioco.h"



bool gioca(List manoG, Scarti s, struct carta cartaATerra) {
    stampaMano(manoG);

    int occr;
    bool giocabile=false;
    printf("\nDigita la posizione della carta da giocare...");
    scanf("%d", &occr);

   while (!giocabile) {
    while (occr < 1 || occr > numeroCarteMano(manoG)) {
        printf("posizione errata\n");
        printf("Digita la posizione della carta da giocare...");
        scanf("%d", &occr);
    }

    struct carta cartaDaGiocare = estraiCarta(manoG, occr);

    if (cartaDaGiocare.num == cartaATerra.num ||
        cartaDaGiocare.colore == cartaATerra.colore ||
        cartaATerra.colore == NEUTRO||cartaDaGiocare.colore==NEUTRO) {
        giocabile = true;
        pushScarto(s, cartaDaGiocare);
        return false;
    }
    else {
        printf("Carta non giocabile\n");
        aggiungiCarta(manoG, cartaDaGiocare);
        ordinaMano(manoG);

        int draw = 1;
        printf("Se vuoi pescare o passare digita 0, altrimenti un numero qualsiasi...");
        scanf("%d", &draw);
        if (draw == 0)
            return true;
    }

    if (!giocabile) {
        printf("Digita la posizione della carta da giocare...");
        scanf("%d", &occr);
    }
   }
   return false;
}



void pesca(List manoG,List mazzo){
    struct carta cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
    ordinaMano(manoG);
    printf("\ncarta pescata: ");
    stampaCarta(cartaPescata);
}

void pesca2(List manoG,List mazzo){
    struct carta cartaPescata;
    cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
    cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
    ordinaMano(manoG);
}

void pesca4(List manoG,List mazzo){
    struct carta cartaPescata;
    cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
    cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
    cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
    cartaPescata=RimuoviPrimaCarta(mazzo);
    aggiungiCarta(manoG,cartaPescata);
    ordinaMano(manoG);
}

