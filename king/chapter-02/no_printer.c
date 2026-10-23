// Name: no_printer.c
// Purpose: experiment with printf
// Author: Georg

#include <stdio.h>

int main(void) {
  printf("Hello, %10s!\n", "World");

  int i = 10, j = 20;
  float x = 43.2892f, y = 5527.0f;

  printf("i = %10d, j = %d, x = %f, y = %f\n", i, j, x, y);
  printf("i = %10d, j = %d, x = %e, y = %e\n", i, j, x, y);
  printf("i = %10d, j = %d, x = %g, y = %g\n", i, j, x, y);
  printf("Too few values: v1: %d, v2: %d\n", i);
  printf("Too many values: v1: %d\n", i, j);
  printf("Wrong data types - int: %f, float: %d\n", i, x);
  printf("Wrong types: %f\n", i);
  printf("More wrong types: %d\n", x);

  return 0;
}
