// Name: project_05.c
// Purpose: Reverse nonnegative integer numbers
// Author: Georg

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int value;

  printf("Enter a nonnegative integer number (max 4294967295): ");
  if (scanf("%u", &value) != 1) {
    fprintf(stderr, "Error: bad input - expected a nonnegative integer "
                    "number <= 4294967295\n");
    return EXIT_FAILURE;
  }
  // whenever a number reversion begins, value contains a validated positive
  // integer number
  printf("\nThe reversal is: ");
  do {
    printf("%d", value % 10);
    value /= 10;
  } while (value > 0);
  puts("");

  return EXIT_SUCCESS;
}
