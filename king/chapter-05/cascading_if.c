// Name: cascading_if.c
// Purpose: Demonstrate series of checks and formatting of nested if statements.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, rv;
  printf("This program plays with cascading checks on values.\n");
  printf("It asks the user to enter a number and checks if its negative, zero "
         "or positive.\n");
  printf("Enter an integer number: ");
  rv = scanf("%d", &n);
  if (rv != 1) {
    printf("Error: bad input - expected one integer number.\n");
    return EXIT_FAILURE;
  }
  if (n < 0)
    printf("%d is negative.\n", n);
  else if (n == 0)
    printf("%d is equal to 0.\n", n);
  else
    printf("%d is positive.\n", n);

  return EXIT_SUCCESS;
}
