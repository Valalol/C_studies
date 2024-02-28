#include <stdlib.h>
#include <stdio.h>

#include "Liste.h"

struct SCell {
    Data value;
    SCell *prev_cell;
    SCell *next_cell;
};

struct SList {
    SCell *premier;
    SCell *dernier;
    SCell **current_block;
};

SList* CreateList() {
    SList *list = (SList*) malloc(sizeof(SList));
    list->premier = NULL;
    list->current_block = NULL;
    return list;
}

void DeleteList(SList *list) {
    free(list);
}



SCell* AddElementBegin(SList *list,Data elem) {
    // if (list->current_block == NULL || )
    SCell *new_cell = (SCell*) malloc(sizeof(SCell));
    new_cell->value = elem;
    new_cell->prev_cell = NULL;
    new_cell->next_cell = list->premier;
    
    if (list->premier != NULL) {
        // si liste vide
        list->premier->prev_cell = new_cell;
    } else {
        // si liste non vide
        list->dernier = new_cell;
    }
    list->premier = new_cell;
    
    return new_cell;
}


SCell* AddElementEnd(SList *list,Data elem) {
    SCell *new_cell = (SCell*) malloc(sizeof(SCell));
    new_cell->value = elem;
    new_cell->prev_cell = list->dernier;
    new_cell->next_cell = NULL;
    
    if (list->dernier != NULL) {
        // si liste vide
        list->dernier->next_cell = new_cell;
    } else {
        // si liste non vide
        list->premier = new_cell;
    }
    list->dernier = new_cell;
    
    return new_cell;
}


SCell* AddElementAfter(SList *list,SCell *cell,Data elem) {
    SCell *new_cell = (SCell*) malloc(sizeof(SCell));
    new_cell->value = elem;
    new_cell->prev_cell = cell->prev_cell;
    new_cell->next_cell = cell->next_cell;

    if (cell->next_cell != NULL) {
        cell->next_cell->prev_cell = new_cell;
    } else {
        list->dernier = new_cell;
    }
    cell->next_cell = new_cell;

    return new_cell;
}


void DeleteCell(SList *list,SCell *cell) {
    if (cell->prev_cell != NULL) {
        cell->prev_cell->next_cell = cell->next_cell;
    } else {
        list->premier = cell->next_cell;
    }
    if (cell->next_cell != NULL) {
        cell->next_cell->prev_cell = cell->prev_cell;
    } else {
        list->dernier = cell->prev_cell;
    }

    free(cell);
}

SCell* GetFirstElement(SList *list) {
    return list->premier;
}

SCell* GetLastElement(SList *list) {
    return list->dernier;
}

SCell* GetPrevElement(SCell *cell) {
    return cell->prev_cell;
}

SCell* GetNextElement(SCell *cell) {
    return cell->next_cell;
}

Data GetData(SCell *cell) {
    return cell->value;
}