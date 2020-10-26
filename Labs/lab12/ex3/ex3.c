#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Choose(int n, int m)
{
	if (m == 0 || m == n) {
		return 1;
	} else {
		return Choose(n-1, m) + Choose(n-1, m-1);
	}
}

int main(void)
{
	int n, m;

	printf("Lab 12 - Exercise Three\n");

	printf("Enter the value of n: ");
	scanf("%d", &n);
	printf("Enter the value of m: ");
	scanf("%d", &m);

	printf("%d choose %d is: %d", n, m, Choose(n, m));

	printf("\n");

	return 0;
}

