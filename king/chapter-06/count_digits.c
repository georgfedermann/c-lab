// Name: count_digits.c
// Purpose: Counts the digits of a given integer number
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int rv, input, digit_count = 0;
  printf("Enter a nonnegative integer: ");

  rv = scanf("%d", &input);
  if (rv != 1 || input < 0) {
    puts("\nError: bad input - expected a non-negative integer number");
    return EXIT_FAILURE;
  }

  do {
    input /= 10;
    digit_count++;
  } while (input > 0);

  printf("\nThe number has %d digit(s).\n", digit_count);

  return EXIT_SUCCESS;
}
