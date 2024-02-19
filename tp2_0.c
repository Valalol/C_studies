#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tri.h"
#include "comparaison.h"

#define taille 10


void randomize_tableau(int *tableau, int length) {
    srand(time(NULL));
    
    for (int i = 0; i<length; i++) {
        tableau[i] = rand();
    }
    return;
}

void print_tableau(int *tableau, int length) {
    for (int i = 0; i < length; i++) {
        // printf("[%d] %d\n", i, tableau[i]);
        printf("%d, ", tableau[i]);
    }
    printf("\n");
    return;
}

int is_sorted(int *tableau, int length) {
    for (int i = 0; i < length-1; i++) {
        if (tableau[i] > tableau[i+1]) {
            return 0;
        }
    }
    return 1; 
}


int main() {
    int tableau[taille];
    int tableau_test[taille];
    clock_t t;
    float time_taken;
    randomize_tableau(tableau, taille);

    void (*sort_func_pointers[]) (int*, int) = {quicksort, selection_sort, bubble_sort};
    char function_names[20][20] = {"quicksort", "selection_sort", "bubble_sort"};

    for (int i = 0; i < 3; i++) {
        memcpy(tableau_test, tableau, sizeof(tableau));
        // print_tableau(tableau_test, taille);

        t = clock();
        sort_func_pointers[i] (tableau_test, taille);
        t = clock() - t;

        time_taken = ((double)t)/CLOCKS_PER_SEC;
        // print_tableau(tableau_test, taille);

        if (is_sorted(tableau_test, taille)) {
            printf("La fonction de tri '%s' a trié le tableau en %fs\n", function_names[i], time_taken);
        } else {
            printf("La fonction de tri '%s' n'a pas trié le tableau correctement\n", function_names[i]);
        }
    }
}