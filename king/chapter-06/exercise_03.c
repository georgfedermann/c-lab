// Name: exercise_03.c
// Purpose:

#include <stdio.h>
#include <stdlib.h>

int main(void){

  // Expect 5 4 3 2
  for (int i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1){
    printf("%d ", i);
  }

  return EXIT_SUCCESS;
}
