// Name: scan_test.c
// Purpose: Experiment with conversion specifications in scanf calls.
// Author: Georg

#include <stdio.h>

int main(void){
  int i1, i2, rv;
  float f1, f2;

  printf("Enter 2 ints and 2 floats: ");
  rv = scanf("%d%d%f%f", &i1, &i2, &f1, &f2);
  printf("i1: %d\ni2: %d\nf1: %f\nf2: %f\n", i1, i2, f1, f2);
  printf("RV: %d\n", rv);

  return 0;
}
