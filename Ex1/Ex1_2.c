#include <stdio.h>
#include <stdint.h>

uint64_t Factorial_Iteration(uint8_t n);
uint64_t Factorial_Recursion(uint8_t n);

int main(void) {

    // a) 
    uint8_t n = 20;
    uint64_t result;
    for (uint8_t i = 0; i <= n; i++)
    {
        result = Factorial_Iteration(i);
        printf("The factorial of %2d using loop is: %llu \r\n", i, result);
    }
    
    // b)
    n = 20;
    result = Factorial_Recursion(n);

    for (uint8_t i = 0; i <= n; i++)
    {
        result = Factorial_Recursion(i);
        printf("The factorial of %2d using loop is: %llu \r\n", i, result);
    }

    return 0;
}

uint64_t Factorial_Iteration(uint8_t n) {
    uint64_t result = 1;
    for (uint8_t i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}

uint64_t Factorial_Recursion(uint8_t n) {
    if (n == 0) return 1;
    return n*Factorial_Recursion(n-1);
}