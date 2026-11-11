// Name: project_10.c
// Purpose: Convert percentage into grades
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int rv, numerical_grade;
  puts("This program asks for percentage and prints a grade.");

  printf("Enter numerical grade (0..100): ");
  rv = scanf("%d", &numerical_grade);

  printf("\n");
  fflush(stdout);
  if (rv != 1 || numerical_grade < 0 || numerical_grade > 100) {
    fprintf(
        stderr,
        "\nError: bad input - expected an integer between 0 and 100 inclusive\n");
    return EXIT_FAILURE;
  }

  switch (numerical_grade / 10) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    puts("F");
    break;
  case 6:
    puts("D");
    break;
  case 7:
    puts("C");
    break;
  case 8:
    puts("B");
    break;
  case 9:
  case 10:
    puts("A");
    break;
  }

  return EXIT_SUCCESS;
}
