// Name: division.c
// Purpose: Find out what my c compiler does with int division of negative numbers
// Author: Georg

#include <stdio.h>
int main(void){
  printf("-9 / 7 = %d\n", -9 / 7);
  printf("-9 %% 7 = %d\n", -9 % 7);

  return 0;
}
