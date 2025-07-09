#include <stdio.h>
#include <string.h>
#include "partiteVinte.h"


void Upload(struct player g){
        FILE *fv = fopen("partiteVinte_UNO.txt", "w+");
        if (fv != NULL) {
            char s[DIM];
            fprintf(fv,"PARTITE VINTE (nome giocatore - n° di partite vinte)\n");
            while (fscanf(fv, "%s", s) != EOF)
                    if(strcmp(s,g.nome)==0)
                        g.punteggio++;
            fprintf(fv,"\n%s - %d pts", g.nome, g.punteggio);
            fclose(fv);
        }
        else
            printf("ERROR: FILE NOT FOUND\n");
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
