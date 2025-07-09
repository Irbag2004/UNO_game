#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pila_scarti.h"

Scarti createScarti() {
    Scarti s = (Scarti)malloc(sizeof(struct stack));
    if (s != NULL) {
        s->stack = (struct carta*)malloc(INCREASE_SIZE * sizeof(struct carta));// con s->stack accedo a stack che è un puntatore
        if (s->stack != NULL) {//if((*s).stack !=NULL)
            s->size = INCREASE_SIZE;
            s->top_index = -1;
        }
        else {
            free(s);
            s = NULL;
            printf("\nMemoria non disponibile...\n");
        }
    }
    else
        printf("\nMemoria non disponibile...\n");

    return s;
}


bool increaseScarti(Scarti s) {//aumenta la dimensione della pila degli scarti
    bool increased = false;
    struct carta* temp = (struct carta*)realloc(s->stack, (s->size + INCREASE_SIZE) * sizeof(struct carta));//ridimensionamento s->stack già allocato
    if (temp != NULL) {
        s->stack = temp; //aggiorno il puntatore allo stack
        s->size += INCREASE_SIZE;
        increased = true;
    }
    return increased;
}


void pushScarto(Scarti s, struct carta c) {//inserisco un elemento in testa allo stack
    if (s == NULL)
        printf("errore");

    if (s->top_index == s->size - 1) {//se non è disponibile lo spazio per una carta...
        if (!increaseScarti(s))
            printf("errore");
    }

    s->top_index++;
    s->stack[s->top_index] = c;
}


struct carta topScarto(Scarti s) {//visualizzo la prima carta senza estrarla dalla pila
    struct carta c = { .num = -1, .colore = -1 };
    if (s != NULL && s->top_index >= 0) {//se c'è almeno una carta nella pila
        c = s->stack[s->top_index];
    }
    return c;
}


bool isEmptyScarti(Scarti s) {
    return (s == NULL || s->top_index == -1);
}


void printScarti(Scarti s) {
    if (s == NULL || isEmptyScarti(s)) {
        printf("[Pila scarti vuota]\n");
        return;
    }

    printf("Pila degli scarti:\n");
    for (int i = s->top_index; i >= 0; i--) {
        struct carta c = s->stack[i];
        printf("Carta: numero = %d, colore = %d\n", c.num, c.colore);
    }

}

void destroyScarti(Scarti s) {
    if (s != NULL) {
        if (s->stack != NULL)
            free(s->stack);
        free(s);
    }
}





