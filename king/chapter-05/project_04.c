// Name: project_04.c
// Purpose: Lookup Beaufort Description based on wind speed in knots.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int wind_speed, rv;
  printf("Program asks for wind speed in knots and prints a description\n"
         "based on the Beaufort Scale.\n");

  printf("Enter wind speed in knots (>= 0): ");
  rv = scanf("%d", &wind_speed);

  if (rv != 1 || wind_speed < 0) {
    printf("Error: bad input - expected an integer greater or equal to 0.\n");
    return EXIT_FAILURE;
  }

  if (wind_speed < 1) {
    printf("Calm");
  } else if (wind_speed <= 3) {
    printf("Light air");
  } else if (wind_speed <= 27) {
    printf("Breeze");
  } else if (wind_speed <= 47) {
    printf("Gale");
  } else if (wind_speed <= 63) {
    printf("Storm");
  } else {
    printf("Hurricane");
  }

  printf("\n");

  return EXIT_SUCCESS;
}
