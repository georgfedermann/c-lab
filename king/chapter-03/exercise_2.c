// Name: exercise_2.c
// Purpose: Practice printf conversion specifications.
// Author: Georg

#include <stdio.h>

int main(void){
  float x = 3.14159265f, y = 0.0000009979f, z = 215731.4215f;

  printf("%-8.1e\n%-8.1e\n%-8.1e\n", x, y, z);
  printf("\n%10.6e\n%10.6e\n%10.6e\n", x, y, z);
  printf("\n%8.3f\n%8.3f\n%8.3f\n", x, y, z);
  printf("\n%6.f\n%6.f\n%6.f\n", x, y, z);

  return 0;
}
