// Name: project_09.c
// Purpose: Select the earlier date of 2.
// Author: Gideon

#include <stdio.h>
#include <stdlib.h>

#define DATE_FORMAT_ERROR_MSG "\nError: bad input - expected date in US format\n"
#define OUTPUT "%d/%d/%02d is earlier than %d/%d/%02d\n"

int main(void) {
  int y1, m1, d1, y2, m2, d2, rv;
  int earlier_date;
  printf("Enter first date (mm/dd/yy): ");
  fflush(stdout);
  rv = scanf("%d/%d/%d", &m1, &d1, &y1);
  if (rv != 3 || m1 < 1 || m1 > 12 || d1 < 1 || d1 > 31) {
    fprintf(stderr, DATE_FORMAT_ERROR_MSG);
    return EXIT_FAILURE;
  }

  printf("Enter second date (mm/dd/yy): ");
  fflush(stdout);
  rv = scanf("%d/%d/%d", &m2, &d2, &y2);
  if (rv != 3 || m2 < 1 || m2 > 12 || d2 < 1 || d2 > 31) {
    fprintf(stderr, DATE_FORMAT_ERROR_MSG);
    return EXIT_FAILURE;
  }
  puts("");

  if (y1 >= 69){
    y1 = 1900 + y1;
  } else {
    y1 = 2000 + y1;
  }

  if (y2 >= 69){
    y2 = 1900 + y2;
  } else {
    y2 = 2000 + y2;
  }

  if (y1 < y2) {
    earlier_date = 1;
  } else if (y1 > y2) {
    earlier_date = 2;
  } else if (m1 < m2) {
    earlier_date = 1;
  } else if (m1 > m2) {
    earlier_date = 2;
  } else if (d1 < d2) {
    earlier_date = 1;
  } else if (d1 > d2) {
    earlier_date = 2;
  } else {
    earlier_date = 0;
  }

  y1 %= 100;
  y2 %= 100;
  switch (earlier_date) {
  case 0:
    printf("Received same date twice: %d/%d/%02d\n", m1, d1, y1);
    break;
  case 1:
    printf(OUTPUT, m1, d1, y1, m2, d2, y2);
    break;
    case 2:
    printf(OUTPUT, m2, d2, y2, m1, d1, y1);
    break;
  }

  return EXIT_SUCCESS;
}
