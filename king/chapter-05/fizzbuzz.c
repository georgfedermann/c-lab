// Name: fizzbuzz.c
// Purpose: Use switch statements for fizzbuzz
// Author: Georg

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int ceiling, rv, counter;
  printf("Fizzbuzz with switch!\n");

  printf("Enter ceiling ( 0 < ceiling <= INT_MAX): ");
  rv = scanf("%d", &ceiling);
  if (rv != 1 || ceiling < 1) {
    printf("Error: bad input - expected one integer number greater 0\n");
    return EXIT_FAILURE;
  }

  for (counter = 0; counter < ceiling;) {
    counter++;
    switch (counter % 15) {
    case 3:
    case 6:
    case 9:
    case 12:
      printf("fizz\n");
      break;
    case 5:
    case 10:
      printf("buzz\n");
      break;
    case 0:
      printf("fizzbuzz\n");
      break;
    default:
      printf("%d\n", counter);
      break;
    }
  }

  return EXIT_SUCCESS;
}
