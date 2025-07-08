#ifndef MANO_H_INCLUDED
#define MANO_H_INCLUDED

#include <stdbool.h>
#include "mazzo.h"


bool aggiungiCarta(List mano, struct carta c);
struct carta estraiCarta(List mano, int occr);
void stampaMano(List mano);
bool manoVuota(List mano);
int numeroCarteMano(List mano);
void ordinaMano(List mano);

#endif // MANO_H_INCLUDED
