// Name: table_of_squares_02.c
// Purpose: Use for loop for square table
// Author: Georg

#include <stdlib.h>
#include <stdio.h>

int main(void){
  int n, rv, odd = 3, square = 1;
  puts("This program prints a table of squares.");
  printf("Enter number of entries in table: ");
  fflush(stdout);
  rv = scanf("%d", &n);
  if (rv != 1 || rv < 1){
    puts("Error: bad input - expeced integer number >= 1");
    return EXIT_FAILURE;
  }

  for (int i = 1; i <= n; odd += 2){
    printf("%10d%10d\n", i++, square);
    square += odd;
  }

  return EXIT_SUCCESS;
}
