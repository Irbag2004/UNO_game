#ifndef MAZZO_H_INCLUDED
#define MAZZO_H_INCLUDED


#include <stdbool.h>


enum colore {BLU, GIALLO, ROSSO, VERDE, NEUTRO};
enum num {ZERO, UNO, DUE, TRE, QUATTRO, CINQUE, SEI, SETTE, OTTO, NOVE, SALTA_GIRO, CAMBIA_GIRO, PESCA_DUE, CAMBIA_COLORE, PESCA_QUATTRO};

struct carta {
    int num;
    int colore;
};


struct node {
   struct carta card;
   struct node* next;
};

typedef struct node* Node;


struct list {
   Node head;
   Node cursor;
};

typedef struct list* List;

List createList();


bool insertFirst(List l, struct carta card);

bool isEmpty(List l);

int length(List l);

bool delete(List l, struct carta card);

void printList(List l);

struct carta nextCard(List l);

bool hasNextCard(List l);

void rewindCursor(List l);


List riempiMazzo();

struct carta RimuoviPrimaCarta();
void stampaCarta(struct carta c);

void destroyList();


#endif // MAZZO_H_INCLUDED
