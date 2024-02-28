#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tri.h"
#include "comparaison.h"
#include "random.h"
#include "tableau.h"


float sort_timer(int *tableau_test, int length, void (sort_func) (int*, int, int (int, int)), int (sort_key) (int, int)) {
    // lance une fonction de tri en mesurant son temps d'execution
    clock_t t;
    float time_taken;

    t = clock();
    // on lance la fonction de tri
    sort_func(tableau_test, length, sort_key);
    t = clock() - t;

    // on calcule le temps pris en divisant pas CLOCKS_PER8SEC
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    return time_taken;
}


int main() {
    int taille = 10000;

    // on crée notre tableau et notre copie pour les tests
    int tableau[taille];
    int tableau_test[taille];
    // on randomize
    randomize_tableau(tableau, taille);

    float time_taken;

    // On choisit notre clé de tri parmis croissant, decroissant et croissant_pair_impair
    int (*sort_key) (int, int) = &croissant;

    // On crée notre liste de pointeurs vers nos fonctions de tri
    void (*sort_func_pointers[]) (int*, int, int (int, int)) = {quicksort, selection_sort, bubble_sort};
    
    // On stocke leurs noms dans une liste
    char function_names[20][20] = {"quicksort", "selection_sort", "bubble_sort"};

    for (int i = 0; i < 3; i++) {
        // on crée une copie du tableau 'tableau' dans 'tableau_test'
        memcpy(tableau_test, tableau, sizeof(tableau));

        // On trie le tableau en récupérant le temps d'execution
        time_taken = sort_timer(tableau_test, taille, sort_func_pointers[i], sort_key);

        // On vérifie que le tableau soit trié et si oui, on affiche le temps de tri
        if (is_sorted(tableau_test, taille, sort_key)) {
            printf("La fonction de tri '%s' a trié le tableau en %fs\n", function_names[i], time_taken);
        } else {
            printf("La fonction de tri '%s' n'a pas trié le tableau correctement\n", function_names[i]);
        }
    }
}