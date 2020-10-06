#include <stdio.h>

/* This file contains the function definitions for Lab 9.
Initially, each function definition is "commented out".
This means that a comment (//) is used to remove the code
from the program.  When you are ready to implement a task,
just "un-comment" it, and then write some test code in the
main function to test it.  When you are ready, you can then
mark your function using CodeRunner - remember you only need
to submit the function definition to CodeRunner.
*/

int CountOnes(int values[], int numValues)
{
	int count = 0;
	for (int i = 0; i < numValues; i++) {
		if (values[i] == 1) {
			count++;
		}
	}
	return count;
}

int LastIndexOf(int search, int values[], int numValues)
{
	for (int i = numValues-1; i >= 0; i--) {
		if (values[i] == search) {
			return i;
		}
	}
	return -1;
}

int SignBalance(int values[])
{
	int positives = 0;
	int negatives = 0;
	int i = 0;
	while (values[i] != 0) {
		if (values[i] > 0) {
			positives++;
		} else if (values[i] < 0) {
			negatives++;
		}
		i++;
	}

	if (positives > negatives) {
		return 1;
	} else if (positives < negatives) {
		return -1;
	} else {
		return 0;
	}
}

void ReverseArray(int *values, int length)
{
	int temp;
	int i, j;
	for (i = 0, j = length-1; i < j; i++, j--) {
		temp = values[i];
		values[i] = values[j];
		values[j] = temp;
	}
}

/* Here is the main function for the program.  You should write
your own test code, which calls the lab functions with various inputs,
into the main function */
int main(void)
{
	printf("Hi there!  Nice to see you.\n");
	printf("Here is a test program for Lab 9.\n");

	int values[5] = {1, 2, 0, 2, 1};

	//test ex1
	printf("Count 1s: %d\n", CountOnes(values, 10));

	//test ex2
	printf("Last Index of: %d\n", LastIndexOf(2, values, 5));

	//test ex3

	int vals[7] = {-1,-1,1,1,1,-1, 0};
	printf("Sign balance: %d\n", SignBalance(vals));

	//test ex4
	ReverseArray(vals, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", vals[i]);
	}

	return 0;
}

