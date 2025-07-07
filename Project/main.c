#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "mazzo.h"
#include "pila_scarti.h"
#define DIM 100


int main() {

    List mazzo = riempiMazzo();
    printList(mazzo);

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

//Prova stack
    //Creo la pila degli scarti
    Scarti scarti = createScarti();
    if (scarti == NULL) {
        printf("Errore nella creazione dello stack.\n");
        return 1;
    }

    //Creo alcune carte di esempio
    struct carta prima = getAndRemoveFirstCard(mazzoDisordinato);
    struct carta seconda = getAndRemoveFirstCard(mazzoDisordinato);

    //Inserisco le carte nello stack
    pushScarto(scarti, prima);
    pushScarto(scarti, seconda);

    //Stampo lo stack
    printScarti(scarti);

    //Controllo la carta in cima
    struct carta top = topScarto(scarti);
    stampaCarta(top);

    //Distrugge lo stack
    destroyScarti(scarti);

    //Stampo lo stack
    printScarti(scarti);

//Interfaccia utente
bool esc=false;
char sel1;
int sel2;
printf("\n----------------------GIOCO DI CARTE UNO----------------------\nPremere invio per visualizzare il menu,qualsiasi altro tasto e poi invio per uscire...");
scanf("%c",&sel1);
if(sel1==10){//codice ASCII della sequenza di escape \n
    while(!esc){
        printf("\n\nMENU:(Per selezionare un'opzione, digitare il numero corrispondente)\n");
        printf("1.Partita VS CPU\n2.Partita 2 giocatori\n3.Partita 3 giocatori\n4.Visualizza Classifica\n5.Visualizza regole di gioco\n6.Esci dal gioco\n...");
        scanf("%d",&sel2);
        switch(sel2){
            case 1:
            //CPU
            break;
            case 2:
            //2 players
            break;
            case 3:
            //3 players
            break;
            case 4:
            //Classifica
            break;
            case 5:
            {
                FILE *fRul = fopen("Regole_UNO.txt", "r");

                if (fRul != NULL) {
                    char c;
                    while (fscanf(fRul, "%c", &c) != EOF)
                        printf("%c",c); // stampa ogni carattere, incluso '\n'
                    fclose(fRul);
                }
                else
                    printf("ERROR: FILE NOT FOUND\n");
            }
            break;
            case 6:
                esc=true;//Aggiorno la variabile esc per uscire dal menù
            break;
            default:
            {
                printf("Selezione errata...riprovare\n");
                esc=false;
            }
        }
    }
}
return 0;

}
