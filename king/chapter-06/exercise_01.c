// Name: exercise_01.c

#include <stdio.h>
#include <stdlib.h>

int main(void){

  // Expected output:
  // 1 2 4 8 16 32 64 128
  int i = 1;
  while (i <= 128){
    printf("%d ", i);
    i *= 2;
  }

  return EXIT_SUCCESS;
}
