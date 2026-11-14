// Name: sum_up_02.c
// Purpose: sum up 10 numbers, demo us of `continue` statement
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int sum = 0, summand, garbage;

  puts("This program adds up 10 non-zero summands.");
  printf("Enter ten non-zero integer summand: ");
  fflush(stdout);

  for (int counter = 0; counter < 10;) {
    if (scanf("%d", &summand) != 1) {
      printf("Error: bad input - expected an integer number <> 0.\n");
      printf("Discarding bad input ... ");
      fflush(stdout);
      for (;;){
        garbage = getchar();
        if (garbage == '\n'){
          break;
        } else if (garbage == EOF){
          puts("Error: bad input - reached EOF. Exiting program.");
          return EXIT_FAILURE;
        }
      }
      printf(" done. Continue data input: ");
      fflush(stdout);
      continue;
    } else if (summand == 0){
      continue;
    }
    sum += summand;
    counter++;
  }

  printf("Sum of entered non-zero integers: %d\n", sum);

  return EXIT_SUCCESS;
}
