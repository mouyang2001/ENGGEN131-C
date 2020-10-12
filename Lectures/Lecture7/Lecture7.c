#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <time.h>

// Tuesday 13/10/2020

int main(void)
{
    int r;

    // set starting random number using clock time
    srand((unsigned int) time(NULL));

    // random in range a to b
    int a = 10;
    int b = 20;
    int random = (rand() % (b-a+1)) + a;

    r = rand();
    printf("%d\n", r);
    printf("RAND_MAX: %d", RAND_MAX);

    return 0;
}