// Name: commission.c
// Purpose: Calculates a commission from a fixed value and a percentage
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int rv;
  float amount, commission;
  printf("This program calculates a commission based on a fixed rate and a "
         "percentage both based on the given principal.\n");

  printf("Enter amount of trade: ");
  rv = scanf("%f", &amount);
  if (rv != 1) {
    printf("Error: bad input - expected one floating point number!\n");
    return EXIT_FAILURE;
  }

  if (amount < 2500)
    commission = 30 + 0.017 * amount;
  else if (amount < 6250)
    commission = 56 + 0.0066 * amount;
  else if (amount < 20000)
    commission = 76 + 0.0034 * amount;
  else if (amount < 50000)
    commission = 100 + 0.0022 * amount;
  else if (amount < 500000)
    commission = 155 + 0.0011 * amount;
  else
    commission = 255 + 0.0009 * amount;

  printf("Commission: %.2f\n", commission);

  return EXIT_SUCCESS;
}
