// Name: dimensional_weight.c
// Purpose: Simple calculations done in C
// Author: Georg

#include <stdio.h>

#define INCHES_PER_POUND 166

int main(void){
  int height = 8, length = 12, width = 10;
  int volume = height * length * width;
  int dim_weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

  printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume: %din³\n", volume);
  printf("Dimensional weight (lbs): %d\n", dim_weight);

  return 0;
}
