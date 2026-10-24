// Name: scan_test_01.c
// Purpose: Play around with blanks and separators...
// Author: Georg

#include <stdio.h>

int main(void){
  int i1 = -5, i2 = -6;
  printf("i1: %d, i2: %d\n", i1, i2);
  printf("Enter two integers, separated by a comma: ");
  scanf("%d , %d", &i1, &i2);
  printf("Values entered: %d - %d\n", i1, i2);

  return 0;
}
