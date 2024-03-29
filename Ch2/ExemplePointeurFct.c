// Exemple d'utilisation de pointeurs de fonctions
//

#include <stdio.h>
#include <assert.h>

// Fonctions d'opération
long int mult(int val1, int val2);
long int div(int val1, int val2);
long int add(int val1, int val2);
long int sub(int val1, int val2);

// Fonctions d'affichage
void print_mult(int val1, int val2);
void print_div(int val1, int val2);
void print_add(int val1, int val2);
void print_sub(int val1, int val2);

typedef long int (*pFctOp_t)(int, int);
typedef void (*pFctPrintOp_t)(int, int);
pFctOp_t TabFctOp[] = {mult, div, add, sub};
pFctPrintOp_t TabFctPrint[] = {print_mult, print_div, print_add, print_sub};
// pFctOp TabFct[] = {&mult, &div, &add, &sub};
int FctNb = sizeof(TabFctOp) / sizeof(TabFctOp[0]);

int main(void)
{
    int x = 360;
    int y = 0;

    for (int i = 0; i < FctNb; i++)
    {
        assert(NULL != TabFctOp[i]);
        // pFctOp pointeurFct = TabFct[i];
        long int result = TabFctOp[i](x, y);
        TabFctPrint[i](x, y);
        printf(" = %ld\n", result);
    }

    return 0;
}

long int mult(int val1, int val2)
{
    return (long int)val1 * (long int)val2;
}
long int div(int val1, int val2)
{
    assert(0 != val2);
    return (long int)val1 / (long int)val2;
}
long int add(int val1, int val2)
{
    return (long int)val1 + (long int)val2;
}
long int sub(int val1, int val2)
{
    return (long int)val1 - (long int)val2;
}

void print_mult(int val1, int val2)
{
    printf("%d * %d", val1, val2);
}
void print_div(int val1, int val2)
{
    printf("%d / %d", val1, val2);
}
void print_add(int val1, int val2)
{
    printf("%d + %d", val1, val2);
}
void print_sub(int val1, int val2)
{
    printf("%d - %d", val1, val2);
}