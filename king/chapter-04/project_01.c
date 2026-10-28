// Name: project_01.c
// Purpose: Reverse a two digit number
// Author: Georg

#include <stdio.h>

int main(void) {
  int number;
  // Verify that scanf successfully reads an integer.
  int rv;
  printf("Enter a two-digit number: ");
  rv = scanf("%d", &number);
  if (rv != 1) {
    printf("\nError: Expected a single two-digit integer.\n");
    return 101;
  }
  if (number < 10 || number > 99) {
    printf("\nError: Expected a two-digit integer.\n");
    return 102;
  }
  printf("The reversal is: %02d\n", (number % 10) * 10 + number / 10);

  return 0;
}
