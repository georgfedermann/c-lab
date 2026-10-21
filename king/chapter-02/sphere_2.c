// Name: sphere_2.c
// Purpose: Calculate sphere volume for radius entered by user.
// Author: Georg

#define PI 3.14159265358979323846f
#include <stdio.h>

int main(void) {
  float radius;
  printf("This program calculates the volume of a sphere with a radius "
         "provided by the user.\n");
  printf("Enter radius: ");
  if (scanf("%f", &radius) != 1){
    printf("Invalid radius.\n");
    return 1;
  }

  printf("Volume for radius %.2f is %.2f\n", radius,
         4.0f * radius * radius * radius * PI / 3.0f);

  return 0;
}
