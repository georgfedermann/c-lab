// Name: pun2.c
// Purpose: Demo printf calls
// Author: Georg
#include <stdio.h>

void printer(void){
  printf("My ");       /* forgot to close this comment ...
  printf("cat ");
  printf("has ");      /* so the comment only ends here. */
  printf("fleas.");
}

int main(void) {
  printf("To C, or not to C: ");
  printf("that is the question.\n");

  printf("\n\nBrevity is the soul of wit.\n  --Shakespeare\n");

  printer();

  return 0;
}
