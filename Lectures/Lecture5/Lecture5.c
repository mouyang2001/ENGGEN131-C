#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int CountNegatives(int values[], int numValues)
{
    int count = 0;
    for (int i = 0; i < numValues; i++) {
        if (values[i] < 0) {
            count++;
        }
    }
    return count;
}

void part1(void) {
    int values[10] = {4, 3, 7, 1, 2, 9, 0, 6, 3, 8};
    printf("Answer = %d\n", CountNegatives(values, 5));
    printf("Answer = %d\n", CountNegatives(values, 10));
}

void part2(void) {
    int values[5][3] = {0};
    
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", values[row][col]);
        }
        printf("\n");
    }
    
}

void FindIndex(int find, int *pos, int values[], int length) {
    for (int i = 0; i < length; i++) {
        if (values[i] == find) {
            *pos = i;
            return;
        }
    }
    *pos = -1;
}

void part3(void) {
    int values[10] = {8,3,7,1,2,-9,0,6,-3,8};
    int index;
    FindIndex(-9, &index, values, 10);

    printf("The value is at index %d\n", index);
}

void part4(void) {
    double a = 12.5;
    double result = sqrt(a);
    printf("%f", result);
}

int main(void)
{
    // part1();
    // part2();
    // part3();
    part4();
    
    return 0;
}