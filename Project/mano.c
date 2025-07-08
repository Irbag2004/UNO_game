#include <stdio.h>
#include <stdlib.h>
#include "mano.h"


const char* ColoreName[] ={"B", "G", "R", "V","N"};
const char* NumeroName[] ={"0","1", "2", "3", "4", "5", "6", "7", "8", "9", "X","<->", "+2", "CC","+4"};


// Aggiunge una carta in testa alla mano
bool aggiungiCarta(List mano, struct carta c) {
    if (mano == NULL) return false;

    Node nuovo = (Node)malloc(sizeof(struct node));
    if (nuovo == NULL) return false;

    nuovo->card = c;
    nuovo->next = mano->head;
    mano->head = nuovo;
    return true;
}


//rimuove la carta richiesta dalla mano, pronta per essere giocata
struct carta estraiCarta(List mano, struct carta daCercare) {
    struct carta c = { .num = -1, .colore = -1 };

    if (mano == NULL || mano->head == NULL)
        return c;

    Node curr = mano->head;
    Node prev = NULL;   //la carta precedente alla prima non puo esistere

    while (curr != NULL) {
        if (curr->card.num == daCercare.num && curr->card.colore == daCercare.colore) {
            c = curr->card;

            if (prev == NULL)
                mano->head = curr->next;    //aggiorno la testa della mano
            else
                prev->next = curr->next;    //aggiorno il puntatore precedente

        free(curr); //se la carta è stata trovata , la rimuovo dalla mano
        return c;
        }
        prev = curr;    //scorro la lista mano
        curr = curr->next;
    }

    return c;   // Restituisce carta "vuota" se non trovata
    printf("la carta non è presente nella mano");
}


void stampaMano(List mano) {
    if (mano == NULL || mano->head == NULL) {
        printf("[Mano vuota]\n");
        return;
    }

    Node curr = mano->head;
    printf("Carte in mano:\n");
    while (curr != NULL) {
        stampaCarta(curr->card);
        curr = curr->next;
    }
    printf("\n");
}

bool manoVuota(List mano) {
    return (mano == NULL || mano->head == NULL);
}


int numeroCarteMano(List mano) {
    int count = 0;
    Node curr = mano->head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}


void ordinaMano(List mano) {
    if (mano == NULL || mano->head == NULL) return;

    bool ordinato = false;
    Node ptr;
    struct carta temp;

    while (!ordinato) {
        ordinato = true;
        ptr = mano->head;

        while (ptr != NULL && ptr->next != NULL) {

            if (ptr->card.colore > ptr->next->card.colore ||
    (ptr->card.colore == ptr->next->card.colore && ptr->card.num > ptr->next->card.num)){
                temp = ptr->card;
                ptr->card = ptr->next->card;
                ptr->next->card = temp;
                ordinato = false;
            }
            ptr = ptr->next;
        }
    }
}
