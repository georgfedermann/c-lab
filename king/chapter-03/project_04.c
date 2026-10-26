// Name: project_04.c
// Purpose: Read phone numbers and re-format then
// Author: Georg

#include <stdio.h>

int main(void){
  int block_1 = 0, block_2 = 0, block_3 = 0;
  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf(" ( %d ) %d - %d", &block_1, &block_2, &block_3);
  printf("You entered %d.%d.%d\n", block_1, block_2, block_3);

  return 0;
}
