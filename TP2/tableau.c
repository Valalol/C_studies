#include <stdio.h>
#include "tableau.h"
#include "random.h"

void randomize_tableau(int *tableau, int length) {
    // remplit le tableau de valeurs random
    for (int i = 0; i<length; i++) {
        tableau[i] = random_value(0, 1000);
    }
    return;
}

void print_tableau(int *tableau, int length) {
    // fonction de debug pour visualiser le tableau
    for (int i = 0; i < length; i++) {
        printf("%d, ", tableau[i]);
    }
    printf("\n");
    return;
}
