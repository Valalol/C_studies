#pragma once
#include <stdio.h>
#include <string.h>

struct Pile {
    char tableau_str[50][20];
    int index;
};

void init_pile(struct Pile *pile);

void pilePush(struct Pile *pile, char *str);

void pilePop(struct Pile *pile);

char* pileTop(struct Pile *pile);

int pileSize(struct Pile *pile);

void pilePrint(struct Pile *pile);