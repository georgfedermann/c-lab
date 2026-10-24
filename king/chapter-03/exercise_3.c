// Name: exercise_3.c
// Purpose: Understand nuances in scanf conversion specifications
// Author: Georg

#include <stdio.h>

int main(void) {
  int a = 0, b = 0, c = 0;
  float x = 0.0f, y = 0.0f;

  printf("Enter value for %%d: ");
  scanf("%d", &a);
  printf("You've entered: %d\n", a);

  printf("Enter value for \" %%d\": ");
  scanf(" %d", &a);
  printf("You've entered %d\n", a);

  printf("Enter values for \"%%d-%%d-%%d\": ");
  scanf("%d-%d-%d", &a, &b, &c);
  printf("You've entered %d-%d-%d\n\n", a, b, c);

  printf("Enter values for \"%%d -%%d -%%d\": ");
  scanf("%d -%d -%d", &a, &b, &c);
  printf("You've entered %d-%d-%d\n\n", a, b, c);

  printf("Enter values for \"%%f\": ");
  scanf("%f", &x);
  printf("You've entered %f\n\n", x);

  printf("Enter values for \"%%f \": ");
  scanf("%f ", &x);
  printf("You've entered %f\n\n", x);

  int ch = getchar();
  printf("What do you mean by '%c'?\n", ch);

  printf("Enter values for \"%%f,%%f\": ");
  scanf("%f,%f", &x, &y);
  printf("You've entered %f,%f\n\n", x, y);

  printf("Enter values for \"%%f, %%f\": ");
  scanf("%f, %f", &x, &y);
  printf("You've entered %f,%f\n\n", x, y);

  return 0;
}
