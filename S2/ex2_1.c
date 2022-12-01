#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum
{
    eArgumentCount = 4,
};

typedef struct
{
    double x;
    double y;
    char operation;
} calculator_t;

void InformationFormat()
{
    printf("ex2_1.exe <Arg1> <Op> <Arg2>\n");
    printf("\t- <Arg1> is first operand\n");
    printf("\t- <Op> is the operation [+ - x /] to be performed on the <Arg1> and <Arg2>\n");
    printf("\t- <Arg2> is second operand\n");
}

bool VerifyArguments(calculator_t *arguments)
{
    bool valid = false;
    // Opérations valides
    if (('+' == arguments->operation) ||
        ('-' == arguments->operation) ||
        ('x' == arguments->operation) ||
        ('/' == arguments->operation))
        valid = true;

    if (false == valid)
    {
        printf("Operation '%c' inconnue.\n", arguments->operation);
        InformationFormat();
        return false;
    }

    // Division par 0
    if ('/' == arguments->operation)
        if (0 == arguments->y)
        {
            printf("Division par 0 impossible !\n");
            return false;
        }

    return true;
}

double GetResult(calculator_t *parameters)
{
    if ('+' == parameters->operation)
        return parameters->x + parameters->y;
    if ('-' == parameters->operation)
        return parameters->x - parameters->y;
    if ('x' == parameters->operation)
        return parameters->x * parameters->y;
    // if ('/' == parameters->operation)
    return parameters->x / parameters->y;
}

int main(int argc, char *argv[])
{
    if (4 != argc)
    {
        printf("ERROR : Invalid argument count\n");
        InformationFormat();
        return 1;
    }

    double number1 = atof(argv[1]);
    double number2 = atof(argv[3]);
    char operation = argv[2][0];

    calculator_t parameters = {number1,
                               number2,
                               operation};

    if (!VerifyArguments(&parameters))
        return 2;

    double result = GetResult(&parameters);

    printf("%f %c %f = %f\n",
           parameters.x,
           parameters.operation,
           parameters.y,
           result);

    return 0;
}