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

int selUno;
bool esc=false;
char sel1;
int sel2;
char sel3;
char data[5];

//Interfaccia utente
printf("\n----------------------GIOCO DI CARTE UNO----------------------\n");
printf("Inserire giorno e mese(gg-mm)...");
scanf("%s",data);
fflush(stdin);
printf("Premere invio per visualizzare il menu,qualsiasi altro tasto e poi invio per uscire...");
scanf("%c",&sel1);
fflush(stdin);
if(sel1==10){//codice ASCII della sequenza di escape \n
    while(!esc){
        printf("\n\nMENU:(Per selezionare un'opzione, digitare il numero corrispondente)\n");
        printf("1.Partita 2 giocatori\n2.Visualizza partite vinte\n3.Visualizza regole di gioco\n4.Esci dal gioco\n...");
        scanf("%d",&sel2);
        fflush(stdin);
        switch(sel2){
            case 1:{
                //inizializzazione giocatori

                struct player g1;
                struct player g2;
                g1.punteggio=0;
                g2.punteggio=0;

                //Scelta casuale ordine giocatore

                int testaCroce;
                printf("giocatore1 scegli tra testa o croce per vedere chi comincia\n");
                printf("digitare 0 per testa, digitare 1 per croce...");
                scanf("%d",&testaCroce);
                fflush(stdin);
                while(testaCroce!=0&&testaCroce!=1){
                    printf("errore nella digitazione\n");
                    printf("digitare 0 per testa, digitare 1 per croce...");
                    scanf("%d",&testaCroce);
                    fflush(stdin);
                }
                srand(time(NULL));
                int moneta=rand()%2;
                if(moneta==testaCroce){
                    printf("\ngiocatore1 hai vinto il lancio della moneta, inizi tu a giocare");
                    printf("\ndigitare i nomi dei giocatori\n");
                    printf("giocatore1...");
                    scanf("%s",g1.nome);
                    printf("giocatore2...");
                    scanf("%s",g2.nome);
                }
                else{
                    printf("\ngiocatore2 hai vinto il lancio della moneta, inizi tu a giocare");
                    printf("\ndigitare i nomi dei giocatori\n");
                    printf("giocatore2...");
                    scanf("%s",g1.nome);
                    printf("giocatore1...");
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

                Scarti scarti = createScarti();//creazione della pila degli scarti
                    if (scarti == NULL) {
                        printf("Errore nella creazione dello stack.\n");
                        return 1;
                    }

                pushScarto(scarti,RimuoviPrimaCarta(mazzoDisordinato)); //aggiunge la prima carta del mazzo alla pila degli scarti

                //creazione mani di gioco

                List manoG1=createList();
                int i;
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

                //predisposizione turni

                bool partitaTerminata=false;
                bool blocca2=false;
                bool blocca1=false;
                struct carta cartaATerra;
                while(!partitaTerminata){
                    if(!blocca1){
                    blocca2=false;

                    //turno giocatore 1
                    cartaATerra=topScarto(scarti);
                    printf("\nCARTA A TERRA: ");
                    stampaCarta(cartaATerra);

                    printf("\ne' il turno di %s",g1.nome);
                    printf("\n\nPremere invio per giocare,qualsiasi altro tasto e poi invio per uscire...");
                    fflush(stdin);
                    scanf("%c",&sel3);
                    fflush(stdin);
                    if(sel3==10){//codice ASCII della sequenza di escape

                        printf("\n\nil numero di carte di %s  e':",g2.nome);
                        printf("%d\n",numeroCarteMano(manoG2));

                        int numCarteG1=numeroCarteMano(manoG1);

                        if(gioca(manoG1,scarti,cartaATerra)){
                            pesca(manoG1,mazzoDisordinato);
                            gioca(manoG1,scarti,cartaATerra);
                            }
                        if(numeroCarteMano(manoG1)<numCarteG1){
                            cartaATerra=topScarto(scarti);
                            if(cartaATerra.num==SALTA_GIRO||cartaATerra.num==CAMBIA_GIRO)   //salta_giro, cambia_giro
                                blocca2=true;
                            if(cartaATerra.colore==NEUTRO){     //cambia_colore, pesca_quattro
                                printf("\nscegliere il colore desiderato(0-B, 1-G, 2-R, 3-V)...");
                                int n;
                                scanf("%d",&n);
                                while(n!=0&&n!=1&&n!=2&&n!=3){
                                    printf("errore nella digitazione");
                                    printf("\nscegliere il colore desiderato(0-B, 1-G, 2-R, 3-V)...");
                                    scanf("%d",&n);
                                }
                                cartaATerra.colore=n;
                                pushScarto(scarti,cartaATerra);
                            }
                            if(cartaATerra.num==PESCA_QUATTRO)  //pesca_quattro
                                pesca4(manoG2,mazzoDisordinato);
                            if(cartaATerra.num==PESCA_DUE)  //pesca_due
                                pesca2(manoG2,mazzoDisordinato);
                            }
                            if(manoVuota(manoG1)){  //condizione di vittoria
                                printf("%s ha vinto la partita!",g1.nome);
                                g1.punteggio++;
                                partitaTerminata = true;
                                break;
                            }
                                printf("digitare 0 se si vuole passare la mano di gioco...");
                                scanf("%d",&selUno);
                                fflush(stdin);

                                if(numeroCarteMano(manoG1)==1){ //una sola carta in mano
                                    if(selUno==0){
                                        printf("%s NON HA DETTO UNO!! Pesca due carte\n",g1.nome);
                                        pesca2(manoG1,mazzoDisordinato);
                                    }
                                    else
                                        printf("%s ha detto UNO\n",g1.nome);
                                }

                    }
                    else
                        break;
                    }

                    //turno giocatore 2
                    if(!blocca2){
                        blocca1=false;
                        cartaATerra=topScarto(scarti);
                        printf("\nCARTA A TERRA: ");
                        stampaCarta(cartaATerra);
                        printf("\ne' il turno di %s",g2.nome);
                        fflush(stdin);
                        printf("\n\nPremere invio per giocare,qualsiasi altro tasto e poi invio per uscire...");
                        scanf("%c",&sel3);
                        fflush(stdin);
                        if(sel3==10){//codice ASCII della sequenza di escape

                            printf("\n\nil numero di carte di %s  e':",g1.nome);
                            printf("%d\n",numeroCarteMano(manoG1));

                            int numCarteG2=numeroCarteMano(manoG2);

                            if(gioca(manoG2,scarti,cartaATerra)){
                                pesca(manoG2,mazzoDisordinato);
                                gioca(manoG2,scarti,cartaATerra);
                            }

                            if(numeroCarteMano(manoG2)<numCarteG2){
                                cartaATerra=topScarto(scarti);
                                if(cartaATerra.num==SALTA_GIRO||cartaATerra.num==CAMBIA_GIRO)   //salta_giro, cambia_giro
                                    blocca1=true;
                                if(cartaATerra.colore==NEUTRO){     //cambia_colore, pesca_quattro
                                    printf("\nscegliere il colore desiderato(0-B, 1-G, 2-R, 3-V)...");
                                    int n;
                                    scanf("%d",&n);
                                    while(n!=0&&n!=1&&n!=2&&n!=3){
                                        printf("errore nella digitazione");
                                        printf("\nscegliere il colore desiderato(0-B, 1-G, 2-R, 3-V)...");
                                        scanf("%d",&n);
                                    }
                                    cartaATerra.colore=n;
                                    pushScarto(scarti,cartaATerra);
                                }
                                if(cartaATerra.num==PESCA_QUATTRO)  //pesca_quattro
                                    pesca4(manoG1,mazzoDisordinato);
                                if(cartaATerra.num==PESCA_DUE)  //pesca_due
                                    pesca2(manoG1,mazzoDisordinato);
                            }

                            if(manoVuota(manoG2)){
                                printf("%s ha vinto la partita!",g2.nome);
                                g2.punteggio++;
                                partitaTerminata = true;
                                break;
                            }

                            printf("digitare 0 se si vuole passare la mano di gioco...");
                            scanf("%d",&selUno);
                            fflush(stdin);

                            if(numeroCarteMano(manoG2)==1){
                                if(selUno==0){
                                    printf("%s NON HA DETTO UNO!! Pesca due carte\n",g2.nome);
                                    pesca2(manoG2,mazzoDisordinato);
                                }
                                else
                                    printf("%s ha detto UNO\n",g2.nome);
                            }
                        }
                        else
                            break;
                    }
                }

                //a partita terminata, libero la memoria e carico i punteggi in classifica

                if (partitaTerminata) {
                    Upload(g1,g2,data);
                    destroyList(mazzo);
                    destroyList(mazzoDisordinato);
                    destroyList(manoG1);
                    destroyList(manoG2);
                    destroyScarti(scarti);
                }

            }
            break;


            //stampa classifica
            case 2:
                stampaPoints();
            break;


            //stampa regole di gioco
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


            //esce dal gioco
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
