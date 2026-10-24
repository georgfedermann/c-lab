// Name: exercise_4.c
// Purpose: Play the parser in scanf
// Author: Georg

#include <stdio.h>

int main(void){
  int i, j;
  float x, y;

  printf("Enter values for \"%%d%%f%%d\": ");
  scanf("%d%f%d", &i, &x, &j);
  printf("You've entered %d; %f; %d\n\n", i, x, j);
  // Enter:
  // 10.3 5 6
  // Expectation:
  // You've entered 10; 0.300000; 5

  // Enter:
  // 12.3 45.6 789
  // Expectation:
  // You've entered 12; 0.300000; 45

  printf("Now enter values for \"%%f%%d%%f\": ");
  scanf("%f%d%f", &x, &i, &y);
  printf("You've entered %f; %d; %f\n\n", x, i, y);
  // Enter:
  // 12.3 45.6 789
  // Expectation:
  // You've entered 12.300000; 45; 0.600000

  return 0;
}
