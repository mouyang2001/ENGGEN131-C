#include<stdio.h>

int main(void) {
    int n = 5;
    int row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (row <= col)
            {
                printf("(%d, %d)", row, col);
            }
        }
        printf("\n");
    }
    return 0;
}
