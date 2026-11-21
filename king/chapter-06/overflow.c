// Name: overflow.c
// Purpose: Observe overflow behavior of int32
// Author: Georg

#include <stdlib.h>
#include <stdio.h>

int main(void) {
  printf("%d * %d = %d\n", 32, 7, 32 * 7);
  printf("Hello\n");
  printf("%d * %d = %d\n", 2000000000, 2, 2000000000 * 2);
  printf("%d * %d = %d\n", 2147483647, 73, 2147483647 * 73);

  return EXIT_SUCCESS;
}
