// Name: exercise_07.c

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i = 9384;
  do {
    printf("%d ", i);
    i /= 10;
  } while (i > 0);
  puts("");

  for (int i = 9384;;) {
    printf("%d ", i);
    i /= 10;
    if (i <= 0) {
      break;
    }
  }
  puts("");

  return EXIT_SUCCESS;
}
