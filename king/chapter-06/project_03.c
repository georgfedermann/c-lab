// Name: project_03.c
// Purpose: Transform a fraction to simplest terms.
// Author: Georg

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int numerator, denominator, m, n, o, rv;
  int sign = 1;

  printf("Enter a fraction: ");
  rv = scanf("%d/%d", &numerator, &denominator);

  if (rv != 2) {
    fprintf(stderr, "Error: invalid input - expected two integers in the form "
                    "numerator/denominator\n");
    return 1;
  }
  if (denominator == 0) {
    fprintf(stderr, "Error: undefined fraction\n");
    return 2;
  }
  if (denominator == INT_MIN) {
    fprintf(stderr, "Error: denominator out of range\n");
    return 2;
  }
  if (numerator == INT_MIN) {
    fprintf(stderr, "Error: numerator out of range\n");
    return 2;
  }

  if ((numerator < 0 && denominator > 0) ||
      (numerator > 0 && denominator < 0)) {
    sign = -1;
  }
  if (numerator < 0) {
    numerator *= -1;
  }
  if (denominator < 0) {
    denominator *= -1;
  }

  m = numerator, n = denominator;

  while (n > 0) {
    o = m % n;
    m = n;
    n = o;
  }

  numerator /= (m * sign);
  denominator /= m;

  printf("\nIn lowest terms: %d/%d\n", numerator, denominator);

  return EXIT_SUCCESS;
}
