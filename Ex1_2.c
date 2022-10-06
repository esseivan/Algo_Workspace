#include <stdio.h>
#include <stdint.h>
#include "GetFact.h"

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

