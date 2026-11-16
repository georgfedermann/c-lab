// Name: acme_checkbook_02.c
// Purpose: Recap on first 6 chapters
// Author: Georg

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long balance = 0;
    int command, ch;

    puts("*** ACME checkbook-balancing program ***");
    puts("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit");

    for (;;) {
        printf("Enter command: ");
        fflush(stdout);

        ch = getchar();
        if (ch == EOF)
            return EXIT_SUCCESS;

        command = ch - '0';
        int valid_command = ch >= '0' && ch <= '4';

        /* Consume the rest of the command line. */
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (ch != ' ' && ch != '\t')
                valid_command = 0;
        }

        if (!valid_command) {
            fprintf(stderr, "Invalid command. Use 0 through 4.\n");
            if (ch == EOF)
                return EXIT_FAILURE;
            continue;
        }

        switch (command) {
        case 0:
            balance = 0;
            puts("Balance cleared.");
            break;

        case 3:
            if (balance < 0)
                printf("Current balance: -$%lld.%02lld\n",
                       -(balance / 100), -(balance % 100));
            else
                printf("Current balance: $%lld.%02lld\n",
                       balance / 100, balance % 100);
            break;

        case 4:
            return EXIT_SUCCESS;

        case 1:
        case 2: {
            long long dollars = 0, fraction = 0, cents;
            int digits = 0, decimal_places = 0;
            int point_seen = 0, valid = 1;

            printf("Enter amount of %s (e.g. 12.34): ",
                   command == 1 ? "credit" : "debit");
            fflush(stdout);

            /* Parse decimal input without using float or double. */
            while ((ch = getchar()) != '\n' && ch != EOF) {
                if (ch >= '0' && ch <= '9') {
                    int digit = ch - '0';

                    if (!point_seen) {
                        if (dollars > (1000000000LL - digit) / 10)
                            valid = 0;
                        else
                            dollars = dollars * 10 + digit;
                        ++digits;
                    } else if (decimal_places < 2) {
                        fraction = fraction * 10 + digit;
                        ++decimal_places;
                    } else {
                        valid = 0;
                    }
                } else if (ch == '.' && !point_seen) {
                    point_seen = 1;
                } else {
                    valid = 0;
                }
            }

            if (ch == EOF) {
                fprintf(stderr, "Input ended during amount entry.\n");
                return EXIT_FAILURE;
            }

            if (digits == 0 || (point_seen && decimal_places == 0))
                valid = 0;

            if (!valid) {
                fprintf(stderr,
                        "Invalid amount; use 0 to 2 decimal places, "
                        "maximum $1,000,000,000.00.\n");
                break;
            }

            if (decimal_places == 1)
                fraction *= 10;

            cents = dollars * 100 + fraction;

            /* Protect the balance from signed integer overflow. */
            if ((command == 1 && balance > LLONG_MAX - cents) ||
                (command == 2 && balance < LLONG_MIN + cents)) {
                fprintf(stderr,
                        "Balance would overflow. Transaction rejected.\n");
                break;
            }

            if (command == 1)
                balance += cents;
            else
                balance -= cents;

            break;
        }
        }
    }
}

