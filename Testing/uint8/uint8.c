#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

//for testing uint8 operations

int main(void)
{   
    uint8_t a = 255;
    uint8_t b = 15;
    uint8_t out = a + b;
    printf("%d", out);

    return 0;
}

