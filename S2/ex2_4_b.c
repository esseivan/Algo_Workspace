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
    scanf("%s", Argument);
    printf("\n");

    // atof convertit un string en un double. Retourne 0 si erreur
    return atof(Argument);
}

int main(void)
{
    printf("Welcome ! Enter two number to be added together.\n");

    char Text1[] = "\nPlease enter first operand : ";
    char Text2[] = "\nPlease enter second operand : ";

    double Number1 = myfunc(Text1);
    double Number2 = myfunc(Text2);
    double Result = Number1 + Number2;

    printf("\nResult of %f + %f = %f", Number1, Number2, Result);

    return 0;
}