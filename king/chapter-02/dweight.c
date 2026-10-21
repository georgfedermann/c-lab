// Name: dweight.c
// Purpose: Exercise on writing C code
// Author: Georg

#include <stdio.h>
#define POUNDS_PER_INCH 166

int main(void) {
  int length = 12, width = 10, height = 8, volume = length * width * height;
  printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume: %din³\n", volume);
  printf("Dimensional weight: %dlbs\n", (volume + POUNDS_PER_INCH - 1) / POUNDS_PER_INCH);

  return 0;
}
