#include <stdio.h>
#include <string.h>

int Test(int *values, int length)
{
    int i;
    int test = values[0];
    for (i = 1; i < length; i++)
    {
        if (test < values[i])
        {
            test = values[i];
        }
    }
    return test;
}

int main(void)
{
    int numbers[5] = {1, 2, 3, 4, 5};
    for (int i = 4; i >= 0; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return 0;
}