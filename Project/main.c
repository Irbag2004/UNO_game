#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "mano.h"
#include "pila_scarti.h"
#include "gioco.h"
#include "partiteVinte.h"
#define DIM 50


int main() {

    /*//List mazzo = riempiMazzo();
    //printList(mazzo);


    printf("\nMazzo mischiato:\n");
    printList(mazzoDisordinato);

    //Creo alcune carte di esempio
    struct carta prima = RimuoviPrimaCarta(mazzoDisordinato);
    struct carta seconda = RimuoviPrimaCarta(mazzoDisordinato);

    //Inserisco le carte nello stack
    pushScarto(scarti, prima);
    pushScarto(scarti, seconda);

    //Controllo la carta in cima
    struct carta top = topScarto(scarti);
    stampaCarta(top);

    //Distrugge lo stack
    destroyScarti(scarti);

    //PROVA MANO
    printf("\n\n\n");
    int i;
    List manoG1=createList();
    for(i=0;i<7;i++){
        struct carta ci=RimuoviPrimaCarta(mazzoDisordinato);
        aggiungiCarta(manoG1,ci);
    }

    stampaMano(manoG1);
    ordinaMano(manoG1);
    printf("\nMano ordinata:\n");
    stampaMano(manoG1);*/








//Interfaccia utente
struct player g1;
struct player g2;
//char giocatore1[DIM];
//char giocatore2[DIM];

//int occr;
int selUno;
int i;
bool esc=false;
char sel1;
int sel2;
char sel3;
printf("\n----------------------GIOCO DI CARTE UNO----------------------\nPremere invio per visualizzare il menu,qualsiasi altro tasto e poi invio per uscire...");
scanf("%c",&sel1);
if(sel1==10){//codice ASCII della sequenza di escape \n
    while(!esc){
        printf("\n\nMENU:(Per selezionare un'opzione, digitare il numero corrispondente)\n");
        printf("1.Partita 2 giocatori\n2.Visualizza partite vinte\n3.Visualizza regole di gioco\n4.Esci dal gioco\n...");
        scanf("%d",&sel2);
        switch(sel2){
            case 1:{

                //08/07/2025    14:50



                //Scelta casuale ordine giocatore
                int testaCroce;
                printf("giocatore1 scegli tra testa o croce per vedere chi comincia\n");
                printf("digitare 0 per testa, digitare 1 per croce");
                scanf("%d",&testaCroce);
                srand(time(NULL));
                int moneta=rand()%2;
                if(moneta==testaCroce){
                    printf("giocatore1 hai vinto il lancio della moneta, inizi tu a giocare");
                    printf("\ndigitare i nomi dei giocatori\n");
                    printf("giocatore1:\n");
                    scanf("%s",g1.nome);
                    printf("giocatore2:\n");
                    scanf("%s",g2.nome);
                }
                else{
                    printf("giocatore2 hai vinto il lancio della moneta, inizi tu a giocare");
                    printf("\ndigitare i nomi dei giocatori\n");
                    printf("giocatore2:\n");
                    scanf("%s",g1.nome);
                    printf("giocatore1:\n");
                    scanf("%s",g2.nome);
                }
                //predisposizione inzio partita
                List mazzo = riempiMazzo();
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

                Scarti scarti = createScarti();
                    if (scarti == NULL) {
                        printf("Errore nella creazione dello stack.\n");
                        return 1;
                    }

                pushScarto(scarti,RimuoviPrimaCarta(mazzoDisordinato)); //gira scoperta a terra la prima carta del mazzo

                List manoG1=createList();
                    for(i=0;i<7;i++){
                        struct carta ci=RimuoviPrimaCarta(mazzoDisordinato);
                        aggiungiCarta(manoG1,ci);
                    }
                ordinaMano(manoG1);

                List manoG2=createList();
                    for(i=0;i<7;i++){
                        struct carta ci=RimuoviPrimaCarta(mazzoDisordinato);
                        aggiungiCarta(manoG2,ci);
                    }
                ordinaMano(manoG2);

                //while(!manoVuota(manoG1)&&!manoVuota(manoG2)){}
                    struct carta cartaATerra;
                    cartaATerra=topScarto(scarti);
                    stampaCarta(cartaATerra);

                printf("e' il turno di %s",g1.nome);
                printf("\n\nPremere invio per giocare,qualsiasi altro tasto e poi invio per uscire...\n");
                fflush(stdin);
                scanf("%c",&sel3);
                if(sel3==10){//codice ASCII della sequenza di escape

                        printf("\n\nil numero di carte di %s  e':",g2.nome);
                        printf("%d\n",numeroCarteMano(manoG2));
                            if(gioca(manoG1,scarti,cartaATerra)){
                                pesca(manoG1,mazzoDisordinato);
                                gioca(manoG1,scarti,cartaATerra);
                            }
                            if(manoVuota(manoG1)){
                                printf("%s ha vinto la partita!",g1.nome);
                                g1.punteggio++;
                                Upload(g1);
                                break;
                            }

                                printf("digitare 0 se si vuole passare la mano di gioco");
                                scanf("%d",&selUno);

                                if(numeroCarteMano(manoG1)==1&&selUno==0){
                                    pesca(manoG1,mazzoDisordinato);
                                    pesca(manoG1,mazzoDisordinato);
                                }
                        }

                }
                //turno giocatore 2

            break;

            case 2:
                stampaPoints();
            break;
            case 3:
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
            case 4:
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
