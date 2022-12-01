#include <stdio.h>
#include <stdlib.h>

enum
{
    eArgumentSize = 80
};

double myfunc(char *Text)
{
    char Argument[eArgumentSize];
    printf("%s", Text);
    scanf("\s", Argument);
    printf("\n");
    return atof(Argument);
}

int main(void)
{
    printf("Welcome ! Enter two number to be added together.\n");

    char Argument1[eArgumentSize];
    char Argument2[eArgumentSize];

    printf("\nPlease enter first operand : ");
    scanf("%s", Argument1);

    printf("\nPlease enter second operand : ");
    scanf("%s", Argument2);

    // atof convertit un string en un double. Retourne 0 si erreur
    double Number1 = atof(Argument1);
    double Number2 = atof(Argument2);
    double Result = Number1 + Number2;

    printf("\nResult of %f + %f = %f", Number1, Number2, Result);

    return 0;
}