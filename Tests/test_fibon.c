#include <stdio.h>

unsigned int fibolter(unsigned int n)
{
    if (n == 0)
        return 0;

    unsigned int t;
    unsigned int c1 = 0;
    unsigned int c2 = 1;

    for (unsigned int i = 1; i < n; i++)
    {
        t = c2;
        c2 += c1;
        c1 = t;
    }

    return c1 + c2;
}

unsigned int fibon(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibon(n - 1) + fibon(n - 2);
}

int main(void)
{
    // for (unsigned int i = 0; i < 20; i++)
    // {
    //     unsigned int x = fibolter(i);
    //     printf("%d, ", x);
    // }

    printf("Welcome\n");
    unsigned int lastValue;
    unsigned int i = 0;

    do
    {
        lastValue = fibon(i++);
        printf("%d, ", lastValue);
    } while (lastValue < 20);
    printf("... \n");

    return 0;
}