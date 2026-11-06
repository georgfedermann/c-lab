// Name: exercise_03.c
// Purpose: Sudty short-circuit behavior of logical expressions
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j, k;

  // a) Expect:
  // Result: 1
  // i: 3, j: 4, k: 5
  i = 3, j = 4, k = 5;
  printf("a)\n");
  printf("i: %d, j: %d, k: %d\n", i, j, k);
  printf("i < j || ++j < k: %d\n", i < j || ++j < k);
  printf("i: %d, j: %d, k: %d\n", i, j, k);

  // b) Expect:
  // Result: 0
  // i: 7, j: 8, k: 9
  i = 7, j = 8, k = 9;
  printf("i: %d, j: %d, k: %d\n", i, j, k);
  printf("i - 7 && j++ < k: %d\n", i - 7 && j++ < k);
  printf("i: %d, j: %d, k: %d\n", i, j, k);

  // c) Expect:
  // Result: 1
  // i: 8, j: 8, k: 9
  i = 7, j = 8, k = 9;
  printf("i: %d, j: %d, k: %d\n", i, j, k);
  printf("(i = j) || (j = k): %d\n", (i = j) || (j = k));
  printf("i: %d, j: %d, k: %d\n", i, j, k);

  // d) Expect:
  // Result: 1
  // i: 2, j: 1, k: 1
  i = 1, j = 1, k = 1;
  printf("i: %d, j: %d, k: %d\n", i, j, k);
  printf("++i || ++j && ++k: %d\n", ++i || ++j && ++k);
  printf("i: %d, j: %d, k: %d\n", i, j, k);


  return EXIT_SUCCESS;
}
