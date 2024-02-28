#include <stdio.h>
#include <math.h>

int main()
{
    int x1 = 1, x2 = 2, y1 = 3, y2 = 4;
    float dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    printf("The distance between the points (%d,%d) and (%d,%d) is %f", x1, y1, x2, y2, dist);
    return 0;
}