// Name: exercise_10.c
// Purpose: replace a continue statement by an equivalent goto statement
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;
  for (i = 0; i <= 10; i++) {
    if (i % 2 == 0) {
      continue;
    }
    printf("%d ", i);
  }
  puts("");
  for (i = 0; i <= 10; i++) {
    if (i % 2 == 0) {
      goto next;
    }
    printf("%d ", i);
  next:;
  }
  puts("");

  return EXIT_SUCCESS;
}
