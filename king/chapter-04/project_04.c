// Name: project_04.c
// Purpose: Read a decimal int between 0 and 32767 and print it as octal number.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int number, rv;
  printf("Enter a decimal integer number between 0 and 32767: ");
  rv = scanf("%d", &number);

  if (rv != 1 || number < 0 || number > 32767) {
    printf("Error: bad input - expected a decimal integer number between 0 and "
           "32767\n");
    return EXIT_FAILURE;
  }

  printf("In octal, your number is: %05o\n", (unsigned int)number);
  printf("In octal, your number is: %05d\n",
         (number % 8) + (number / 8 % 8 * 10) + (number / 64 % 8 * 100) +
             (number / 512 % 8 * 1000) + (number / 4096 % 8 * 10000));

  return EXIT_SUCCESS;
}
