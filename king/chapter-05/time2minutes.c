// time2minutes.c
// Accepts time in 24h format and returns minutes since midnight
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int input_hours, input_minutes, rv;

  rv = scanf("%d:%d", &input_hours, &input_minutes);
  if (rv != 2){
    fprintf(stderr, "Error: expected 24h format time");
    return EXIT_FAILURE;
  }
  printf("%d", input_hours * 60 + input_minutes);

  return EXIT_SUCCESS;
}
