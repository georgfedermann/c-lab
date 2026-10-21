// Name: case_sensitive.c
// Purpose: Demonstrate that identifiers are case sensitive in C.
// Author: Georg

#include <stdio.h>

int main(void) {
  int Car = 0, cAr = 1, caR = 2;
  printf("car - 3 ways of writing, 3 variables, 3 values ...\n");
  printf("Car: %d, cAr: %d, caR: %d\n", Car, cAr, caR);

  return 0;
}
