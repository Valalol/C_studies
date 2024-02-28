#include <stdio.h>

int main()
{
    int a,b,c,d;
    printf("Entrez la valeur de A : ");
    scanf("%d", &a);
    printf("Entrez la valeur de B : ");
    scanf("%d", &b);
    printf("Entrez la valeur de C : ");
    scanf("%d", &c);
    d = a;
    a = b;
    b = c;
    c = d;
    printf("Nouvelle valeur de A : %d\nNouvelle valeur de B : %d\nNouvelle valeur de C : %d", a,b,c);
    return 0;
}