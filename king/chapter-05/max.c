// Name: max.c
// Purpose: Find the largest of three values.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j, k;
  int rv;
  int max;
  printf(
      "This program asks for three numbers and prints the largest of them.\n");
  printf("Enter three integer numbers: ");
  rv = scanf("%d%d%d", &i, &j, &k);
  if (rv != 3) {
    printf("Error: bad input - expected three integer numbers!\n");
    return EXIT_FAILURE;
  }

  if (i > j) {
    // i > k
    if (i > k)
      // i > j , i > k
      max = i;
    else
      // j < i , i <= k -> j <= k
      max = k;
  } else if (j > k) {
    // i <= j , j > k
    max = j;
  } else {
    // i <= j , j <= k -> i <= k
    max = k;
  }

  printf("max(%d, %d, %d) = %d\n", i, j, k, max);

  return EXIT_SUCCESS;
}
