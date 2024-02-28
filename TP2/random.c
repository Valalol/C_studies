#include <stdlib.h>
#include <time.h>
#include "random.h"

void init_random() {
    // met une seed à peu près random (en fonction du temps)
    srand(time(NULL));
    return;
}

int random_value(int min, int max) {
    // On prend une valeur random entre min et max
    int value = rand() % (max-min) + min;
    return value;
}
