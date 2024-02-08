#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

int gml_check(FILE *pFile) {
    struct Pile pile_balises;
    init_pile(&pile_balises);

    char string_array[20];
    int n_string = 0;

    enum Balise_type {
        ouvrante,
        fermante
    };

    enum Balise_type cur_balise_type;

    enum Etats {
        avant_balise,
        lecture_balise,
        lecture_type_balise
    };

    enum Etats cur_etat;
    cur_etat = avant_balise;
    char c;

    while(!feof(pFile)) {
        c = fgetc(pFile);

        switch(cur_etat) {
            case avant_balise:
            if (c == '<') {
                cur_etat = lecture_type_balise;
            }
            break;

            case lecture_balise:
            if (c == '>' || c == ' ') {
                string_array[n_string] = '\0';
                n_string = 0;
                if (cur_balise_type == ouvrante) {
                    // printf("Balise ouvrante : %s\n", string_array);
                    pilePush(&pile_balises, string_array);
                } else {
                    // printf("Balise fermante : %s\n", string_array);

                    if (strcmp(string_array, pileTop(&pile_balises))) {
                        printf("Erreur trouvée !\nBalise attendue : </%s> Balise trouvée : </%s>\n", pileTop(&pile_balises), string_array);
                        exit(0);
                    }
                    pilePop(&pile_balises);
                }
                cur_etat = avant_balise;
            }
            else {
                string_array[n_string] = c;
                n_string++;
            }
            break;

            case lecture_type_balise:
            if (c == '/') {
                cur_balise_type = fermante;

                cur_etat = lecture_balise;
            } 
            else {
                cur_balise_type = ouvrante;

                ungetc(c, pFile);

                cur_etat = lecture_balise;
            }
            break;
        }
    }
    printf("Pas d'erreur trouvée");
    return 0;
}



int main() {
    FILE *pFile;

    if ((pFile = fopen("tp1_input.txt", "rt"))) {
        gml_check(pFile);
        fclose(pFile);
    }
    else printf("Erreur d'ouverture du fichier\n");
    return 0;
}