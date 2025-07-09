#ifndef GIOCO_H_INCLUDED
#define GIOCO_H_INCLUDED
#include "pila_scarti.h"
#include <stdbool.h>
void pesca(List manoG,List mazzo);
bool gioca(List manoG,Scarti s,struct carta cartaATerra);
#endif // GIOCO_H_INCLUDED
