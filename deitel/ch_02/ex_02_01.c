// Name: ex_02_01.c
// Purpose: Demonstrate basic C program features.
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

// function main begins program execution
int main(void) {
  printf("Welcome to C!\n");

  // Check if this comment makes it past the pre-processor
  // Spoiler alert: no, it does not.
  // Much like EXIT_SUCCESS, which gets replaced by the value of the macro.
  return EXIT_SUCCESS;
}
