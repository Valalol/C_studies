#include <stdio.h>

int main() {
    int a,b,q,r;
    printf("Entrez la valeur de A : ");
    scanf("%d", &a);
    printf("Entrez la valeur de B : ");
    scanf("%d", &b);
    r = a;
    q = 0;
    while (r>=b) {
        r -= b;
        q += 1;
    }
    printf("%d = %d * %d + %d", a,b,q,r);
    return 0;
}