// Name: project_01.c
// Purpose: User enters date in format mm/dd/yyyy,
//          program corrects him to use iso-8601 formatted date
// Author: Georg

#include <stdio.h>

int main(void){
  int day = 0, month = 0, year = 0;

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);
  printf("ISO-8601: %04d-%02d-%02d\n\n", year, month, day);

  return 0;
}
