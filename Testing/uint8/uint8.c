#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t a = 42;
    uint8_t b = 19;
    uint8_t out = a%b;

    printf("%d", out);

    return 0;
}