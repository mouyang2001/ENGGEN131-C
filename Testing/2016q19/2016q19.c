#include <stdio.h>
void Process(int a, int *b)
{
    a = a + *b;
    *b = *b + a;
}
int main(void)
{
    int a = 1;
    int b = 10;
    Process(a, &b);
    printf("Result = %d %d\n", a, b);
    return 0;
}