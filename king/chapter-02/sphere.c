// Name: sphere.c
// Purpose: Calculate the volume of a sphere.
// Author: Georg

#include <math.h>
#include <stdio.h>

int main(void) {
  printf("The volume of a sphere with 10 meter radius is %.2f\n",
         4 * pow(10.0f, 3.0f) * M_PI / 3);

  return 0;
}
