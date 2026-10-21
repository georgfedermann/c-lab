// Name: uninitialized.c
// Purpose: Print values of unitialized stack variables
// Author: Georg

#include <stdio.h>

int main(void){
  int i1, i2, i3;
  float f1, f2, f3;

  printf("This program prints the values of uninitialized int and float variables.\n");
  printf("int1: %d\nint2: %d\nint3: %d\n\n", i1, i2, i3);
  printf("float1: %f\nfloat2: %f\nfloat3: %f\n", f1, f2, f3);
  printf("Floats in scientific notation:\n");
  printf("float1: %e\nfloat2: %e\nfloat3: %e\n", f1, f2, f3);

  return 0;
}
