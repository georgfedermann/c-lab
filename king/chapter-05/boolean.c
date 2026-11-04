// Name: boolean.c
// Purpose: Explore the C type boolean.
// Author: Georg

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
  _Bool flag = 42;
  int b = 42;

  printf("flag: %d, b: %d\n", flag, b);
  printf("size of int: %zu\n", sizeof b);
  printf("size of _Bool: %zu\n", sizeof flag);

  bool semaphore = true;
  printf("semaphore: %u\n", semaphore);
  printf("size of bool: %zu\n", sizeof semaphore);
  semaphore = 42;
  printf("semaphore: %u\n", semaphore);
  printf("true: %d, false: %d\n", true, false);

  return EXIT_SUCCESS;
}
