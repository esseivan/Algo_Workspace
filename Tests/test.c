#include <stdio.h>
#include <stdlib.h>

int *myFunc(void)
{
    static int varD = 3;
    varD++;
    printf("func \t%p\n", &varD);
    return &varD;
}

int main(void)
{
    static int bss1;
    static int bss2;
    static int data1 = 1;
    static int data2 = 1;

    int *p = myFunc();

    printf(".bss\t%p %p\n", &bss1, &bss2);
    printf(".data\t%p %p\n", &data1, &data2);

    myFunc();

    return 0;
}
