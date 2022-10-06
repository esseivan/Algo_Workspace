#include "GetFact.h"
#include <stdio.h>

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