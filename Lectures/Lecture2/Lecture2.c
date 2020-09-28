#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// predefine so that TAXRATE always becomes 12.5
#define TAXRATE 12.5

int main(void)
{
    int x;
    double z;

    x = 10;
    z = 5.5;

    printf("%d %f", x, z);

    return 0;
}