// Name: project_06.c
// Purpose: European countries use a 13-digit code known as a European Article Number (EAN)
//          instead of the 12-digit Universal Product Code (UPC) found in the US.
//          Each EAN ends with a check digit, just as a UPC does. The algorithm for calcualting
//          the check digit is also similar:
//              Add places 2, 4, 6, 8, 10 12
//              Add places 1, 3, 5, 7, 9, 11
//              Multiple the first sum by 3 and add it to the seconds sum.
//              Calculate remainder modulo 10, subtract remainder from 10.
//          Test cases: EAN 8691484260008
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
  int weighted_sum, check_digit;
  int rv;

  printf("This program calculats the check digit for an European Article Number (EAN).\n");
  printf("Enter the first 11 digits of an EAN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12);
  
  weighted_sum = (d1 + d3 + d5 + d7 + d9 + d11) + 3 * (d2 + d4 + d6 + d8 + d10 + d12);
  check_digit = (10 - weighted_sum % 10) % 10;

  printf("check digit: %d\n", check_digit);

  return 0;
}
