// Name: overflow.c
// Purpose: Find out at what points type int will overflow
// Author: Georg
#include <stdio.h>

int main(void) {

  int runner = 1, semaphore = 0;

  printf("Initial setup:\nrunner = %d\nsemaphore = %d\n", runner, semaphore);
  while(runner > semaphore){
    runner++;
    semaphore++;
  }
  printf("runner apparently flipped at %d\n", semaphore);

  return 0;

}
