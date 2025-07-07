#ifndef PILA_SCARTI_H
#define PILA_SCARTI_H

#include <stdbool.h>
#include "mazzo.h"  // per la definizione di struct carta

#define INCREASE_SIZE 1

// Definizione della struttura stack per le carte scartate
typedef struct stack {
    struct carta* stack;
    int size;
    int top_index;
} *Scarti;

// Funzioni per la gestione dello stack
Scarti createScarti();
bool increaseScarti(Scarti s);
bool pushScarto(Scarti s, struct carta c);
struct carta topScarto(Scarti s);
bool isEmptyScarti(Scarti s);
void printScarti(Scarti s);
void destroyScarti(Scarti s);

#endif // PILA_SCARTI_H
