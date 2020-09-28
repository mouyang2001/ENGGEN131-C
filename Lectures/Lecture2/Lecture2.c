#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// structure types
typedef struct {
    int x;
    int y;
} Point;

// example of fundamental theorem of arithmetic
int main(void)
{
    int factors[100] = {0};
    int numFactors = 0;

    int input; 
    printf("Enter a value between 50 and 200: ");
    scanf("%d", &input);

    // check if between 50 and 200?
    while (input < 50 || input > 200) {
        printf("Please enter valid value: ");
        scanf("%d", &input);
    }

    int n, p;
    n = input;
    p = 2;

    while (n > 1) {
        if (n % p == 0) {
            n = n/p;

            factors[numFactors] = p;
            numFactors++;
        } else {
            p++;
        }
    }

    for (int i = 0; i < numFactors; i++) {
        printf("%d ", factors[i]);
    }

    return 0;
}