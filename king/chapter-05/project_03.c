// Name: project_03.c
// Purpose: Calculate the commission for a broker and their competition
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int rv;
  float number_shares, price_share, amount, commission, commission_b;

  printf("Program reads number of shares and price per share and prints the\n"
         "commission.\n");

  printf("Enter number of shares: ");
  rv = scanf("%f", &number_shares);
  if (rv != 1) {
    printf("Error: bad input - Expected one float value.\n");
    return EXIT_FAILURE;
  }

  printf("Enter price per share: USD ");
  rv = scanf("%f", &price_share);
  if (rv != 1) {
    printf("Error: bad input - Expected one float value.\n");
    return EXIT_FAILURE;
  }

  amount = number_shares * price_share;

  if (amount < 2500)
    commission = 30 + 0.017f * amount;
  else if (amount < 6250)
    commission = 56 + 0.0066f * amount;
  else if (amount < 20000)
    commission = 76 + 0.0034f * amount;
  else if (amount < 50000)
    commission = 100 + 0.0022f * amount;
  else if (amount < 500000)
    commission = 155 + 0.0011f * amount;
  else
    commission = 255 + 0.0009f * amount;

  commission_b = 33 + number_shares * (number_shares < 2000 ? 0.03f : 0.02f);

  printf("Commission: USD %.2f\n", commission);
  printf("(Rival commission USD %.2f)\n", commission_b);

  return EXIT_SUCCESS;
}
