// Name: project_01.c
// Purpose: Count the digits a number contains.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int number, rv, counter = 0, tmp;
  printf("This program prints the number of digits of a given number.\n");

  printf("Enter an integer number: ");
  rv = scanf("%d", &number);

  if (rv != 1) {
    printf("Error: bad input - expected one integer number.\n");
    return EXIT_FAILURE;
  }

  tmp = number;
  do {
    counter++;
    tmp /= 10;
  } while (tmp != 0);

  printf("The number %d has %d digits.\n", number, counter);

  return EXIT_SUCCESS;
}
