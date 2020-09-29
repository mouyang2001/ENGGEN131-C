#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// functions should always be above
int GetInputValue(void)
{
    int input;
    printf("Enter input value: ");
    scanf("%d", &input);
    return input;
}

int SumOfIntegers(int limit)
{
    int sum = 0;
    for (int i = 1; i < limit; i++) {
        sum = sum + i;
    }
    return sum;
}

// example of fundamental theorem of arithmetic
int main(void)
{
    int input, result;
    input = GetInputValue();
    result = SumOfIntegers(input);
    printf("Sum of all integers less");
    printf(" Than %d is %d", input, result);
    return 0;
}