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
	int i = 0;
	int positives = 0;
	int negatives = 0;
	int length = sizeof(values[0]) / sizeof(int);
	for (int i = 0; i < length; i++) {
		if (values[i] > 0) {
			positives++;
		} else if (values[i] < 0) {
			negatives++;
		} else if (values[i] == 0) {
			break;
		}
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
	int a, b;
	int i, j;
	for (i = 0, j = length-1; j >= 0; i++, j--) {
		//FUCK YOU!
	}
}

/* Here is the main function for the program.  You should write
your own test code, which calls the lab functions with various inputs,
into the main function */
int main(void)
{
	printf("Hi there!  Nice to see you.\n");
	printf("Here is a test program for Lab 9.\n");

	int values[10] = {-1,-4,-2,-7,-1,-5,2,7,1,9};

	//test ex1
	printf("%d\n", CountOnes(values, 10));

	//test ex2
	printf("%d\n", LastIndexOf(1, values, 10));

	//test ex3
	printf("%d\n", SignBalance(values));

	//test ex4
	int values1[7] = {1,2,3,4,5,6,7};
	ReverseArray(values1, 7);
	for (int i = 0; i < 7; i++) {
		printf("%d ", values1[i]);
	}

	return 0;
}

