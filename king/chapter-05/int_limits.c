// Name: int_limits.c
// Purpose: Experiment with near-overflow experiences.
// Author: georg

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int counter, fuse = 0;
  unsigned int u_counter;
  printf("This program experiments with int edge cases.\n");

  counter = INT_MAX - 10;

  printf("Count to INT_MAX using a while loop:\n");
  while (true) {
    printf("%d\n", counter);

    if (counter == INT_MAX) {
      break;
    }

    counter++;
  }

  printf("Count to INT_MAX using a for loop:\n");
  for (counter = INT_MAX - 11; counter < INT_MAX;) {
    printf("%d\n", ++counter);
  }
  printf("Allow overflow on signed int to checkout behavior on AMD x86-64\n");
  printf("Try compiling with -fsanitize=undefined "
         "-fno-sanitize-recover=undefined\n");
  printf("Maybe: sudo dnf install libubsan\n");
  for (counter = INT_MAX - 10; counter != -2147483636; counter++) {
    printf("%d\n", counter);
  }

  printf("Using unsigned int as counter:\n");
  printf("Unsigned max: %u\n", UINT_MAX);

  u_counter = UINT_MAX - 10;
  while (true) {
    printf("%u\n", u_counter++);
    fuse++;
    if (fuse > 20) {
      break;
    }
  }

  return EXIT_SUCCESS;
}
