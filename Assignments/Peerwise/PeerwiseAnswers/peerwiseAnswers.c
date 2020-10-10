#include <stdio.h>

int Foo(int a)
{
    a = a + a;
    printf("Foo = %d, ", a);
    return a;
}

int main(void)
{
    int a = 10;

    a = Foo(a);

    printf("main = %d ", a);

    return 0;
}