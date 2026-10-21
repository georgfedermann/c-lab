// Name: c2f.c
// Purpose: Converts Celsius to Fahrenheit, to be used on the command line
// Author: Georg

#include <stdio.h>
#define FREEZING_POINT 32.0f
#define SCALE_FACTOR (9.0f / 5.0f)

int main(void) {
  float celsius, fahrenheit;
  scanf("%f", &celsius);
  fahrenheit = celsius * SCALE_FACTOR + FREEZING_POINT;

  printf("%.1f\n", fahrenheit);

  return 0;
}
