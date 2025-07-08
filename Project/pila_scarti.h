#ifndef PILA_SCARTI_H
#define PILA_SCARTI_H

#include <stdbool.h>
#include "mano.h"

#define INCREASE_SIZE 1

// Definizione della struttura stack per le carte scartate
typedef struct stack {
    struct carta* stack;
    int size;
    int top_index;
} *Scarti;



Scarti createScarti();
bool increaseScarti(Scarti s);
void pushScarto(Scarti s, struct carta c);
struct carta topScarto(Scarti s);
void destroyScarti(Scarti s);

#endif // PILA_SCARTI_H
