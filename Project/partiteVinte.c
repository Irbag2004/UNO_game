
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "partiteVinte.h"

#define MAX_PLAYERS 2


void Upload(struct player g1,struct player g2, char data[]) {
    FILE *fv = fopen("partiteVinte_UNO.txt", "a");
        fprintf(fv, "PARTITE VINTE del %s\n(nome giocatore - n di partite vinte):\n",data);
        fprintf(fv, "%s - %d\n", g1.nome, g1.punteggio);
        fprintf(fv, "%s - %d\n", g2.nome, g2.punteggio);
        fclose(fv);

}

void stampaPoints(){
                FILE *fv = fopen("partiteVinte_UNO.txt", "r");

                if (fv != NULL) {
                    char c;
                    while (fscanf(fv, "%c", &c) != EOF)
                        printf("%c",c); // stampa ogni carattere, incluso '\n'
                    fclose(fv);
                }
                else
                    printf("ERROR: FILE NOT FOUND\n");
}
