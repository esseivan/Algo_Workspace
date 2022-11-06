// Converter Celsius to Fahrenheit


#include <stdio.h>
#include <stdint.h>

float convert_c_to_f(float val_c)
{
    return (val_c * 1.8) + 32.0;
}

int main(void)
{
    char const cDeg = 0xF8;
    // a
    printf("%cC to %cF converter !\n", cDeg, cDeg);
    // N'imprime pas les ° pour certaines raisons inconnues ???

    float val_c = 10.0;
    float val_f = val_c * 1.8 + 32.0;

    // printf("Value of %.2f%cC corresponds to %.2f%cF\r", val_c, cDeg, val_f, cDeg);

    // b
    val_f = convert_c_to_f(val_c);

    // c
    for (int i = -20; i <= 30; i++)
    {
        val_f = convert_c_to_f((float)i);
        printf("Value of %+5.1f%cC corresponds to %+5.1f%cF\n", (float)i, cDeg, val_f, cDeg);
    }

    return 0;
}