// Name: addresses.c
// Purpose: print size of variable types
// Author: Georg
#include <stdio.h>

int main(void) {
  int a = 1, b = 2, c = 3, d = 4;
  float x = 1.0f, y = 2.0f, z = 3.0f, w = 4.0f;

  printf("Infering size of int variables in bytes by reading\n");
  printf("consecutive memory locations from the stack.\n\n");
  printf("Address a: %p\n", (void *) &a);
  printf("Address b: %p\n", (void *) &b);
  printf("Address c: %p\n", (void *) &c);
  printf("Address d: %p\n", (void *) &d);


  printf("\nInfering size of float variables in bytes by reading\n");
  printf("consecutive memory locations from the stack.\n\n");
  printf("Address x: %p\n", (void *) &x);
  printf("Address y: %p\n", (void *) &y);
  printf("Address z: %p\n", (void *) &z);
  printf("Address w: %p\n", (void *) &w);

  return 0;
}
