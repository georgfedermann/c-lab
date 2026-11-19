// Name: exercise_13.c

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, m = 8;
  for (n = 0; m > 0; n++)
    m /= 2;

  printf("n: %d, m: %d\n", n, m);

  m = 8;
  for (n = 0; m > 0; m /= 2, n++)
    ;
  printf("n: %d, m: %d\n", n, m);

  return EXIT_SUCCESS;
}
