#include <stdio.h>
#include "pile.h"

int main() {
    struct Pile mapile;
    init_pile(&mapile);
    pilePush(&mapile, "MES MINIONNNS");
    pilePush(&mapile, "NOUS ALLONS VOLER");
    pilePush(&mapile, "LA LUUUUUUUUUNNEEE");
    pilePrint(&mapile);
}