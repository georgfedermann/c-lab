// Name: interest.c
// Purpose: Calculate interest rates and credit balances per month
// Author: Georg

#include <stdio.h>

int main(void){
  float principal, interest_rate, monthly_payment;
  float amount, monthly_interest_rate;
  printf("This program calculates credit balances on monthly bases.\n");

  printf("Enter amount of loan: ");
  if (scanf("%f", &principal) != 1){
    printf("Invalid amount.\n");
    return 1;
  }
  amount = principal;

  printf("Enter interest rate: ");
  if (scanf("%f", &interest_rate) != 1){
    printf("Invalid amount.\n");
    return 1;
  }

  printf("Enter monthly payment: ");
  if (scanf("%f", &monthly_payment) != 1){
    printf("Invalid amount.\n");
    return 1;
  }

  monthly_interest_rate = 1 + interest_rate / (100 * 12);
  amount *= monthly_interest_rate;
  amount -= monthly_payment; 
  printf("Balance remaining after first payment: $%.2f\n", amount);

  amount *= monthly_interest_rate;
  amount -= monthly_payment; 
  printf("Balance remaining after second payment: $%.2f\n", amount);

  amount *= monthly_interest_rate;
  amount -= monthly_payment; 
  printf("Balance remaining after third payment: $%.2f\n", amount);

}
