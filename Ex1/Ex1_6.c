#include <stdio.h>
#include <stdint.h>

float converter(float valD)
{
    return (valD * 1.8) + 32.0;
}

int main(void)
{
    char const cDeg = 0xF8;
    // a
    printf("%cC to %cF converter !\n", cDeg, cDeg);
    // N'imprime pas les ° pour certaines raisons inconnues ???

    float valD = 10.0;
    float valF = valD * 1.8 + 32.0;

    // printf("Value of %.2f%cC corresponds to %.2f%cF\r", valD, cDeg, valF, cDeg);

    // b
    valF = converter(valD);

    // c
    for (int i = -20; i <= 30; i++)
    {
        valF = converter((float)i);
        printf("Value of %+02.1f%cC corresponds to %+2.1f%cF\n", (float)i, cDeg, valF, cDeg);
    }

    return 0;
}