// Name: exercise_01.c
// Purpose: Exercise 1 from King's book
// Author: Georg

#include <stdio.h>

int main(void) {
  int i, j, k;

  // Expect: 1 2
  i = 5;
  j = 3;
  printf("%d %d\n", i / j, i % j);

  // Expect: 0
  i = 2;
  j = 3;
  printf("%d\n", (i + 10) % j);

  // Expect: 1
  i = 7;
  j = 8;
  k = 9;
  printf("%d\n", (i + 10) % k / j);

  // Expect: 0
  i = 1;
  j = 2;
  k = 3;
  printf("%d\n", (i + 5) % (j + 2) / k);

  return 0;
}
