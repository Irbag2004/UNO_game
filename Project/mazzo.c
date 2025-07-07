#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "mazzo.h"



List riempiMazzo() {
    List mazzo = createList(); //MAZZO ORDINATO
    int num, colore, i;

     for (colore = BLU; colore <= VERDE; colore++){
        num = PESCA_QUATTRO;
        struct carta c2 = { num, NEUTRO };
        insertFirst(mazzo, c2);

     num = CAMBIA_COLORE;
        struct carta c1 = { num, NEUTRO };
        insertFirst(mazzo, c1);

            for (num = PESCA_DUE; num >= UNO; num--) {
                for(i=0;i<2;i++){
                struct carta c = { num, colore };
                insertFirst(mazzo, c);
            }
        }
               num = ZERO;
        struct carta c0 = { num, colore };
        insertFirst(mazzo, c0);
    }

    return mazzo;
}



struct carta getAndRemoveFirstCard(List l) {
    struct carta c = { -1, -1 };

    if (l == NULL || l->head == NULL) {
        return c;
    }

    Node first = l->head;
    c = first->card;


    l->head = first->next;

    free(first);

    return c;
}

