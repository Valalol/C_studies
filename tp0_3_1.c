#include <stdio.h>

void pretty_print(int *tab, int height, int width) {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", *(tab + i * width + j));
        }
        printf("\n");
    }
}


int main() {
    int height = 8, width = 7;
    int tab[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            tab[i][j] = (i+1)*10 + j+1;
        }
    }

    pretty_print(*tab, height, width);

    return(0);
}