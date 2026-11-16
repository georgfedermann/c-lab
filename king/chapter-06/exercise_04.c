// Name: exercise_04.c

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;

  puts("Listing values of a counter variable in the loop body");
  puts("for (i = 0; i < 10; i++)");
  puts("Behold:\n0 1 2 3 4 5 6 7 8 9");
  for (i = 0; i < 10; i++) {
    printf("%d ", i);
  }

  puts("\nfor (i = 0; i < 10; ++i)");
  puts("Behold:\n0 1 2 3 4 5 6 7 8 9");
  for (i = 0; i < 10; ++i) {
    printf("%d ", i);
  }

  puts("\nfor (i = 0; i++ < 10;)");
  puts("Behold:\n1 2 3 4 5 6 7 8 9 10");
  for (i = 0; i++ < 10;) {
    printf("%d ", i);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
