// Name: taxes.c
// Purpose: Enter amount, calculate taxes.
// Author: Georg

#include <stdio.h>

int main(void){
  float amount;
  printf("This program prompts for an amount and calculates 5%% taxes added.\n");
  printf("Enter an amount: ");

  if (scanf("%f", &amount) != 1){
    printf("Invalid amount.");
    return 1;
  }
  printf("With tax added: $%.2f\n", amount * 1.05f);

  return 0;
}
