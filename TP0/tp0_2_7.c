#include <stdio.h>
#include <math.h>

int main() {
    int a,b,c;
    printf("Entrez la valeur de A : ");
    scanf("%d", &a);
    printf("Entrez la valeur de B : ");
    scanf("%d", &b);
    printf("Entrez la valeur de C : ");
    scanf("%d", &c);
    float delta = pow(b,2)-4*a*c;
    if (delta > 0) {
        float result1 = (-1*b - sqrt(delta)) / 2*a;
        float result2 = (-1*b + sqrt(delta)) / 2*a;
        printf("L'équation a deux solutions : %f et %f", result1, result2);
    } else if (delta == 0) {
        float result = -1*b / 2*a;
        printf("L'équation a une solution : %f", result);
    } else {
        printf("L'équation n'a pas de solutions");
    }
    return 0;
}