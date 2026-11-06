// Name: project_02.c
// Purpose: Convert 24h time into 12h time
// Author: Georg

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int hours, minutes, rv;
  bool is_morning;

  printf("Reads a 24h time and converts it into a 12h time.\n");
  printf("Enter time in 24h format (HH:MM): ");

  rv = scanf("%d:%d", &hours, &minutes);

  if (rv != 2 || hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
    printf("Error: bad input - expected a time in 24h format\n");
    return EXIT_FAILURE;
  }

  is_morning = hours < 12;
  hours = hours % 12 == 0 ? 12 : hours % 12;

  printf("%2d:%02d %s\n", hours, minutes, is_morning ? "AM" : "PM");

  return EXIT_SUCCESS;
}
