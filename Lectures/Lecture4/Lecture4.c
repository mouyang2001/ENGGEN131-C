#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int SumArray(int nums[10], int numElements) {
    int sum = 0;
    for (int i = 0; i < numElements; i++) {
        sum += nums[i];
    }

    nums[0] = 99;

    return sum;
}

void part1(void) {
    int numbers[10] = {2, 5, 1, 7, 3, 9, 8, 6, 0, 4};
    int result;
    result = SumArray(numbers, 10);
    printf("Sum = %d\n", result);

    printf("%d %d %d", numbers[0], numbers[1], numbers[2]);
}

void part2(void) {
    int a; 
    a = 10;

    //pointer is a variable that stores address &a
    int *p;
    p = &a;

    // * can dereference to what is stored there ie value of a
    printf("p points to the value %d", *p);
}

typedef struct {
    int widht;
    int height;
} Rectangle;

// variables and structures are pass by value
// so copy is stored in the stack
// NOTE arrays are pass by reference
void Change(int *a)
{
    *a += 1;
}

void part3(void) {
    int a;
    a = 10;

    // to overcome pass by value 
    // pass in address of variable instead of magnitude
    Change(&a);

    printf("a = %d", a);
}

int main(void) {
    // part1();
    // part2();
    part3();

    return 0;
}