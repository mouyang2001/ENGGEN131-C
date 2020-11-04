#include<stdio.h>

void Print(int n)
{
    if (n == 0)
    {
        printf("Done      ");
    }
    else
    {
        Print(n - 1);
    }
}

int main(void) {
    int a = 5;
    int b = 13;
    int c = 5/13;
    printf("%d\n", c);

    int n = 5;
    int row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (row > col)
            {
                printf("*");
            }
        }
        printf("\n");
    }

    Print(3);
    
}

