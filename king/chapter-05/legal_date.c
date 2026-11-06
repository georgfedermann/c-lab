// Name: legal_date.c
// Purpose: Print a date in fancy way for legal documents.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int year, month, day, rv;
  printf("Reads a date and then prints it in a format for legal documents.\n");
  printf("Enter date in ISO-8601 like format (Y-M-D): ");

  rv = scanf("%d-%d-%d", &year, &month, &day);
  if (rv != 3 || month < 1 || month > 12 || day < 1 || day > 31) {
    printf("Error: bad input - expected ISO8601 date.");
    return EXIT_FAILURE;
  }

  printf("\nDated this ");
  switch (day) {
  case 1:
  case 21:
  case 31:
    printf("%dst", day);
    break;
  case 2:
  case 22:
    printf("%dnd", day);
    break;
  case 3:
  case 23:
    printf("%drd", day);
    break;
  default:
    printf("%dth", day);
    break;
  }
  printf(" day of ");

  switch (month) {
  case 1:
    printf("January");
    break;
  case 2:
    printf("February");
    break;
  case 3:
    printf("March");
    break;
  case 4:
    printf("April");
    break;
  case 5:
    printf("May");
    break;
  case 6:
    printf("June");
    break;
  case 7:
    printf("July");
    break;
  case 8:
    printf("August");
    break;
  case 9:
    printf("September");
    break;
  case 10:
    printf("October");
    break;
  case 11:
    printf("November");
    break;
  case 12:
    printf("December");
    break;
  }

  printf(", %d.\n", year);

  return EXIT_SUCCESS;
}
