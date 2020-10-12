#include <stdio.h>

int main(void)
{

    int x = 3;
    int y = 27;

    for (int i = 1; x < y; i++)
    {
        x = i * x;
    }

    printf("The new value of 'x' is: %d", x);

    return 0;
}