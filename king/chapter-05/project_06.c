// Name: project_06.c
// Purpose: European countries use a 13-digit code known as a European Article
// Number (EAN)
//          instead of the 12-digit Universal Product Code (UPC) found in the
//          US. Each EAN ends with a check digit, just as a UPC does. The
//          algorithm for calcualting the check digit is also similar:
//              Add places 2, 4, 6, 8, 10 12
//              Add places 1, 3, 5, 7, 9, 11
//              Multiple the first sum by 3 and add it to the seconds sum.
//              Calculate remainder modulo 10, subtract remainder from 10.
//          Test cases: EAN 8691484260008
//          This program reads an EAN and verifies that its check digit checks
//          out.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, check_digit,
      weighted_sum;
  int rv;
  printf("This program verifies a European Article Number (EAN) using its "
         "check digit.\n");
  printf("Enter EAN (# ###### ######): ");

  rv = scanf("%1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d", &d1, &d2,
             &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12, &d13);

  if (rv != 13){
    printf("\nError: bad input - expected 13 digits\n");
    return 2;
  }

  weighted_sum =
      (d2 + d4 + d6 + d8 + d10 + d12) * 3 + (d1 + d3 + d5 + d7 + d9 + d11);
  check_digit = (10 - weighted_sum % 10) % 10;

  printf("\n%s\n", check_digit == d13 ? "VALID" : "NOT VALID");

  return check_digit == d13 ? EXIT_SUCCESS : 1;
}
