#include <stdio.h>

// recurusion exercises

// 10 11 12 13 14 15 16 17
void printBetween(int low, int high) {
    if (low == high) {
        printf("%d ", low);
    } else {
        printf("%d ", low);
        printBetween(low+1, high);
    }
}

int arraySum(int *values, int startIndex, int endIndex) {
    if (startIndex == endIndex) {
        return values[startIndex];
    } else {
        return values[endIndex] + arraySum(values, startIndex, endIndex-1);
    }
}

// s: start, d: destination, t: transition
void hanoi(int n, char s, char d, char t) {
    if (n == 1) {
        printf("Move from %c to %c\n", s, d);
    } else {
        hanoi(n-1, s, t, d);
        printf("Move from %c to %c\n", s, d);
        hanoi(n - 1, t, d, s);
    }
}

int main(void) {

    int values[10] = {4,2,7,8,1,3,9,5,10,6};

    printf("Lecture 10: Recursion exercises:\n");

    printBetween(10,20);

    printf("\nArray sum = %d\n", arraySum(values, 0, 9));

    hanoi(4, 'A', 'C', 'B');

    return 0;
}