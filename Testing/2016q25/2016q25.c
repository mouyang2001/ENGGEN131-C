#include<stdio.h>

int Exam(int a, int b)
{
    int i;
    int sum = 0;
    for (i = a; i < b; i++)
    {
        printf("%d\n", i);
        sum = sum + (b - a);
    }
    return sum;
}

int main(void) {
    printf("%d", Exam(1,5));
    return 0;
}

