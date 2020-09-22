#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{   
    int total, winners;
    double shared;

    printf("Total:\n");
    scanf("%d", &total);
    printf("Winners:\n");
    scanf("%d", &winners);
    
    shared = (double)total/winners;

    printf("Shared: $%.2f", shared);

    return 0;
}

