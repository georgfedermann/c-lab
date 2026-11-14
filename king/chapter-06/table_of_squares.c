// Name: table_of_squares.c
// Purpose: Introduce while loop; print table of squares
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int rv, n, i = 1;
  puts("Program reads an integer and prints a table of squares for i in N, i < n");
  printf("Enter number of entries in table: ");
  fflush(stdout);
  rv = scanf("%d", &n);
  if (rv != 1 || n < 1){
    fprintf(stderr, "Error: bad input - expected an int >= 1\n");
    return EXIT_FAILURE;
  }

  while (i <= n){
    printf("%10d%10d\n", i, i * i);
    i += 1;
  }

  return EXIT_SUCCESS;
}
