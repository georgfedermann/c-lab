// Name: scan.c
// Purpose: Reads a value and echos it out again
// Author: Georg

#include <stdio.h>

int main(void) {
  int var;
  scanf("%d", &var);
  printf("Read value: %d\n", var);

  return 0;
}
