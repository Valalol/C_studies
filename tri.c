#include <stdio.h>
#include "tri.h"
#include "comparaison.h"

void swap_tableau(int *tableau, int i1, int i2) {
    int temp = tableau[i1];
    tableau[i1] = tableau[i2];
    tableau[i2] = temp;
}

int quicksort_partition(int *tableau, int low, int high, int (*sort_func) (int, int)) {
    int valeur_pivot = tableau[low];
    int index_pivot = low;
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
    if (low >= high || low < 0) {
        return;
    } else {
        int index_pivot = quicksort_partition(tableau, low, high, sort_func);
        rec_quicksort(tableau, low, index_pivot-1, sort_func);
        rec_quicksort(tableau, index_pivot+1, high, sort_func);
        return;
    }
}

void quicksort(int *tableau, int length) {
    rec_quicksort(tableau, 0, length-1, &croissant);
    return;
}

void selection_sort(int *tableau, int length) {
    int min_value, min_index;
    for (int i = 0; i < length; i++) {
        min_value = tableau[i];
        min_index = i;
        for (int j = i; j < length; j++) {
            if (tableau[j] < min_value) {
                min_index = j;
                min_value = tableau[j];
            }
        }
        swap_tableau(tableau, i, min_index);
    }
    return;
}

void bubble_sort(int *tableau, int length) {
    int sorted = 0;
    
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < length-1; i++) {
            if (tableau[i] > tableau[i+1]) {
                sorted = 0;
                swap_tableau(tableau, i, i+1);
            }
        }
    }
    return;
}