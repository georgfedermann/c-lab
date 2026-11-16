// Name: exercise_02.c

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i = 9384;

  // Expected output:
  // 9384 938 93 9
  do {
    printf("%d ", i);
    i /= 10;
  } while (i > 0);

  return EXIT_SUCCESS;
}
