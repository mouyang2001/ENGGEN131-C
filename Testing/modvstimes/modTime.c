#include<stdio.h>

#define A 1 + 2
#define B 5
#define C 2 * 3

int main(void) 
{
    int i, j;
    double k;
    i = 4+5%3;
    j = (int) 1.9999;
    k = 4/3;

    int x = A*B;
    int y = B+C;

    printf("%d %d %f\n", i, j, k);
    printf("%d %d", x, y);
    return 0;
}