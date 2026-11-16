// Name: exercise_06.c

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i = 1;
  while (i <= 128) {
    printf("%d ", i);
    i *= 2;
  }
  puts("");

  for (int i = 1; i <= 128; i *= 2) {
    printf("%d ", i);
  }
  puts("");

  return EXIT_SUCCESS;
}
