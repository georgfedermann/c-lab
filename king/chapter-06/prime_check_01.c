// Name: prime_check_01.c
// Purpose: Look for divisors of a given number, demo `break` statement
// Author: Georg

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int number = 143, d, limit;

  printf("Enter number to check for divisors: ");
  fflush(stdout);
  if (scanf("%d", &number) != 1 || number < 0) {
    puts("Error: bad input - expected nonnegative integer number");
    return EXIT_FAILURE;
  }
  limit = (int)sqrt(number);
  if (number == 0 || number == 1) {
    printf("%d is not a prime number.\n", number);
  } else {
    for (d = 2; d <= limit; d++) {
      if (number % d == 0) {
        goto done;
      }
    }
  done:
    if (d > sqrt(number)) {
      printf("%d is a prime number.\n", number);
    } else {
      printf("%d is divisible by %d.\n", number, d);
    }
  }

  return EXIT_SUCCESS;
}
