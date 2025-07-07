#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pila_scarti.h"

// Creo lo stack degli scarti
Scarti createScarti() {
    Scarti s = (Scarti)malloc(sizeof(struct stack));
    if (s != NULL) {
        s->stack = (struct carta*)malloc(INCREASE_SIZE * sizeof(struct carta));// con s->stack accedo a stack che è un puntatore
        if (s->stack != NULL) {
            s->size = INCREASE_SIZE;
            s->top_index = -1;
        } else {
            free(s);
            s = NULL;
            //printf("\nMemoria non disponibile...\n");
        }
    //else
    //    printf("\nMemoria non disponibile...\n");
    }
    return s;
}

// Aumenta la capacità dello stack
bool increaseScarti(Scarti s) {
    bool increased = false;
    struct carta* temp = (struct carta*)realloc(s->stack, (s->size + INCREASE_SIZE) * sizeof(struct carta));//ridimensionamento s->stack già allocato
    if (temp != NULL) {
        s->stack = temp; //aggiorno il puntatore allo stack
        s->size += INCREASE_SIZE;
        increased = true;
    }
    return increased;
}

// Inserisce una carta nello stack
bool pushScarto(Scarti s, struct carta c) {
    if (s == NULL)
        return false;

    if (s->top_index == s->size - 1) {//se non è disponibile lo spazio per una carta...
        if (!increaseScarti(s))
            return false;
    }

    s->top_index++;
    s->stack[s->top_index] = c;
    return true;
}

// Restituisce la carta in cima senza rimuoverla
struct carta topScarto(Scarti s) {
    struct carta c = { .num = -1, .colore = -1 };
    if (s != NULL && s->top_index >= 0) {//se c'è almeno una carta nella pila
        c = s->stack[s->top_index];
    }
    return c;
}

// Controlla se lo stack è vuoto
bool isEmptyScarti(Scarti s) {
    return (s == NULL || s->top_index == -1);
}

// Stampa tutte le carte nello stack
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
            free(s->stack);  // Libera array di carte
        free(s);             // Libera struttura Scarti
    }
}

