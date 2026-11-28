// Name: int_limits.c
// Purpose: Remind me of int type limits
// Author: Georg

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
  unsigned int value;

  printf("INT_MIN: %d\n", INT_MIN);
  printf("INT_MAX: %d\n", INT_MAX);
  printf("UINT_MAX: %u\n", UINT_MAX);

  printf("\nTest UINT overflow:\n");
  value = UINT_MAX;
  printf("unsigned int value = %u\n", value);
  printf("value + 1 = %u\n", value + 1);



  return EXIT_SUCCESS;
}
