#ifndef PILA_SCARTI_H
#define PILA_SCARTI_H

#include <stdbool.h>
#include "mano.h"

#define INCREASE_SIZE 1


typedef struct stack {
    struct carta* stack;
    int size;
    int top_index;
} *Scarti;          //Scarti è un puntatore alla struct stack



Scarti createScarti();
bool increaseScarti(Scarti s);
void pushScarto(Scarti s, struct carta c);
struct carta topScarto(Scarti s);
bool isEmptyScarti(Scarti s);
void printScarti(Scarti s);
void destroyScarti(Scarti s);

#endif // PILA_SCARTI_H
