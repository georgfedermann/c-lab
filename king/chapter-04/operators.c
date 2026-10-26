/*
 * Using C comments here to allow for compilation to std89
// Name: operators.c
// Purpose: Experiment with information provided in King's book ch04.
// Author: Georg
*/

#include <stdio.h>

int main(void) {
  printf("+-3: %d\n", +-3);
  printf("-+3: %d\n", -+3);

  printf("10 %% 3: %d\n", 10 % 3);
  printf("12 %% 3: %d\n", 12 % 3);

  printf("10 / 3: %d\n", 10 / 3);

  printf("5 / 2 * 2.0: %.1f\n", 5 / 2 * 2.0);
  printf("5 / 2.0 * 2: %.1f\n", 5 / 2.0 * 2);

  /*
    // This would result in a compiler error:
    // printf("5 % 2.0: %f\n", 5.0 % 2.0);
  */

  printf("-9 %% 7: %d\n", -9 % 7);

  return 0;
}
