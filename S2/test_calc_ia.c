#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  // Vérifie qu'il y a au moins 3 arguments
  if (argc < 3) {
    printf("Usage: Algo-Ex2_1-CommandLine <Arg1> <Op> <Arg2> [<Op> <Arg3>...]\n");
    return 1;
  }

  // Concatène tous les arguments en une chaîne
  char* input = argv[1];
  for (int i = 2; i < argc; i++) {
    input = strcat(input, " ");
    input = strcat(input, argv[i]);
  }

  // Évalue l'expression en utilisant l'algorithme de Shunting-Yard
  int result = 0;
  int arg1 = 0;
  char op = '+';
  int arg2 = 0;
  int i = 0;
  while (input[i] != '\0') {
    // Lit l'opérande ou l'opérateur
    if (input[i] >= '0' && input[i] <= '9') {
      // Lecture d'un opérande
      int value = 0;
      while (input[i] >= '0' && input[i] <= '9') {
        value = value * 10 + (input[i] - '0');
        i++;
      }
      // Effectue l'opération précédente
      if (op == '+') {
        result += arg1;
      } else if (op == '-') {
        result -= arg1;
      } else if (op == 'x') {
        result *= arg1;
      } else if (op == '/') {
        result /= arg1;
      }
      // Prépare l'opération suivante
      arg1 = value;
      op = '+';
      arg2 = 0;
    } else if (input[i] == '+' || input[i] == '-' || input[i] == 'x' || input[i] == '/') {
      // Lecture d'un opérateur
      op = input[i];
      i++;
    } else if (input[i] == '(') {
      // Ouvre une parenthèse, on saute l'opé
