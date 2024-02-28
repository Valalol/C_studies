#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
    char ch;
    char arret = ' ';
    while (ch != arret) {
        printf("\nEntrez un nouveau chiffre : ");
        ch = getchar();
        if (isdigit(ch)) {
            printf("\nLe chiffre entré est %d", ch + "0");
        } else {
            printf("\nLe caractère n'est pas un chiffre");
        }
    }
    return 0;
}