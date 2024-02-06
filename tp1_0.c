#include <stdio.h>
#include <stdlib.h>

int string_are_equal(char *a, char *b) {
    int i = 0;
    while (*(a+i) != '\0' && *(b+i) != '\0') {
        if (*(a+i) != *(b+i)) {
            return 0;
        }
        i++;
    }
    if (*(a+i) != '\0' || *(b+i) != '\0') {
        return 0;
    } else {
        return 1;
    }
}

int get_balises(FILE *pFile) {
    char pile_balises_ouvertes[50][20];
    int n_pile = 0;

    char string_array[50];

    char *current_string;
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
                current_string[n_string] = '\0';
                n_string = 0;
                if (cur_balise_type == ouvrante) {
                    // printf("Balise ouvrante : %s\n", current_string);
                    n_pile++;
                } else {
                    // printf("Balise fermante : %s\n", current_string);
                    n_pile--;
                    if (!string_are_equal(current_string, pile_balises_ouvertes[n_pile])) {
                        printf("Erreur trouvée !\nBalise attendue : </%s> Balise trouvée : </%s>\n", pile_balises_ouvertes[n_pile], current_string);
                        exit(0);
                    }
                }
                cur_etat = avant_balise;
            }
            else {
                current_string[n_string] = c;
                n_string++;
            }
            break;

            case lecture_type_balise:
            if (c == '/') {
                cur_balise_type = fermante;
                current_string = string_array;

                cur_etat = lecture_balise;
            } 
            else {
                cur_balise_type = ouvrante;
                current_string = pile_balises_ouvertes[n_pile];

                current_string[n_string] = c;
                n_string++;

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
        get_balises(pFile);
        fclose(pFile);
    }
    else printf("Erreur d'ouverture du fichier\n");
    return 0;
}