#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    printf("Hello World\n");

    int32_t var1 = 23;
    int32_t var2 = -554;
    int32_t var3 = var1+var2;

    printf("variables are : var1=%d and var2=%d\nAddition = %d\n", 
        var1, var2, var3);


/*
    uint32_t x = 2, y = 9;

    uint8_t z = x + y;

    printf("Result is %d \n", z);
    printf("y / x = %d \n", y/x);

    unsigned char b = 5;
    short s = 8;
    int i = 9;
    float f = 2.5;
    double d = 5.2;

    printf("%f \n",d/2);
    printf("%d \n",s*4);
    printf("%d \n",(b+s) > (5*f));
    printf("%f \n",i/4 + d);
    printf("%d \n",1/3);
    printf("%d \n",b&6);


    int j = 7, k = 4;
    bool a = true, b = true;

*/
    return 0;
}