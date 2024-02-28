#include <stdio.h>
#include <math.h>

int main()
{
    int a = 2;
    char b = '2';
    float c = 2.0;
    long double d = 2;
    printf("Size of int : %do \n", sizeof(a));
    printf("Size of char : %do \n", sizeof(b));
    printf("Size of float : %do \n", sizeof(c));
    printf("Size of long double : %do \n", sizeof(d));
    return 0;
}