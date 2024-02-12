#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define taille 20


void randomize_tableau(int *tableau, int length) {
    srand(time(NULL));
    
    for (int i = 0; i<length; i++) {
        tableau[i] = rand();
    }
    return;
}


void print_tableau(int *tableau, int length) {
    for (int i = 0; i < length; i++) {
        printf("[%d] %d\n", i, tableau[i]);
    }
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


int partition(int *tableau, int low, int high) {
    int pivot = tableau[high];
    int i = low - 1;

    for (int j = low; j < high - 1; j++) {
        if (tableau[j] <= pivot) {
            i++;
            swap_tableau(tableau, i, j);
        }
    }

    i++;
    swap_tableau(tableau, i, high);
    return i;
}


void quicksort(int *tableau, int low, int high) {
    if (low >= high || low < 0) {
        // print_tableau(tableau, taille);
        return;
    }
    int p = partition(tableau, low, high);

    quicksort(tableau, low, p-1);
    quicksort(tableau, p, high);
}


int main() {
    int tableau[taille];

    randomize_tableau(tableau, taille);

    print_tableau(tableau, taille);
    printf("%d", is_sorted(tableau, taille));

    quicksort(tableau, 0, taille-1);

    print_tableau(tableau, taille);
    printf("%d", is_sorted(tableau, taille));
}