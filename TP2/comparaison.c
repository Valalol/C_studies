#include "comparaison.h"

int croissant(int a, int b) {
    // tri croissant
    return (a<=b);
}

int decroissant(int a, int b) {
    // tri décroissant
    return (a>=b);
}

int croissant_pair_impair(int a, int b) {
    // séparation des pairs et des impairs et tri croissant 
    int parité_a = a%2;
    int parité_b = b%2;
    if (parité_a == parité_b) {
        return (a<=b);
    } else {
        return (parité_a<=parité_b);
    }
}