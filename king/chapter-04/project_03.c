// Name: project_03.c
// Purpose: Read a three digit number and reverse it without using arithmetic
// expressions. Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int digit_1, digit_2, digit_3, rv;

  printf("This program reads a three digit number and prints its reverse.\n");
  printf("Enter a three digit number: ");
  rv = scanf("%1d%1d%1d", &digit_1, &digit_2, &digit_3);

  if (rv != 3) {
    printf(
        "Error: bad input - expected three digits or a three digit number\n");
    return EXIT_FAILURE;
  }
  printf("%d%d%d\n", digit_3, digit_2, digit_1);

  return EXIT_SUCCESS;
}
