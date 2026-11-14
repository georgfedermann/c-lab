// Name: eof.c
// Purpose: study EOF, input stream reading error recovyer, etc.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int rv, input = 47;
  puts("Press CTRD-D to signal EOF as first thing on input");

  rv = scanf("%d", &input);
  printf("scanf read %d and return %d\n", input, rv);
  printf("feof(stdin): %d\n", feof(stdin));
  printf("Now calling clearerr(stdin)\n");
  clearerr(stdin);
  printf("Now, try enter another number: ");
  fflush(stdout);
  rv = scanf("%d", &input);
  printf("scanf read %d and returned %d\n", input, rv);

  return EXIT_SUCCESS;
}
