// Name: exercise_04.c
// Purpose: Write a single expression whose value is either -1, 0, or +1
//          depending on whether i is less than, equal, or greater than j,
//          respectively.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j, rv;
  printf("The user enters two integer number i, j and the program prints -1,\n"
         "0, or +1, depending on whether i is less than, equal to, or\n"
         "greater than j\n");

  printf("Enter 2 integer numbers: ");
  rv = scanf("%d %d", &i, &j);
  printf("Debug: i: %d, j: %d, rv: %d\n", i, j, rv);

  if (rv != 2) {
    printf("Error: bad input - expected two integer numbers.\n");
    return EXIT_FAILURE;
  }

  printf("%d\n", i < j ? -1 : i == j ? 0 : 1);

  return EXIT_SUCCESS;
}
