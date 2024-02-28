#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

void gml_check(FILE *pFile) {
    // on crée une pile et une chaine de caractères
    struct Pile pile_balises;
    init_pile(&pile_balises);

    char string_array[20];
    int n_string = 0;

    // On crée nos états et nos types de balises
    enum Balise_type {
        ouvrante,
        fermante
    };

    enum Balise_type cur_balise_type;

    enum Etats {
        avant_balise,
        lecture_balise,
        lecture_type_balise,
        lecture_arguments,
        fin_balise
    };

    enum Etats cur_etat;
    cur_etat = avant_balise;
    char c;

    // tant qu'on est pas à la fin du fichier
    while(!feof(pFile)) {
        // on récupère le caractère suivant
        c = fgetc(pFile);

        // en fonction de l'état actuel
        switch(cur_etat) {
            case avant_balise:
            // si on trouve un '<' on commence à lire le type de la balise
            if (c == '<') {
                cur_etat = lecture_type_balise;
            }
            break;

            case lecture_type_balise:
            // si on trouve un '/' on sait que c'est une balise fermante sinon c'est une balise ouvrante, 
            // et on passe à la lecture de la balise en elle meme
            // S'il y a un caractère autre que '/' on utilise ungetc() pour remettre le caractère dans le flux 
            if (c == '/') {
                cur_balise_type = fermante;
                cur_etat = lecture_balise;
            } 
            else {
                ungetc(c, pFile);
                cur_balise_type = ouvrante;
                cur_etat = lecture_balise;
            }
            break;

            case lecture_balise:
            // on lit les caractères un par un jusqu'à trouver un espace ou un '>'
            if (c == '>' || c == ' ') {
                // on termine le string par un \0
                string_array[n_string] = '\0';
                n_string = 0;

                // si on trouve un espace, on commence à lire les arguments, sinon si on trouve un '>' on passe à la fin de la lecture de balise
                if (c == '>') {
                    cur_etat = fin_balise;
                } else {
                    cur_etat = lecture_arguments;
                }
            }
            else {
                string_array[n_string] = c;
                n_string++;
            }
            break;

            case lecture_arguments:
            // dès qu'on trouve le '>' on change d'etat
            if (c == '>') {
                cur_etat = fin_balise;
            }
            break;

            case fin_balise:
                // on remet le charactère actuel dans le flux
                ungetc(c, pFile);
                // Si la balise était ouvrante, on l'ajoute à la pile
                if (cur_balise_type == ouvrante) {
                    printf("+ '%s'\n", string_array);
                    pilePush(&pile_balises, string_array);
                } else {
                    // sinon, on compare le dernier élément de la pile avec la balise actuelle
                    if (strcmp(string_array, pileTop(&pile_balises))) {
                        // si les balises sont différentes, on affiche une erreur et on stoppe le programme
                        printf("Erreur trouvée !\nBalise attendue : </%s> Balise trouvée : </%s>\n", pileTop(&pile_balises), string_array);
                        return;
                    }
                    printf("- '%s'\n", pileTop(&pile_balises));
                    pilePop(&pile_balises);
                }
                cur_etat = avant_balise;
            break;
        }
    }

    // S'il reste des balises non fermée avant la fin du document, on affiche une erreur
    if (pileSize(&pile_balises) == 1) {
        printf("une balise non fermée avant la fin du document : </%s>", pileTop(&pile_balises));
        return;
    }
    else if (pileSize(&pile_balises) >= 2) {
        printf("Plusieurs balises non fermées avant la fin du document dont </%s>", pileTop(&pile_balises));
        return;
    }

    // Si le fichier a passé tous les checks, alors il est bien formatté
    printf("Pas d'erreur trouvée");
    return;
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