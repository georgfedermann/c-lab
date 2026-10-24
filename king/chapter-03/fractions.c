// Name: fractions.c
// Purpose: Use scanf to read fractions and add them up.
// Author: Georg

#include <stdio.h>

int main(void){
  // fraction 1, numerator and denominator
  int numerator_1 = 0, denominator_1 = 1;
  // fraction 2
  int numerator_2 = 0, denominator_2 = 1;
  // result
  int numerator = 0, denominator = 1;
  printf("This program reads fractions in the format a/b and adds them up.\n");
  printf("Enter fraction 1 (a/b): ");
  scanf("%d/%d", &numerator_1, &denominator_1);
  printf("Enter fraction 2 (a/b): ");
  scanf("%d/%d", &numerator_2, &denominator_2);
  denominator = denominator_1 * denominator_2;
  numerator = numerator_1 * denominator_2 + numerator_2 * denominator_1;
  printf("%d/%d + %d/%d = %d/%d\n", numerator_1, denominator_1, numerator_2,
         denominator_2, numerator, denominator);

  return 0;
}
