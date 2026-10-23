// Name: change.c
// Purpose: Calculate change with minimal amount of bills.
// Author: Georg

#include <stdio.h>

int main(void) {
  int n20 = 0, n10 = 0, n5 = 0, n1 = 0, amount, a;
  printf("This program calculates how to return change with minimum number of "
         "bills\n");

  printf("Please enter change amount: ");
  if (scanf("%d", &amount) != 1) {
    printf("Invalid amount.");
    return 1;
  }

  n20 = amount / 20;
  a = amount % 20;
  n10 = a / 10;
  a = a % 10;
  n5 = a / 5;
  a = a % 5;
  n1 = a;

  printf("Return $%d with %d 20$, %d 10$, %d 5$ and %d 1$ bills.\n", amount,
         n20, n10, n5, n1);

  return 0;
}
