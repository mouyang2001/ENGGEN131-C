#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ConvertToBinary(int n)
{
	if (n == 1) {
		printf("%d", 1);
	} else {
		ConvertToBinary(n/2);
		printf("%d", n % 2);
	}
}

int main(void)
{
	int input;

	printf("Lab 12 - Exercise Two\n");

	printf("Enter the decimal number to convert: ");
	scanf("%d", &input);

	printf("%d in binary is: ", input);
	ConvertToBinary(input);

	printf("\n");

	return 0;
}

