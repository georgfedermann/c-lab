// Name: if_statement_01.c
// Purpose: Test assumptions about C's Selection Statements (if, switch, logical
// expressions)
// Author: Georg

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i = 1, j = 2;
  float x = 1.1, y = M_PI;

  printf("This program tests the return value of logical expressions and how "
         "`if` deals with them.\n");
  printf("Testing int operands\n");
  printf("====================\n");
  printf("i = %d, j = %d\n", i, j);
  printf("x = %.2f, y = %.2f\n", x, y);
  printf("i < j -> %d\n", i < j);
  printf("i == 0 -> %d\n", i == j);
  printf("i != j -> %d\n", i != j);
  printf("i <= j -> %d\n", i <= j);

  printf("Mixed type operands (int / float)\n");
  printf("=================================\n");
  printf("%d < %.2f -> %d\n", i, x, i < x);
  printf("%d > %.2f -> %d\n", j, y, j > y);

  if (i == M_PI) {
    printf("%d is PI!\n", i);
  } else {
    printf("%d is not PI!\n", i);
  }

  if (y == M_PI) {
    printf("%.2f is PI!\n", y);
  } else {
    printf("%.2f is not PI!\n", y);
  }

  if (y == (float)M_PI) {
    printf("%.2f is (float)PI!\n", y);
  } else {
    printf("No, %.2f is not (float)PI either!\n", y);
  }

  return EXIT_SUCCESS;
}
