#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Concat(const char *dest, const char *src1, const char *src2) {
    FILE *pdest, *psrc1, *psrc2;
    int c;

    pdest = fopen(dest, "w");
    if (!(pdest)) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    psrc1 = fopen(src1, "rt");
    if (!(psrc1)) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    psrc2 = fopen(src2, "rt");
    if (!(psrc2)) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }

    while ((c = fgetc(psrc1)) != EOF ) {
        fputc(c, pdest);
    }
    fclose(psrc1);

    while ((c = fgetc(psrc2)) != EOF ) {
        fputc(c, pdest);
    }
    fclose(psrc2);
    fclose(pdest);
}




typedef struct Lettre_apparition {
    char lettre;
    int n;
} Lettre_apparition;




void swap_tableau(Lettre_apparition *tableau, int i1, int i2) {
    // échange de deux valeurs
    Lettre_apparition temp = tableau[i1];
    tableau[i1] = tableau[i2];
    tableau[i2] = temp;
}


int quicksort_partition(Lettre_apparition *tableau, int low, int high, int (*sort_func) (Lettre_apparition, Lettre_apparition)) {
    Lettre_apparition valeur_pivot = tableau[low];
    int index_pivot = low;
    // on prend le pivot et on met les valeurs plus petites avant le pivot
    for (int i = low+1; i <= high; i++) {
        if ((*sort_func)(tableau[i], valeur_pivot)) {
            swap_tableau(tableau, i, index_pivot+1);
            swap_tableau(tableau, index_pivot, index_pivot+1);
            index_pivot++;
        }
    }
    return(index_pivot);
}

void rec_quicksort(Lettre_apparition *tableau, int low, int high, int (*sort_func) (Lettre_apparition, Lettre_apparition)) {
    // S'il n'y a qu'une case on ne fait rien
    if (low >= high || low < 0) {
        return;
    } else {
        // sinon on prend un pivot on déplace les éléments de chaque coté du pivot avec la fonction partition
        // et on réappelle le quicksort sur chaque morceau
        int index_pivot = quicksort_partition(tableau, low, high, sort_func);
        rec_quicksort(tableau, low, index_pivot-1, sort_func);
        rec_quicksort(tableau, index_pivot+1, high, sort_func);
        return;
    }
}

void quicksort(Lettre_apparition *tableau, int length, int (*sort_func) (Lettre_apparition, Lettre_apparition)) {
    rec_quicksort(tableau, 0, length-1, sort_func);
    return;
}

int decroissant(Lettre_apparition a, Lettre_apparition b) {
    return (a.n>=b.n);
}



void StatFreq(const char *fichier) {
    FILE *pfile;

    Lettre_apparition lettres_amount_list[50];
    for (int i = 0; i<50; i++) {
        lettres_amount_list[i].lettre = '\0';
        lettres_amount_list[i].n = 0;
    }

    if ((pfile = fopen(fichier, "rt"))) {
        char c;
        while ((c = fgetc(pfile)) != EOF ) {
            
            int i = 0;

            while (lettres_amount_list[i].lettre != '\0' && lettres_amount_list[i].lettre != c) {
                i++;
            }

            lettres_amount_list[i].lettre = c;
            lettres_amount_list[i].n++;
        }


        int n = 0;
        while (lettres_amount_list[n].lettre != '\0') {
            n++;
        }


        quicksort(lettres_amount_list, n, decroissant);


        int i = 0;
        while (lettres_amount_list[i].lettre != '\0') {
            printf("Caractère '%c' : %d\n", lettres_amount_list[i].lettre, lettres_amount_list[i].n);
            i++;
        }

    } else {
        printf("Erreur d'ouverture du fichier\n");
    }
    return;
}










int main() {
    Concat("dest.txt", "src1.txt", "src2.txt");

    StatFreq("dest.txt");

    return 0;
}