// Name: horner.c
// Purpose: Practice typing
// Author: Georg

# include <stdio.h>

int main(void){
  int x, y;
  printf("This program uses horner schema to calculate polynomial value.\n");
  printf("Enter x value: ");
  if (scanf("%d", &x) != 1){
    printf("Invalid value.\n");
    return 1;
  }

  y = ((((3 * x + 2) * x - 5) * x - 1) * x + 7 ) * x - 6;
  printf("y(%d) = %d\n", x, y);

  return 0;
}
