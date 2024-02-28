#include <stdio.h>
#include <math.h>

int main() {
    printf("Entrez un caractère : ");
    char a;
    scanf("%c",&a);
    printf("Le caractère '%c' a le code ascii %d et le code hexadécimal %X", a, a, a);
    return 0;
}