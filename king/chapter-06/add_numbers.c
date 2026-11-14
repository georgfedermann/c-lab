// Name: add_numbers.c
// Purpose: add up numbers as entered by the user
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int input, sum = 0, rv;
  puts("This program sums a series of integers.");
  printf("Enter integers (0 to terminate): ");
  fflush(stdout);

  do {
    rv = scanf("%d", &input);

    sum += input;
  } while (input != 0);

  printf("The sum is: %d\n", sum);

  return EXIT_SUCCESS;
}
