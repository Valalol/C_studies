#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define taille 30


int croissante(int a, int b) {
    return (a<b);
}


int decroissante(int a, int b) {
    return (a>b);
}


int pair_impair(int a, int b) {
    int parité_a = a%2;
    int parité_b = b%2;
    if (parité_a == parité_b) {
        return (a<b);
    } else {
        return (parité_a<parité_b);
    }
}


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
    for (int i = 0; i < length; i++) {
        if (tableau[i] > tableau[i+1]) {
            return 0;
        }
    }
    return 1; 
}


void swap_tableau(int *tableau, int i1, int i2) {
    int temp = tableau[i1];
    tableau[i1] = tableau[i2];
    tableau[i2] = temp;
}


void sort(int *tableau) {
    return;
}

int partition(int *tableau, int low, int high, int (*sort_func) (int, int)) {
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
        int index_pivot = partition(tableau, low, high, sort_func);
        rec_quicksort(tableau, low, index_pivot-1, sort_func);
        rec_quicksort(tableau, index_pivot+1, high, sort_func);
        return;
    }
}

void quicksort(int *tableau, int length) {
    rec_quicksort(tableau, 0, length-1, &croissante);
}


int main() {
    int tableau[taille];
    randomize_tableau(tableau, taille);

    print_tableau(tableau, taille);
    quicksort(tableau, taille);
    print_tableau(tableau, taille);

    void (*sort_func_pointers[]) (int*, int) = {quicksort};
}