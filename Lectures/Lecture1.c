#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// predefine so that TAXRATE always becomes 12.5
#define TAXRATE 12.5

int main(void)
{
    int input, minutes, seconds;

    printf("Please enter a number of seconds: ");
    scanf("%d", &input);

    minutes = input / 60;
    seconds = input % 60;

    printf("There are %d mins and %d seconds in %d seconds", minutes, seconds, input);

    return 0;
}