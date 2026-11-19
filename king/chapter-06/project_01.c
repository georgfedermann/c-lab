// Name: project_01.c
// Purpose: Reads a sequence of numbers, terminated when the user enters 0.
//          Then the program emits the largest number entered by the user.
// Author: Georg

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double maximum, number;
  int rv, ch;
  // if has_maximum is true, maximum contains the largest qualifying number
  // processed so far.
  bool has_maximum = false;

  for (;;) {
    printf("Enter a number: ");
    fflush(stdout);

    rv = scanf("%lf", &number);

    if (rv == EOF) {
      break;
    } else if (rv == 0) {
      // clean up current line and try again
      ch = 0;
      while (ch != '\n' && ch != EOF) {
        ch = getchar();
      }
    } else if (rv == 1) {
      if (number <= 0) {
        break;
      } else if (!has_maximum || number > maximum) {
        has_maximum = true;
        maximum = number;
      }
    } else {
      // Something weird has happened? rv < 0 and not EOF or rv > 1?
      fprintf(stderr, "program could not recover\n");
      return EXIT_FAILURE;
    }
  }

  if (has_maximum) {
    printf("\nThe largest number entered was %lf\n", maximum);
  } else {
    puts("\nNo nonnegative numbers were entered.");
  }

  return EXIT_SUCCESS;
}
