// Name: sum_up.c
// Purpose: Sum up numbers, demo `break` statements
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int sum = 0, summand;
  for (;;) {
    printf("Enter next summand (0 to stop): ");
    fflush(stdout);
    if (scanf("%d", &summand) != 1) {
      puts("Error: bad input - expected integer number");
      return EXIT_FAILURE;
    }
    if (summand == 0) {
      break;
    }
    sum += summand;
  }
  printf("Sum of entered numbers: %d\n", sum);

  return EXIT_SUCCESS;
}
