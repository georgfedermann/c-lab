// Name: project_06.c
// Purpose: Fractions revisited. Implement another format of entering fractions.
// Author: Georg

#include <stdio.h>

int main(void) {
  // 2 fractions
  int numerator1, numerator2, denominator1, denominator2;
  // Basic input cardinality reconciliation
  int rv;
  printf("This program reads to fractions and returns the unsimplified sum.\n");

  printf("Enter two fractions (e.g. 3/4+2/5): ");
  rv = scanf("%d/%d+%d/%d", &numerator1, &denominator1, &numerator2,
             &denominator2);
  if (rv != 4){
    printf("Expected to read 4 values, scanf returned %d before that.", rv);
    return 1;
  }
  printf("%d/%d+%d/%d=%d/%d\n", numerator1, denominator1, numerator2,
         denominator2, (numerator1 * denominator2 + numerator2 * denominator1),
         denominator1 * denominator2);

  return 0;
}
