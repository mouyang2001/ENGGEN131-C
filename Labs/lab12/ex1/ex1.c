#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void PrintReverse(int n)
{
	if (n < 10) {
		printf("%d", n);
	} else {
		printf("%d", n%10);
		PrintReverse(n/10);
	}
}

int main(void)
{
	int input;

	printf("Lab 12 - Exercise One\n");

	printf("Enter the number to reverse: ");
	scanf("%d", &input);

	printf("%d in reverse is: ", input);
	PrintReverse(input);

	printf("\n");

	return 0;
}
