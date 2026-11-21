// Name: test_probe.c
// Purpose: Generate some output to capture with the test engine
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int output = 1, c;
  for (c = 0; c < 8; c++) {
    printf("%d ", output);
    output *= 2;
  }
  fprintf(stderr, "Error: StackOverflow!");

  return EXIT_SUCCESS;
}
