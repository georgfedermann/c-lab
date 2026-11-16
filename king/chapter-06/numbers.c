// Name: numbers.c
// Purpose: Generate numbers as an input to sum_up_02
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  for (int i = 1, j = 1; i <= 10; i++, j *= 2) {
    printf("%d ", j);
  }
  puts("0");

  return EXIT_SUCCESS;
}
