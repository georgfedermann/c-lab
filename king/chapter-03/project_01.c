// Name: project_01.c
// Purpose: Transforms US date to ISO-6801
// Author: Georg

#include <stdio.h>

int main(void){
  int day = 0, month = 0, year = 0;
  printf("Program accepts date in format mm/dd/yyyy and converts it to ISO-8601.\n");
  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);
  printf("ISO-8601: %04d-%02d-%02d\n\n", year, month, day);

  return 0;
}
