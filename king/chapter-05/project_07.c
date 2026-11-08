// Name: project_07.c
// Purpose: Find the largest and the smallest of four integers entered by the
// user.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int d1, d2, d3, d4;
  int rv;
  int min1, max1, min2, max2;

  puts("This program reads 4 integer numbers and prints the largest and the\n"
       "smallest one.");
  printf("Enter 4 integer numbers: ");

  rv = scanf("%d %d %d %d", &d1, &d2, &d3, &d4);

  if (rv != 4) {
    puts("\nError: bad input\nexpected four integer numbers\n");
    return EXIT_FAILURE;
  }

  if (d1 < d2) {
    max1 = d2;
    min1 = d1;
  } else {
    max1 = d1;
    min1 = d2;
  }

  if (d3 < d4) {
    max2 = d4;
    min2 = d3;
  } else {
    max2 = d3;
    min2 = d4;
  }

  printf("\nLargest: %d\nSmallest: %d\n", max1 > max2 ? max1 : max2,
         min1 < min2 ? min1 : min2);

  return EXIT_SUCCESS;
}
