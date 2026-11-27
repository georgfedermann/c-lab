// Name: project_04.c
// Purpose: commission calculator looping over deals
// Author: Georg

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PROMPT "Enter value of trade: "

int main(void) {
  double trade_value, commission;
  int key;
  int rv;
  bool input_succeeded;

  for (;;) {
    // Prompt trade value
    input_succeeded = false;
    do {
      printf(PROMPT);
      rv = scanf("%lf", &trade_value);
      if (rv == EOF) {
        return EXIT_SUCCESS;
      } else if (rv != 1 || trade_value < 0) {
        // Print error message
        fprintf(
            stderr,
            "\nError: bad input - expected nonnegative floating point number\n");
        // clear input line before prompoting again
        for (;;) {
          key = getchar();
          if (key == '\n') {
            break;
          } else if (key == EOF) {
            return EXIT_SUCCESS;
          }
        }
      } else if (rv == 1) {
        input_succeeded = true;
        // clear input line before prompoting again
        for (;;) {
          key = getchar();
          if (key == '\n') {
            break;
          } else if (key == EOF) {
            return EXIT_SUCCESS;
          }
        }
      }
    } while (!input_succeeded);
    // test exit condition
    if (trade_value == 0) {
      return EXIT_SUCCESS;
    }
    // Calculate commission
    if (trade_value < 2500)
      commission = 30 + 0.017 * trade_value;
    else if (trade_value < 6250)
      commission = 56 + 0.0066 * trade_value;
    else if (trade_value < 20000)
      commission = 76 + 0.0034 * trade_value;
    else if (trade_value < 50000)
      commission = 100 + 0.0022 * trade_value;
    else if (trade_value < 500000)
      commission = 155 + 0.0011 * trade_value;
    else
      commission = 255 + 0.0009 * trade_value;

    // Output result
    printf("\nCommission: $%.2f\n\n", commission);
  }
}
