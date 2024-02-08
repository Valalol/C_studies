#pragma once

struct Pile {
    char tableau_str[50][20];
    int index;
};

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