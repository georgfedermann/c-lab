// Name: conditional.c
// Purpose: Demo conditional expression and its applications
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i = 1, j = 2, k = 3;
  printf("i = %d, j = %d, k = %d\n", i, j, k);
  k = i > j ? i++ : j++;
  printf("i = %d, j = %d, k = %d\n", i, j, k);
  k = (i >= 0 ? i : 0) + j;
  printf("i = %d, j = %d, k = %d\n", i, j, k);

  return EXIT_SUCCESS;
}
