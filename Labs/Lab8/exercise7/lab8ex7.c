#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// You can assume the converted number will have fewer digits than MAX_SIZE
#define MAX_SIZE 100

int main(void)
{
    int bits[MAX_SIZE];
    int numBits = 0;

    int input;
    printf("Enter a number:\n");
    scanf("%d", &input);
    while (input > 0)
    {   
        bits[numBits] = input % 2;
        numBits++;

        input = input / 2;
    }

    for (int i = numBits-1; i >= 0; i--)
    {
        printf("%d", bits[i]);
    }

    return 0;
}
