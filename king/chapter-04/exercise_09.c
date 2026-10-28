// Name: exercise_09.c
// Purpose: Test outcome of various C expressions
// Author: Georg

#include <stdio.h>

int main(void) {
  int i, j, k;

  // a) Expect: 63 8
  i = 7, j = 8;
  i *= j + 1;
  printf("%d %d\n", i, j);

  // b) Expect: -1 2 1
  i = j = k = 1;
  i -= j += k;
  printf("%d %d %d\n", i, j, k);

  // c) Expect: 2 -1  3
  i = 1, j = 2, k = 3;
  i -= j -= k;
  printf("%d %d %d\n", i, j, k);

  // d) Expect: 0 0 0
  i = 2, j = 1, k = 0;
  i *= j *= k;
  printf("%d %d %d", i, j, k);

  return 0;
}
