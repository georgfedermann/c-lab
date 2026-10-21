// Name: dimensional_weight_1.c
// Purpose: Demonstrate data input, processing, output
// Author: Georg

#include <stdio.h>
#define INCHES_PER_POUND 166

int main(void) {
  int length, width, height, volume, dim_weight;

  printf("This program calculates the dimensional weight of a package.\n");
  printf("Enter length: ");
  scanf("%d", &length);
  printf("Enter width: ");
  scanf("%d", &width);
  printf("Enter height: ");
  scanf("%d", &height);

  printf("Provided values: %dx%dx%d\n", length, width, height);

  volume = length * width * height;

  dim_weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

  printf("Calculated volume: %din³\n", volume);
  printf("Calculated dimensional weight: %dlbs\n", dim_weight);

  return 0;
}
