#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mazzo.h"

int main() {

       List mazzo = riempiMazzo();  // Ottieni mazzo creato
    printList(mazzo);  // Se hai una funzione di stampa

    List mazzoDisordinato = createList();

    srand(time(NULL));
    while(!isEmpty(mazzo)) {
        int indiceCartaDaInserire = rand()%length(mazzo);

        rewindCursor(mazzo);
        int i;
        struct carta c;
        for (i=0; i<=indiceCartaDaInserire; i++)
            c = nextCard(mazzo);
        insertFirst(mazzoDisordinato, c);
        delete(mazzo, c);
    }

    printf("\nMazzo mischiato:\n");
    printList(mazzoDisordinato);

return 0;}
