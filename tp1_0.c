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
    enum Etats {
        avant_balise,
        lecture_balise,
        lecture_type_balise
    };

    enum Etats cur_etat;
    cur_etat = avant_balise;
    char c;
    c = fgetc(pFile);

    while(!feof(pFile)) {
        c = fgetc(pFile);

        switch(cur_etat) {
            case avant_balise:
            if (c == '<') {
                cur_etat = lecture_type_balise;
            }
            break;

            case lecture_balise:
            if (c == '>') {
                printf("\n");
                cur_etat = avant_balise;
            } else {
                printf("%c",c);
            }
            break;

            case lecture_type_balise:
            if (c == '/') {
                printf("Balise fermante : ");
                cur_etat = lecture_balise;
            } else {
                printf("Balise ouvrante : %c", c);
                cur_etat = lecture_balise;
            }
            break;
        }
    }
    return 0;
}



int main() {
    FILE *pFile;

    if ((pFile = fopen("tp1_input.txt", "rt"))) {
        get_balises(pFile);
        fclose(pFile);
    }
    else printf("Error opening file\n");
    return 0;

    // int result = string_are_equal("aaa\0", "aaa\0");
    // printf("%d",result);
}