// Name: exercise_11.c
// Purpose: Explore switch statements
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int area_code, rv;
  printf("This program reads an area code and tries to look up the\n"
         "corresponding city name.\n");
  printf("Enter three digit area code: ");

  rv = scanf("%3d", &area_code);
  printf("Debug: area_code: %d, rv: %d\n", area_code, rv);

  if (rv != 1) {
    printf("Error: bad input - expected three digit area code\n");
    return EXIT_FAILURE;
  }

  switch (area_code) {
  case 229:
    printf("Albany");
    break;
  case 404:
  case 470:
  case 678:
  case 770:
    printf("Atlanta");
    break;
  case 478:
    printf("Macon");
    break;
  case 706:
  case 762:
    printf("Columbus");
    break;
  case 912:
    printf("Savannah");
    break;
  default:
    printf("Area code not recognized");
    break;
  }
  printf("\n");

  return EXIT_SUCCESS;
}
