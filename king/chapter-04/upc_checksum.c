// Name: upc_checksum.c
// Purpose: Calculates the check digit for an otherwise known
//          12 digit Universal Product Code (UPC).
// Author: Georg

#include <stdio.h>

int main(void) {
  // UPC digits, d11 is for the checksum
  int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
  int weighted_sum;
  // For input cardinality validation
  int rv;
  printf("This program calculates the checksum for an otherwise\n");
  printf("known product code.\n");
  printf("Enter first eleven digits (# # # # # # # # # # #): ");

  rv = scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d0, &d1, &d2, &d3, &d4, &d5, &d6, &d7,
             &d8, &d9, &d10);
  if (rv != 11) {
    printf("\nExpected to read 11 digits, but scanf returned %d before that.\n",
           rv);
    return 101;
  }

  weighted_sum = (d0 + d2 + d4 + d6 + d8 + d10) * 3 + (d1 + d3 + d5 + d7 + d9);
  d11 = (10 - weighted_sum % 10) % 10;
  printf("\n%d   %d%d%d%d%d %d%d%d%d%d %d\n", d0, d1, d2, d3, d4, d5, d6, d7,
         d8, d9, d10, d11);

  return 0;
}
