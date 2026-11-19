// Name: exercise_12.c
// Purpose: simple prime finder algorithm
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int d, n = 77;

  for (d = 2; d * d <= n; d++)
    if (n % d == 0)
      break;

  if (d*d > n)
    printf("%d is a prime number\n", n);
  else
    printf("%d is a divisor of %d\n", d, n);

  return EXIT_SUCCESS;
}
