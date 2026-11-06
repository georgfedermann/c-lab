// Name: exercise_02.c
// Purpose: Learn logical operators
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // a) Expect: 1
  int i = 10, j = 5, k;
  printf("i: %d, j: %d, !i < j: %d\n", i, j, !i < j);

  // b) Expect: 1
  i = 2, j = 1;
  printf("i: %d, j: %d, !!i + !j: %d\n", i, j, !!i + !j);

  // c) Expect: 1
  i = 5, j = 0, k = -5;
  printf("i: %d, j: %d, k: %d, i && j || k: %d\n", i, j, k, i && j || k);

  // d) Expect: 1
  i = 1, j = 2, k = 3;
  printf("i: %d, j: %d, k: %d, i < j || k: %d\n", i, j, k, i < j || k);

  return EXIT_SUCCESS;
}
