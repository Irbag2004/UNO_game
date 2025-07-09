#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mazzo.h"

const char* ColoreNome[] ={"B", "G", "R", "V","N"};
const char* NumeroNome[] ={"0","1", "2", "3", "4", "5", "6", "7", "8", "9", "X","<->", "+2", "CC","+4"};


List createList() {

    List l = (List)malloc(sizeof(struct list));
    if(l != NULL) {
        l->head = NULL;
        l->cursor = NULL;
    }

    return l;
}

bool insertFirst(List l, struct carta card) {
    bool inserted = false;
    if (card.colore >= BLU && card.colore <= NEUTRO && card.num>=ZERO && card.num <= PESCA_QUATTRO) {
        Node n = (Node)malloc(sizeof(struct node));
        if(n != NULL) {
                n->card.colore = card.colore;
                n->card.num = card.num;

                n->next = l->head;
                l->head = n;
            inserted = true;
        }
    }
    return inserted;
}
void printList(List l) {

    Node curr = l->head;

    printf("\n[ ");
    while(curr != NULL) {
        printf("(%s %s)  ", NumeroNome[curr->card.num], ColoreNome[curr->card.colore]);
        curr = curr->next;
    }
    printf(" ]\n");

}

bool isEmpty(List l) {
    return (l->head == NULL);
}
void rewindCursor(List l) {//porto in testa il cursore
    l->cursor = l->head;
}

bool hasNextCard(List l) {
    return (l->cursor != NULL);
}

struct carta nextCard(List l) {//ritorna carta successiva
    Node tempN = NULL;
    if(hasNextCard(l)) {
        tempN = l->cursor;
        l->cursor = l->cursor->next;
    }
    return tempN->card;
};


bool delete(List l, struct carta card) {//elimina una carta dal mazzo
    Node prev = NULL;
    Node curr = l->head;

    while (curr != NULL) {
        if (curr->card.colore == card.colore && curr->card.num == card.num) {
            if (prev == NULL) {
                l->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    return false;  // Carta non trovata
}

    int length(List l) {
        int len = 0;
        Node curr = l->head;

        while(curr != NULL) {
            curr = curr->next;
            len++;
        }

        return len;
    }


    void stampaCarta(struct carta c) {
    printf("num = %s, colore = %s\n", NumeroNome[c.num], ColoreNome[c.colore]);
    }

void destroyList(List l) {
    if (l != NULL) {
        Node current = l->head;
        Node next;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }

        free(l);
    }
}

