#include <stdio.h>
#include "tri.h"
#include "comparaison.h"

void swap_tableau(int *tableau, int i1, int i2) {
    // échange de deux valeurs
    int temp = tableau[i1];
    tableau[i1] = tableau[i2];
    tableau[i2] = temp;
}

int quicksort_partition(int *tableau, int low, int high, int (*sort_func) (int, int)) {
    int valeur_pivot = tableau[low];
    int index_pivot = low;
    // on prend le pivot et on met les valeurs plus petites avant le pivot
    for (int i = low+1; i <= high; i++) {
        if ((*sort_func)(tableau[i], valeur_pivot)) {
            swap_tableau(tableau, i, index_pivot+1);
            swap_tableau(tableau, index_pivot, index_pivot+1);
            index_pivot++;
        }
    }
    return(index_pivot);
}

void rec_quicksort(int *tableau, int low, int high, int (*sort_func) (int, int)) {
    // S'il n'y a qu'une case on ne fait rien
    if (low >= high || low < 0) {
        return;
    } else {
        // sinon on prend un pivot on déplace les éléments de chaque coté du pivot avec la fonction partition
        // et on réappelle le quicksort sur chaque morceau
        int index_pivot = quicksort_partition(tableau, low, high, sort_func);
        rec_quicksort(tableau, low, index_pivot-1, sort_func);
        rec_quicksort(tableau, index_pivot+1, high, sort_func);
        return;
    }
}

void quicksort(int *tableau, int length, int (*sort_func) (int, int)) {
    // quicksort
    rec_quicksort(tableau, 0, length-1, sort_func);
    return;
}

void selection_sort(int *tableau, int length, int (*sort_func) (int, int)) {
    // tri par sélection (on trouve l'élément le plus petit et on le met au début puis on trouve le 2e plus petit et on le met à la 2e case)
    int min_value, min_index;
    for (int i = 0; i < length; i++) {
        min_value = tableau[i];
        min_index = i;
        for (int j = i; j < length; j++) {
            if ((*sort_func)(tableau[j], min_value)) {
                min_index = j;
                min_value = tableau[j];
            }
        }
        swap_tableau(tableau, i, min_index);
    }
    return;
}

void bubble_sort(int *tableau, int length, int (*sort_func) (int, int)) {
    // trie à bulle (on échange les élémennts deux à deux jusqu'à que ce soit trié)
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < length-1; i++) {
            if (!((*sort_func)(tableau[i], tableau[i+1]))) {
                sorted = 0;
                swap_tableau(tableau, i, i+1);
            }
        }
    }
    return;
}