// Name: boolean.c
// Purpose: Verify assumptions about C's boolean expression evaluation
// Author: Georg

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
  if (0){
    puts("0 is true");
  }else {
    puts("0 is false");
  }

  return EXIT_SUCCESS;
}
