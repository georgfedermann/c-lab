// Name: project_02.c
// Purpose: calculate greatest common divisor (gcd) of two numbers
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int m, n, o, rv;
  printf("Enter two integers: ");
  rv = scanf("%d %d", &m, &n);

  if (rv != 2 || m < 0 || n < 0) {
    fprintf(stderr, "Error: bad input - expected two nonnegative integers\n");
    return 1;
  }
  if (m == 0 && n == 0) {
    fprintf(stderr, "Error: gcd(0,0) is undefined");
    return 2;
  }

  while (n > 0) {
    o = m % n;
    m = n;
    n = o;
  }
  printf("\nGreatest common divisor: %d\n", m);

  return EXIT_SUCCESS;
}
