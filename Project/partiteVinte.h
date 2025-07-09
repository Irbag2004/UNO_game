#ifndef CLASSIFICA_H_INCLUDED
#define CLASSIFICA_H_INCLUDED
#define DIM 50

struct player{
    char nome[DIM];
    int punteggio;
};

void Upload(struct player g);
void stampaPoints();

#endif // CLASSIFICA_H_INCLUDED
