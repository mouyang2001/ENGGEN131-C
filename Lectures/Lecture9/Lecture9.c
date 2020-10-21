#include<stdio.h>

// Recursion

int Sum(int n) {
    printf("Calling Sum(%d)\n", n);
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result+=i;
    }

    return result;
}

// recursive case must progress to recursive case
int Sum2(int n) {
    printf("Calling Sum2(%d)\n", n);
    // base case
    if (n == 0) 
    {
        return 0;
    }
    // the recursive case
    else {
        
        return n + Sum2(n - 1);
    }
}


// exponentially becomes more difficult
// 1.4 billion function calls just to get 45th fibonacci number
int Fibonacci(int n) {
    // base case
    if (n <= 2) {
        return 1;
    } 
    // recursive case
    else {
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
}

int main(void) {
    printf("Sum = %d \n", Sum2(10));
    return 0;
}