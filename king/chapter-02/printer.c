// Name: printer.c
// Purpose: Demo conversion specifications in printf
// Author: Georg

#include <stdio.h>

int main(void){
  int i;
  float x;

  i = 42;
  x = 839.21f;

  printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
  printf("|%d|%5d|%-5d|%.5d|\n", i, i, i, i);
  printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
  printf("\a - Ding!!\b \n");

  return 0;
}
