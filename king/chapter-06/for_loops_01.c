// Name: for_loops_01.c
// Purpose: Compare for and counter based while
// Author: Georg

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;
  int n = 15;

  puts("for loop:\n========");
  for (i = 10; i > 0; i--) {
    printf("T minus %d and counting\n", i);
  }
  puts("equivalent while loop:\n=======================");
  i = 10;
  while (i > 0) {
    printf("T minus %d and counting\n", i);
    i--;
  }

  // Counting up from 0 to n - 1
  printf("Counting up from 0 to n - 1, where n is %d:\n", n);
  for (i = 0; i < n; i++) {
    if (i > 0) {
      printf(" - ");
    }
    printf("%d", i);
  }
  puts("");
  printf("Counting up from 1 to n, where n is %d:\n", n);
  for (i = 1; i <= n; i++) {
    if (i > 1) {
      printf(" - ");
    }
    printf("%d", i);
  }
  puts("");
  printf("Counting down from n - 1 to 0, where n is %d:\n", n);
  for (i = n - 1; i >= 0; i--) {
    if (i < n - 1) {
      printf(" - ");
    }
    printf("%d", i);
  }
  puts("");
  printf("Counting down from n - 1 to 0, try different approach\n");
  // This clearly is the more confusing appraoch, when reading the code
  for (i = n; i > 0; i--) {
    if (i < n) {
      printf(" - ");
    }
    printf("%d", i - 1);
  }
  puts("");
  printf("Counting down from n to 1, where n is %d:\n", n);
  for (i = n; i >= 1; i--) {
    if (i < n) {
      printf(" - ");
    }
    printf("%d", i);
  }
  puts("");
  printf("Value i before declaration inside for loop: %d\n", i);
  for (int i = 10; i == 10; i++) {
    printf("Version of i inside for loop: %d\n", i);
  }
  printf("Value of i after declaration inside for loop: %d\n", i);
  printf("Declaring `count` inside for loop:\n");
  for (int count = 10; 10 == count; count++) {
    printf("Value of count inside for loop: %d\n", count);
  }
  printf("Getting compiler error when referring to count outside declaring for "
         "loop.\n");

  printf("Comma Operator to initialize and increment\n");
  for (i = 5, n = 0, 4 < 5, 3 * 3 * 3; i > n && n >= 0; i--, n++, 3 < 4, "hello, world!"){
    printf("i: %d, n: %d\n", i, n);
  }

  puts("Counting from 1 to n again");
  for (i = 0; i++, i <=10;){
    if ( i > 1){
      printf(" - ");
    }
    printf("%d", i);
  }
  puts("");

  return EXIT_SUCCESS;
}
