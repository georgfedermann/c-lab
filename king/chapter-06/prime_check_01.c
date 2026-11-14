// Name: prime_check_01.c
// Purpose: Look for divisors of a given number, demo `break` statement
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int number = 143, d;

  printf("Enter number to check for divisors: ");
  fflush(stdout);
  if (scanf("%d", &number) != 1 || number < 0) {
    puts("Error: bad input - expected nonnegative integer number");
    return EXIT_FAILURE;
  }

  if (number == 0 || number == 1) {
    printf("%d is not a prime number.\n", number);
  } else {
    for (d = 2; d < number; d++) {
      if (number % d == 0) {
        break;
      }
    }
    if (d < number - 1) {
      printf("%d is divided by %d.\n", number, d);
    } else {
      printf("%d is a prime number.\n", number);
    }
  }

  return EXIT_SUCCESS;
}
