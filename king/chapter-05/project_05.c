// Name: project_05.c
// Purpose: Calculate single person income tax
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double income, tax;
  int rv;

  printf("Calculates income tax for a single resident.\n");
  printf("Enter taxable income in USD (e.g. 650.50): ");
  rv = scanf("%lf", &income);
  if (rv != 1) {
    printf("Error: bad input - expected a floating point number.\n");
    return EXIT_FAILURE;
  }

  // Negative income produces no tax liability.
  if (income < 0) {
    income = 0;
  }

  if (income <= 750) {
    tax = income * 0.01;
  } else if (income <= 2250) {
    tax = 7.5 + (income - 750) * 0.02;
  } else if (income <= 3750) {
    tax = 37.5 + (income - 2250) * 0.03;
  } else if (income <= 5250) {
    tax = 82.5 + (income - 3750) * 0.04;
  } else if (income <= 7000) {
    tax = 142.5 + (income - 5250) * 0.05;
  } else {
    tax = 230 + (income - 7000) * 0.06;
  }

  printf("Tax due: USD %.2f\n", tax);

  return EXIT_SUCCESS;
}
