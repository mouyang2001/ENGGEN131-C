#include <stdio.h>

// The following structure definition is provided for Exercise 3
typedef struct {
	int width;
	int height;
} Rectangle;

/* This file contains the function definitions for Lab 8.
Initially, each function definition is "commented out".
This means that a comment (//) is used to remove the code
from the program.  When you are ready to implement a task,
just "un-comment" it, and then write some test code in the
main function to test it.  When you are ready, you can then
mark your function using CodeRunner (remember for Exercises
1 to 6, you only need to submit the function definition
to CodeRunner, not the main function).
*/

void PrintSquare(int n)
{
	printf("%d", n*n);
}

int Square(int n)
{
	return n*n;
}

int LargerRectangle(Rectangle r1, Rectangle r2)
{
	int a1 = r1.width * r1.height;
	int a2 = r2.width * r2.height;
	return a1 >= a2 ? a1 : a2;
}

int SumBetween(int low, int high)
{	
	int sum = 0;
	// note shouldn't put low directly in
	// code runner hates it
	for (int i = low; i <= high; i++)
	{
		sum = sum + i;
	} 
	return sum;
}

int LargestRoom(int carpetArea)
{
	int n = 0;
	while (n*n <= carpetArea) {n++;}
	return n-1; 
}

int MiddleOfThree(int a, int b, int c)
{
	if ((c <= b && b <= a) || (a <= b && b <= c))
	{
		return b;
	}
	else if ((c <= a && a <= b) || (b <= a && a <= c)) {
		return a;
	} else {
		return c;
	}
}

/* Here is the main function for the program.  You should write
your own test code, which calls the lab functions with various inputs,
into the main function */
int main(void)
{
	printf("Hi there!  Nice to see you.\n");
	printf("Here is a test program for Lab 8.\n");

	// test ex1
	// PrintSquare(5);

	// test ex2
	// int result;
	// result = Square(5);
	// printf("Result = %d", result);

	// test ex3
	// Rectangle r1, r2;
	// r1.width = 5;
	// r1.height = 21;
	// r2.width = 10;
	// r2.height = 10;

	// int result = LargerRectangle(r1,r2);
	// printf("Result = %d", result);

	// test ex4
	printf("%d", SumBetween(-10, 0));

	// test ex5
	// printf("%d\n", LargestRoom(0));
	// printf("%d\n", LargestRoom(99));
	// printf("%d\n", LargestRoom(100));
	// printf("%d\n", LargestRoom(101));

	// test ex6
	// int result = MiddleOfThree(5, 5, 10);
	// printf("%d", result);

	return 0;
}

