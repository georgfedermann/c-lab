// Name: acme_checkbook.c
// Purpose: Track checkbook transactions
// Author: Georg

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_ERROR                                                            \
  "Error: bad input expected positive monetary amount in the format #.##"

int main(void) {
  int command;
  int balance_cents = 0;
  bool input_succeeded = false;
  puts("**** ACME checkbook-balancing program ****");
  puts("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");

  for (;;) {
    printf("Enter command: ");
    fflush(stdout);
    if (scanf("%d", &command) != 1 || command < 0 || command > 4) {
      continue;
    }
    switch (command) {
    case 0: {
      // Clear balance
      balance_cents = 0;
      puts("Balance reset to 0.00");
      break;
    }
    case 1:
    case 2: {
      int input_dollar = 0, input_cent = 0;
      input_succeeded = false;
      do {
        printf("Enter amount of %s: ", (command == 1 ? "credit" : "debit"));
        fflush(stdout);
        if (scanf("%d.%d", &input_dollar, &input_cent) < 1 ||
            input_dollar < 0) {
          puts(INPUT_ERROR);
          for (;;) {
            if (getchar() == '\n') {
              break;
            }
          }
          printf("Retry: ");
          fflush(stdout);
        } else {
          input_succeeded = true;
        }
      } while (!input_succeeded);
      if (command == 1) {
        balance_cents += input_dollar * 100 + input_cent;
      } else {
        balance_cents -= input_dollar * 100 + input_cent;
      }
      break;
    }
    case 3: {
      printf("Current balance: $%.2f\n", (balance_cents / 100.0));
      break;
    }
    case 4: {
      puts("Thank you for using ACME checkbook-balancing");
      goto exit;
    }
    }
  }
exit:
  return EXIT_SUCCESS;
}
