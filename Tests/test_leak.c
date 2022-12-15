
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char q = '\0';
    printf("Confirm continue. Your computer may crash. Continue ? [y/n]\n");
    scanf("%c", &q);
    if (q != (char)'y')
        return -1;

    int kB = 1;
    int *pRec;
    do
    {
        pRec = (int *)malloc(1 << 10);
        kB++;
    } while (NULL != pRec);
    printf("Allocated %ukB \n", kB);
    return 0;
}