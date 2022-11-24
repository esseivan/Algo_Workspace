#include <stdio.h>

typedef struct
{
    int x;
} test_t;

void test1(test_t x)
{
    x.x = 50;
    printf("%p\n", &x);
}

void test2(test_t *x)
{
    x->x = 50;
    printf("%p\n", x);
}

int main(void)
{
    test_t var = {1};

    printf("%p\n", &var);
    test1(var);
    test2(&var);
    printf("%d", var.x);

    return 0;
}