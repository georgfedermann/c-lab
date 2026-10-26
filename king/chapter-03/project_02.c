// Name: project_02.c
// Purpose: Format product information
// Author: Georg

#include <stdio.h>

int main(void) {
  int item_number = 0;
  int purchase_day = 0, purchase_month = 0, purchase_year = 0;
  float unit_price = 0.0f;
  printf("Program reads product information and prints it formatted.\n");
  printf("Enter item number (###): ");
  scanf("%d", &item_number);
  printf("Enter unit price (#,##): ");
  scanf("%f", &unit_price);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &purchase_month, &purchase_day, &purchase_year);

  // printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  // printf("%d\t\t$%7.2f\t\t%d-%d-%d\n\n", item_number, unit_price,
  // purchase_year,
  //        purchase_month, purchase_day);

  printf("%-15s%-15s%-15s\n", "Item", "Unit", "Purchase");
  printf("%-15s%-15s%-15s\n", "", "Price", "Date");
  printf("%-15d$ %10.2f   %04d/%02d/%02d\n", item_number, unit_price,
         purchase_year, purchase_month, purchase_day);

  return 0;
}
