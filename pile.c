#include "pile.h"

void init_pile(struct Pile *pile) {
    pile->index = 0;
}

void pilePush(struct Pile *pile, char *str) {
    strcpy(pile->tableau_str[pile->index], str);
    pile->index++;
}

void pilePop(struct Pile *pile) {
    pile->index--;
}

char* pileTop(struct Pile *pile) {
    return (pile->tableau_str[pile->index - 1]);
}

int pileSize(struct Pile *pile) {
    return (pile->index);
}

void pilePrint(struct Pile *pile) {
    for (int i = 0; i < pile->index; i++) {
        printf("[%d] %s\n", i, pile->tableau_str[i]);
    }
}