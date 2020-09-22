#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int largeCap, smallCap, items;
    int large, small, remainder;
    printf("Large capacity:\n");
    scanf("%d", &largeCap);

    printf("Small capacity:\n");
    scanf("%d", &smallCap);

    printf("Number of items:\n");
    scanf("%d", &items);

    large = items/largeCap;
    small = (items % largeCap) / smallCap;
    remainder = items - large*largeCap - small*smallCap;

    printf("Allocated:\n - Large: %d\n - Small: %d\n - Scrap: %d\n", large, small, remainder);
    return 0;
}

