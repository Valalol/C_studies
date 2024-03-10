#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Liste.h"

void PrintList(SList *list);

void madoc_test() {
	SList *list;
	SCell *cell;

	list=CreateList();

	printf("Add 5, 3, 1\n");
	AddElementBegin(list,5);
	cell=AddElementBegin(list,3);
	AddElementBegin(list,1);
	PrintList(list);
	printf("\n");

	printf("Add 6, 8\n");
	AddElementEnd(list,6);
	AddElementEnd(list,8);
	PrintList(list);
	printf("\n");

	printf("Add 4\n");
	AddElementAfter(list,cell,4);
	PrintList(list);
	printf("\n");

	printf("Add 2\n");
	AddElementAfter(list,GetFirstElement(list),2);
	PrintList(list);
	printf("\n");

	printf("Delete 3\n");
	DeleteCell(list,cell);
	PrintList(list);
	printf("\n");

	printf("Add 7\n");
	AddElementAfter(list,GetPrevElement(GetLastElement(list)),7);
	PrintList(list);
	printf("\n");

	printf("Delete 1\n");
	DeleteCell(list, GetFirstElement(list));
	PrintList(list);
	printf("\n");

	printf("Delete 8\n");
	DeleteCell(list, GetLastElement(list));
	PrintList(list);
	printf("\n");

	printf("Add 9\n");
	AddElementAfter(list, GetLastElement(list), 9);
	PrintList(list);
	printf("\n");

	printf("Add 10\n");
	AddElementAfter(list, GetLastElement(list), 10);
	PrintList(list);
	printf("\n");

	printf("Début free de la liste");
	DeleteList(list);

	return;
}


void test_time() {
	SList *list;

	list=CreateList();

	clock_t start, end;
    float time_taken;

	start = clock();
	for (int i = 0; i<1000000; i++) {
		AddElementBegin(list, i);
	}
    end = clock();

	printf("%ld\n", start);
	printf("%ld\n", end);
    // on calcule le temps pris en divisant pas CLOCKS_PER8SEC
    time_taken = ((float) (end - start))/CLOCKS_PER_SEC;
	printf("Time taken : %fs\n", time_taken);

	printf("Début free de la liste");
	DeleteList(list);

	return;
}


int main() {
	madoc_test();
}


void PrintList(SList *list)
{
	if (list)
	{
		SCell *cell=GetFirstElement(list);
		while (cell!=NULL)
		{
			printf("[%d] -> ",GetData(cell));
			cell=GetNextElement(cell);
		}
		printf("NULL\n");
	}
}
