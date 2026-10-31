// Name: project_02.c
// Purpose: Read a three digit number and print the reverse number
// Author: Georg

#include <stdio.h>

int main(void) {
  int number;
  int rv;
  printf("Program reads a three digit number and prints its reverse.\n");
  printf("Enter three digit number: ");

  rv = scanf("%d", &number);

  if (rv != 1) {
    printf("Error: bad input - expected a three digit number\n");
    return 101;
  }
  if (number < 100 || number > 999) {
    printf("Error: bad input - expected a three digit number\n");
    return 102;
  }
  printf("%03d\n",
         (number % 10 * 100) + (number / 10 % 10 * 10) + (number / 100));

  return 0;
}
