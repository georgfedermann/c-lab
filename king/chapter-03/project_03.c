// Name: project_03.c
// Purpose: Read ISBN and split it into elements.
// Author: Georg

#include <stdio.h>

int main(void) {
  int gs1_prefix = 0, group_id = 0, publisher_code = 0, item_number = 0,
      check_digit = 0;

  printf("This program reads an ISBN (13 digits) and splits it down into its "
         "elements\n");
  printf("Enter ISIN (e.g. 978-0-393-97950-3): ");
  scanf("%d-%d-%d-%d-%d", &gs1_prefix, &group_id, &publisher_code, &item_number,
        &check_digit);

  printf("GS1 prefix: %d\n", gs1_prefix);
  printf("Group identifier: %d\n", group_id);
  printf("Publisher code: %d\n", publisher_code);
  printf("Item number: %d\n", item_number);
  printf("Check digit: %d\n", check_digit);

  return 0;
}
