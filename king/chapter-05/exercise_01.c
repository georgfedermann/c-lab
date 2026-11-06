// Name: exercise_01.c
// Purpose: Practice evaluating simple to slightly more complex C expressions.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Expectation: 1
  int i = 2, j = 3, k;
  k = i * j == 6;
  printf("i = %d, j = %d, k = i * j == 6, k = %d\n", i, j, k);

  // Expectation: 1
  i = 5, j = 10, k = 1;
  printf("i = %d, j = %d, k = %d, k > i < j = %d\n", i, j, k, k > i < j);

  // Expectation: 1
  i = 3, j = 2, k = 1;
  printf("i = %d, j = %d, k = %d, i < j == j < k -> %d\n", i, j, k,
         i < j == j < k);

  // Expectation: 0
  i = 3, j = 4, k = 5;
  printf("i = %d, j = %d, k = %d, i %% j + i < k -> %d\n", i, j, k,
         i % j + i < k);

  return EXIT_SUCCESS;
}
