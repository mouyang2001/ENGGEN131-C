#include <stdio.h>

/*
Start from the main() function. 
Establish the variables: 'sum' starts at 0 and 'values' an array containing 8 integers.
These are fed into 'aFunction()', NOTE that 'sum' is fed in as a pointer, '&sum', which allows us to directly modify it's value in memory.
Within 'aFunction', a For loop iterates through the FIRST 7 numbers in 'values' array ( hence excluding the last integer, 4 ) and add it all onto 'sum' variable.
Finally we print the value of 'sum' into the console, which is equal to 28 (1 + 6 + 7 + 2 + 9 + 0 + 3).
*/

// what is the output of this code?

void aFunction(int a[], int *b)

{
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", b);
        printf("%d ", *b);
        *b += a[i];
    }
}

int main(void)
{
    int sum = 0;
    int values[8] = {1, 6, 7, 2, 9, 0, 3, 4};

    aFunction(values, &sum);

    printf("%d", sum);

    return 0;
}
