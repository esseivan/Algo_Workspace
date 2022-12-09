/*
 * Fichier : ex2_1.c
 * Auteur : Esseiva Nicolas
 * Date : 09.12.2022
 * Description : Exercice 2.1, calculatrice simple avec utilisation des arguments
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum
{
    eArgumentCount = 4,
};

// Indique comment utiliser le programme à l'utilisateur
void InformationFormat()
{
    printf("ex2_1 <Arg1> <Op> <Arg2>\n");
    printf("\t- <Arg1> is first operand. This operand cannot be 0\n");
    printf("\t- <Op> is the operation [+ - x /] to be performed on the <Arg1> and <Arg2>\n");
    printf("\t- <Arg2> is second operand. This operand cannot be 0\n");
}

// Verifier la validité des arguments
bool VerifyArguments(double x, double y, char operation)
{
    bool valid = false;
    // Opérations valides
    if (('+' == operation) ||
        ('-' == operation) ||
        ('x' == operation) ||
        ('/' == operation))
        valid = true;

    if (false == valid)
    {
        printf("ERROR: Operation '%c' unknown.\n", operation);
        return false;
    }

    // un operand 0
    if ((0 == x) || (0 == y))
    {
        printf("ERROR: Operand is 0\n");
        return false;
    }

    return true;
}

// Calcul du résultat de l'opération
double GetResult(double x, double y, char operation)
{
    double result = x;

    if ('+' == operation)
        result += y;
    else if ('-' == operation)
        result -= y;
    else if ('x' == operation)
        result *= y;
    else // '/' dernier restant
        result /= y;

    return result;
}

int main(int argc, char *argv[])
{
    if (4 != argc)
    {
        printf("ERROR : Invalid argument count\n");
        InformationFormat();
        return -2;
    }

    double x = atof(argv[1]);
    double y = atof(argv[3]);
    char operation = argv[2][0];

    if (!VerifyArguments(x, y, operation))
    {
        InformationFormat();
        return -1;
    }

    double result = GetResult(x, y, operation);

    printf("Result of desired operation of %.4f %c %.4f = %.6f\n",
           x,
           operation,
           y,
           result);

    return 0;
}