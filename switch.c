// Name: switch.c
// Purpose: Philosphize about switch statements and cascaded if statements.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int rv, grade;
  printf("This program uses cascaded if statements and switch statements\n");
  printf("to print evaluations based on grades from 0 to 4.\n");
  printf("Enter grade (0, 1, 2, 3, 4): ");
  rv = scanf("%1d", &grade);
  if (rv != 1 || grade < 0 || grade > 4) {
    printf("Error: bad input - expected a one digit grade between 0 and 4 "
           "inclusive\n");
    return EXIT_FAILURE;
  }

  if (grade == 4)
    printf("Excellent");
  else if (grade == 3)
    printf("Good");
  else if (grade == 2)
    printf("Average");
  else if (grade == 1)
    printf("Poor");
  else if (grade == 0)
    printf("Failing");
  else
    printf("Illegal grade");

  printf("\n\nNow, the same thing but with a `switch` statement:\n");

  switch (grade) {
  case 4:
    printf("Excellent");
    break;
  case 3:
    printf("Good");
    break;
  case 2:
    printf("Average");
    break;
  case 1:
    printf("Poor");
    break;
  case 0:
      printf("Failing");
    break;
  default:
      printf("Illegal grade");
    break;
  }

  return EXIT_SUCCESS;
}
