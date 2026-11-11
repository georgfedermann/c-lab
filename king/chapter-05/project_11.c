// Name: project_11.c
// Purpose: Spell out a given 2-digit number
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int number, rv;
  int d_tens, d_ones;

  // preamble
  puts("Converts a two digit number into English words");

  // Read input
  printf("Enter a two-digit number: ");
  fflush(stdout);
  rv = scanf("%d", &number);

  // Validate input
  if (rv != 1 || number < 10 || number > 99) {
    fprintf(stderr, "Error: bad input - expected a two digit integer number\n");
    return EXIT_FAILURE;
  }

  // Process Input
  printf("\nYou entered the number ");
  d_tens = number / 10;
  d_ones = number % 10;
  if (d_tens == 1) {
    switch (number) {
    case 10:
      printf("ten");
      break;
    case 11:
      printf("eleven");
      break;
    case 12:
      printf("twelve");
      break;
    case 13:
      printf("thirteen");
      break;
    case 14:
      printf("fourteen");
      break;
    case 15:
      printf("fifteen");
      break;
    case 16:
      printf("sixteen");
      break;
    case 17:
      printf("seventeen");
      break;
    case 18:
      printf("eighteen");
      break;
    case 19:
      printf("nineteen");
      break;
    }
  } else {
    switch (d_tens) {
    case 2:
      printf("twenty");
      break;
    case 3:
      printf("thirty");
      break;
    case 4:
      printf("forty");
      break;
    case 5:
      printf("fifty");
      break;
    case 6:
      printf("sixty");
      break;
    case 7:
      printf("seventy");
      break;
    case 8:
      printf("eighty");
      break;
    case 9:
      printf("ninety");
      break;
    }
    if (d_ones != 0){
      printf("-");
    }
    switch (d_ones) {
    case 1:
      printf("one");
      break;
    case 2:
      printf("two");
      break;
    case 3:
      printf("three");
      break;
    case 4:
      printf("four");
      break;
    case 5:
      printf("five");
      break;
    case 6:
      printf("six");
      break;
    case 7:
      printf("seven");
      break;
    case 8:
      printf("eight");
      break;
    case 9:
      printf("nine");
      break;
    }
  }
  puts(".");

  return EXIT_SUCCESS;
}
