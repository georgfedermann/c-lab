// Name: exercise_11.c
// Purpose: Fun with C - what does the program print?
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int sum = 0, i;

  for (i = 0; i < 10; i++) {
    if (i % 2)
      continue;
    sum += i;
  }
  printf("Expect:\n20\n");
  printf("%d\n", sum);

  return EXIT_SUCCESS;
}
