// Name: add_numbers_kink.c
// Purpose: Demo program, appetizer for `do-while` statements
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n, sum = 0;

  printf("This program sums a series of integers.\n");
  printf("Enter integers (0 to terminate): ");
  fflush(stdout);

  scanf("%d", &n);
  while (n != 0){
    sum += n;
    scanf("%d", &n);
  }
  printf("The sum is: %d\n", sum);

  return EXIT_SUCCESS;
}
