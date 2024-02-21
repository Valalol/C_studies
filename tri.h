#pragma once

void swap_tableau(int *tableau, int i1, int i2);
int quicksort_partition(int *tableau, int low, int high, int (*sort_func) (int, int));
void rec_quicksort(int *tableau, int low, int high, int (*sort_func) (int, int));
void quicksort(int *tableau, int length, int (*sort_func) (int, int));
void selection_sort(int *tableau, int length, int (*sort_func) (int, int));
void bubble_sort(int *tableau, int length, int (*sort_func) (int, int));