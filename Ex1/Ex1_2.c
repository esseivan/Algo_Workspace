#include <stdio.h>
#include <stdint.h>

u64_t Factorial_Iteration(u8_t n);
u64_t Factorial_Recursion(u8_t n);
u64_t getFactWithTable(u8_t n);

// c)

#define cFact0 1
#define cFact1

int main(void) {

    // a) 
    u8_t n = 20;
    u64_t result;
    for (u8_t i = 0; i <= n; i++)
    {
        result = Factorial_Iteration(i);
        printf("The factorial of %2d using loop is: %llu \r\n", i, result);
    }
    
    // b)
    n = 20;

    for (u8_t i = 0; i <= n; i++)
    {
        result = Factorial_Recursion(i);
        printf("The factorial of %2d using loop is: %llu \r\n", i, result);
    }
    
    // c)
    n = 20;

    for (u8_t i = 0; i <= n; i++)
    {
        result = getFactWithTable(i);
        printf("The factorial of %2d using loop is: %llu \r\n", i, result);
    }

    return 0;
}

u64_t Factorial_Iteration(u8_t n) {
    u64_t result = 1;
    for (u8_t i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}

u64_t Factorial_Recursion(u8_t n) {
    if (n == 0) return 1;
    return (u64_t)n*Factorial_Recursion(n-1);
}

u64_t getFactWithTable(u8_t n) {
    static u64_t FactTable[] = {
        1ull,
        1ull*1,
        1ull*1*2,
        1ull*1*2*3,
        1ull*1*2*3*4,
        1ull*1*2*3*4*5,
        1ull*1*2*3*4*5*6,
        1ull*1*2*3*4*5*6*7,
        1ull*1*2*3*4*5*6*7*8,
        1ull*1*2*3*4*5*6*7*8*9,
        1ull*1*2*3*4*5*6*7*8*9*10,
        1ull*1*2*3*4*5*6*7*8*9*10*11,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12*13,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12*13*14,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12*13*14*15,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12*13*14*15*16,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18*19,
        1ull*1*2*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18*19*20,
        // etc...
    };
    return FactTable[n];
}