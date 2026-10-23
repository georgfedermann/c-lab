// Name: polynomial.c
// Purpse: Simple polynomial arithmetics
// Author: Georg

#include <stdio.h>

int main(void) {
  int x = 0, y = 0;
  printf("This program calculates the value of a polynomial for\n");
  printf("a user provided value.\n");

  printf("Enter value of x: ");
  if (scanf("%d", &x) != 1) {
    printf("Invalid value");
    return 1;
  }

  y = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x +
      7 * x - 6;
  printf("\ny(%d) = %d\n", x, y);

  return 0;
}
