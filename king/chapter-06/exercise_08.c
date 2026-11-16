// Name: exercise_08.c

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int i, j = 0;

  puts("Expect:\n10 5 3 2 1 1 1 ");

  for (i = 10; i >= 1; i /= 2) {
    printf("%d ", i++);
    if (j++ >= 6) {
      printf("\nCircuit breaker activated at i: %d, j: %d\n", i, j);
      break;
    }
  }
  puts("");

  // Equivalent while statement
  i = 10, j = 0;
  while (i >= 1) {
    printf("%d ", i++);
    if (j++ >= 6) {
      printf("\nCircuit breaker activated at i: %d, j: %d\n", i, j);
      break;
    }
    i /= 2;
  }

  return EXIT_SUCCESS;
}
