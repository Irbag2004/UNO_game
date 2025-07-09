#ifndef CLASSIFICA_H_INCLUDED
#define CLASSIFICA_H_INCLUDED
#define DIM 50

struct player{
    char nome[DIM];
    int punteggio;
};

void Upload(struct player g1,struct player g2,char data[]);
void stampaPoints();

#endif // CLASSIFICA_H_INCLUDED
