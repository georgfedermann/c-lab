// Name: peeps_poops.c
// Purpose: A game of peeps poops
// Author: Georg

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int ceiling, rv, counter;
  printf("This program counts from 1 to n, replacing multiples of 3 with\n");
  printf("peeps, and multiples of 5 with poops.\n");

  printf("Enter ceiling (int > 0, int <= %d): ", INT_MAX);
  rv = scanf("%d", &ceiling);

  if (rv != 1 || ceiling < 1) {
    printf("Error: bad input - expected one integer number > 0\n");
    return EXIT_FAILURE;
  }
  for (counter = 0; counter < ceiling; ) {
    counter++;
    if (counter % 3 == 0 && counter % 5 == 0) {
      printf("peeps-poops\n");
    } else if (counter % 5 == 0) {
      printf("poops\n");
    } else if (counter % 3 == 0) {
      printf("peeps\n");
    } else {
      printf("%d\n", counter);
    }
  }

  return EXIT_SUCCESS;
}
